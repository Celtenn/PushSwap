#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int g_exit_status;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_shell
{
	char	**env;
	t_list	*cmds;
	int		stdin_backup;
	int		stdout_backup;
}	t_shell;

void	init_shell(t_shell *shell, char **envp);
void	free_shell(t_shell *shell);
void	free_str_array(char **arr);
void execute_commands(t_list *cmds, t_shell *shell);
char *expand_variables(const char *input, t_shell *shell);

int builtin_cd(char **argv, t_shell *shell);
int	builtin_exit(char **argv, t_shell *shell);
int builtin_echo(char **argv);
int is_builtin(char *cmd);
int exec_builtin(char **argv, t_shell *shell);

int builtin_pwd(char **argv);
int builtin_env(char **argv, char **env);
int builtin_export(char **argv, t_shell *shell);
int builtin_unset(char **argv, t_shell *shell);

char *get_var_value(const char *name, t_shell *shell);

void	setup_signals(void);

#endif