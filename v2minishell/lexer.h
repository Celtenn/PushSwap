#ifndef LEXER_H
# define LEXER_H

#include "parser.h"
#include "minishell.h"
typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_APPEND,
	T_HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

t_token	*tokenize(char *input, t_shell *shell);
void	free_tokens(t_token *tokens);

#endif