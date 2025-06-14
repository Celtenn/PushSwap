#include "minishell.h"
#include "parser.h"

void	init_shell(t_shell *shell, char **envp)
{
	int i = 0;
	while (envp[i])
		i++;
	shell->env = malloc(sizeof(char *) * (i + 1));
	for (i = 0; envp[i]; i++)
		shell->env[i] = strdup(envp[i]);
	shell->env[i] = NULL;
	shell->cmds = NULL;
	shell->stdin_backup = dup(STDIN_FILENO);
	shell->stdout_backup = dup(STDOUT_FILENO);
}

/*void free_shell(t_shell *shell)
{
	if (shell->cmds)
		clear_cmd_list(shell->cmds);
	shell->cmds = NULL;

	// shell->env = NULL; // BUNU SİL
	// free_str_array(shell->env); // BUNU SİL

	dup2(shell->stdin_backup, STDIN_FILENO);
	dup2(shell->stdout_backup, STDOUT_FILENO);
	close(shell->stdin_backup);
	close(shell->stdout_backup);
}*/

void	free_shell(t_shell *shell)
{
	if (shell->cmds)
		clear_cmd_list(shell->cmds);
	shell->cmds = NULL;

	dup2(shell->stdin_backup, STDIN_FILENO);
	dup2(shell->stdout_backup, STDOUT_FILENO);
}

void	free_str_array(char **arr)
{
	if (!arr) return;
	int i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
