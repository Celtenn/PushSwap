#include "minishell.h"
#include "parser.h"

int g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_shell	shell;

	(void)argv;
	if (argc != 1)
	{
		write(2, "please do not enter arguments\n", 30);
		exit(0);
	}
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
		if (*input != '\0')
		{
			if (!parse_input(input, &shell))
				fprintf(stderr, "Parse error!\n");
			else
				execute_commands(shell.cmds, &shell);
		}		
		free_shell(&shell);
		free(input);
	}
	free_str_array(shell.env);
	return (0);
}