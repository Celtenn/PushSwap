#include "lexer.h"
#include "parser.h"
#include "minishell.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

void	free_tokens(t_token *tokens)
{
	t_token *tmp;
	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
}

static int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static t_token	*add_token(t_token **head, char *val, t_token_type type)
{
	t_token *new = malloc(sizeof(t_token));
	if (!new)
		return NULL;
	new->value = strdup(val);
	new->type = type;
	new->next = NULL;

	if (!*head)
		*head = new;
	else {
		t_token *tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return new;
}

static int	handle_quotes(const char *input, int i, char **out)
{
	char quote = input[i++];
	int start = i;
	while (input[i] && input[i] != quote)
		i++;
	if (input[i] != quote)
		return -1;
	*out = strndup(&input[start], i - start);
	return i + 1;
}

t_token	*tokenize(char *input, t_shell *shell)
{
	int		i = 0;
	t_token	*tokens = NULL;
	char	*word;

	while (input[i])
	{
		while (isspace(input[i]))
			i++;
		if (!input[i])
			break ;

		if (input[i] == '"') // ÇİFT TIRNAK: expand edilir
		{
			int new_i = handle_quotes(input, i, &word);
			if (new_i == -1)
				return (free_tokens(tokens), NULL);

			char *expanded = expand_variables(word, shell);  // ✅ genişlet
			if (!expanded || *expanded == '\0')
			{
				free(word);
				free(expanded);
				i = new_i;
				continue;
			}
			add_token(&tokens, expanded, T_WORD);
			free(word);
			free(expanded);
			i = new_i;
		}
		else if (input[i] == '\'') // TEK TIRNAK: olduğu gibi al
		{
			int new_i = handle_quotes(input, i, &word);
			if (new_i == -1)
				return (free_tokens(tokens), NULL);
			add_token(&tokens, word, T_WORD);  // ❌ expand edilmez
			free(word);
			i = new_i;
		}
		else if (input[i] == '|')
			add_token(&tokens, "|", T_PIPE), i++;
		else if (input[i] == '>' && input[i + 1] == '>')
			add_token(&tokens, ">>", T_APPEND), i += 2;
		else if (input[i] == '<' && input[i + 1] == '<')
			add_token(&tokens, "<<", T_HEREDOC), i += 2;
		else if (input[i] == '>')
			add_token(&tokens, ">", T_REDIR_OUT), i++;
		else if (input[i] == '<')
			add_token(&tokens, "<", T_REDIR_IN), i++;
		else
		{
			int	start = i;
			while (input[i] && !isspace(input[i]) && !is_special(input[i]))
				i++;
			word = strndup(&input[start], i - start);
			char *expanded = expand_variables(word, shell);
			if (!expanded || *expanded == '\0')
			{
				free(word);
				free(expanded);
				continue;  // boş değişken varsa token ekleme
			}
			add_token(&tokens, expanded, T_WORD);
			free(word);
			free(expanded);
		}
	}
	return tokens;
}

