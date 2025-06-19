#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "lexer.h"

typedef struct s_redir
{
	char			*filename;
	int				type;
	int heredoc_fd;  // heredoc pipe read end
	int				quoted_delim;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char	**argv;
	t_redir	*redirs;
	int		pipe_next;
}	t_cmd;

int		parse_input(char *input, t_shell *shell);
void	clear_cmd_list(t_list *cmds);

#endif