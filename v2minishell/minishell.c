#include "minishell.h"
#include "parser.h"
#include <stdio.h>

int g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_shell	shell;

	(void)argc;
	(void)argv;

	init_shell(&shell, envp);
	setup_signals();
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("exit\n");
			break;
		}
		if (*input)
			add_history(input);

		if (!parse_input(input, &shell))
			fprintf(stderr, "Parse error!\n");
		else
		{
			execute_commands(shell.cmds, &shell);
		}		
		free_shell(&shell);
		free(input);
	}
	return 0;
}