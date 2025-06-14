#include "minishell.h"
#include "parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>  // open()
#include <unistd.h> // dup2(), close()
#include <readline/readline.h>


static char *find_executable(char *cmd, t_shell *shell)
{
	if (strchr(cmd, '/'))
		return strdup(cmd); // mutlak veya ./ bağıl yol

	char *path = get_var_value("PATH", shell);  // ✅ Doğru kaynaktan oku
	if (!path || !*path)
	{
		free(path);  // get_var_value malloc ile dönüyor, temizle
		return NULL;
	}

	char *paths = strdup(path);
	free(path);
	if (!paths)
		return NULL;

	char *token = strtok(paths, ":");
	while (token)
	{
		char *full = malloc(strlen(token) + strlen(cmd) + 2);
		if (!full)
		{
			free(paths);
			return NULL;
		}
		sprintf(full, "%s/%s", token, cmd);
		if (access(full, X_OK) == 0)
		{
			free(paths);
			return full;
		}
		free(full);
		token = strtok(NULL, ":");
	}
	free(paths);
	return NULL;
}


// Yardımcı: heredoc içeriğini pipe ile ver
// Sadece fonksiyon içinde tanımlı jump buffer
int create_heredoc_pipe(const char *delimiter, t_shell *shell)
{
	int pipefd[2];
	if (pipe(pipefd) < 0)
		return -1;

	pid_t pid = fork();
	if (pid == -1)
		return -1;

	if (pid == 0) // CHILD → heredoc okuyucu
	{
		signal(SIGINT, SIG_DFL); // Ctrl-C → normal öldürsün

		close(pipefd[0]); // sadece yaz
		while (1)
		{
			char *line = readline("> ");
			if (!line || strcmp(line, delimiter) == 0)
			{
				free(line);
				break;
			}

			// quote kontrolü yapıyorsan expand etme
			char *expanded = expand_variables(line, shell);
			write(pipefd[1], expanded, strlen(expanded));
			write(pipefd[1], "\n", 1);
			free(line);
			free(expanded);
		}
		close(pipefd[1]);
		exit(0);
	}

	// PARENT
	int status;
	waitpid(pid, &status, 0);

	close(pipefd[1]); // sadece oku

	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(pipefd[0]);
		g_exit_status = 130;
		return -1;
	}
	return pipefd[0];  // pipe read end
}


int prepare_heredocs(t_cmd *cmd, t_shell *shell)
{
	t_redir *r = cmd->redirs;

	while (r)
	{
		if (r->type == T_HEREDOC)
		{
			r->heredoc_fd = create_heredoc_pipe(r->filename, shell);
			if (r->heredoc_fd < 0)
				return -1; // heredoc iptal edildi
		}
		r = r->next;
	}
	return 0;
}
// apply_redirections fonksiyonu: T_HEREDOC dahil
static void apply_redirections(t_redir *redir)
{
	while (redir)
	{
		int fd;

		if (redir->type == T_REDIR_IN)
			fd = open(redir->filename, O_RDONLY);
		else if (redir->type == T_REDIR_OUT)
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (redir->type == T_APPEND)
			fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (redir->type == T_HEREDOC)
			fd = redir->heredoc_fd;
		else
			fd = -1;

		if (fd < 0)
		{
			perror(redir->filename);
			exit(1);
		}

		if (redir->type == T_REDIR_IN || redir->type == T_HEREDOC)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);

		redir = redir->next;
	}
}


static void exec_command(t_cmd *cmd, t_shell *shell)
{
	if (!cmd->argv || !cmd->argv[0] || cmd->argv[0][0] == '\0')
        exit(0);
	apply_redirections(cmd->redirs);  // <<< Buraya entegre ettik

	char *path = find_executable(cmd->argv[0], shell);
	if (!path)
	{
		fprintf(stderr, "Command not found: %s\n", cmd->argv[0]);
		exit(127);
	}
	execve(path, cmd->argv, shell->env);
	perror("execve failed");
	exit(1);
}


void execute_commands(t_list *cmds, t_shell *shell)
{
	int		pipefd[2];
	int		prev_read = -1;
	pid_t	pid;
	t_cmd	*cmd;

	while (cmds)
	{
		cmd = (t_cmd *)cmds->content;
		if (cmd->pipe_next)
			pipe(pipefd);

		if (is_builtin(cmd->argv[0]) && !cmd->pipe_next)
		{
			apply_redirections(cmd->redirs);
			exec_builtin(cmd->argv, shell);  // 🔧 shell artık parametre olarak veriliyor
			return;
		}
		if (prepare_heredocs(cmd, shell) < 0)
		{
			perror("heredoc");
			return;
		}
		pid = fork();
		if (pid == 0) // child
		{
			signal(SIGINT, SIG_DFL);    // Ctrl-C varsayılan (örn: cat durur)
			signal(SIGQUIT, SIG_DFL);   // Ctrl-\ varsayılan (örn: cat "Quit" yazar)

			if (prev_read != -1)
			{
				dup2(prev_read, STDIN_FILENO);
				close(prev_read);
			}
			if (cmd->pipe_next)
			{
				close(pipefd[0]);
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
			}
			apply_redirections(cmd->redirs);  // redirection child’ta da uygulanmalı
			if (is_builtin(cmd->argv[0]))
				exec_builtin(cmd->argv, shell);
			else
				exec_command(cmd, shell);

			exit(0);  // <- unutma, child çıkmalı
		}
		else if (pid < 0)
		{
			perror("fork failed");
			return;
		}

		if (prev_read != -1)
			close(prev_read);
		if (cmd->pipe_next)
		{
			close(pipefd[1]);
			prev_read = pipefd[0];
		}
		cmds = cmds->next;
	}

	int status;
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
	}
}


/*int status;
while (wait(&status) > 0)
{
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
}
*/