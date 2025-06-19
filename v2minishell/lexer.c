#include "lexer.h"
#include "parser.h"
#include "minishell.h"
#include <ctype.h>

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
		return (NULL);
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
		return (-1);
	*out = strndup(&input[start], i - start);
	return i + 1;
}

static char *collect_word_segments(const char *input, int *i, t_shell *shell, int in_heredoc)
{
	char *result = calloc(1, 1);
	if (!result)
		return NULL;

	while (input[*i] && !isspace(input[*i]) && !is_special(input[*i]))
	{
		char *segment = NULL;

		// === ÇİFT TIRNAKLI ===
		if (input[*i] == '"')
		{
			int start = *i;
			int new_i = handle_quotes(input, *i, &segment);
			if (new_i == -1)
				return free(result), NULL;

			if (in_heredoc)
			{
				// tırnaklarıyla birlikte geri al
				char *raw = strndup(&input[start], new_i - start);
				if (!raw)
					return free(result), NULL;
				char *tmp = realloc(result, strlen(result) + strlen(raw) + 1);
				if (!tmp) return free(result), free(raw), NULL;
				result = tmp;
				strcat(result, raw);
				free(raw);
			}
			else
			{
				char *expanded = expand_variables(segment, shell);
				if (!expanded)
					return free(result), free(segment), NULL;
				char *tmp = realloc(result, strlen(result) + strlen(expanded) + 1);
				if (!tmp) return free(result), free(segment), free(expanded), NULL;
				result = tmp;
				strcat(result, expanded);
				free(expanded);
			}
			free(segment);
			*i = new_i;
		}

		// === TEK TIRNAKLI ===
		else if (input[*i] == '\'')
		{
			int start = *i;
			int new_i = handle_quotes(input, *i, &segment);
			if (new_i == -1)
				return free(result), NULL;

			if (in_heredoc)
			{
				char *raw = strndup(&input[start], new_i - start);
				if (!raw)
					return free(result), NULL;
				char *tmp = realloc(result, strlen(result) + strlen(raw) + 1);
				if (!tmp) return free(result), free(raw), NULL;
				result = tmp;
				strcat(result, raw);
				free(raw);
			}
			else
			{
				char *tmp = realloc(result, strlen(result) + strlen(segment) + 1);
				if (!tmp) return free(result), free(segment), NULL;
				result = tmp;
				strcat(result, segment);
			}
			free(segment);
			*i = new_i;
		}

		// === TIRNAKSIZ PARÇA ===
		else
		{
			int start = *i;
			while (input[*i] && !isspace(input[*i]) && !is_special(input[*i]) && input[*i] != '"' && input[*i] != '\'')
				(*i)++;
			if (in_heredoc)
			{
				char *raw = strndup(&input[start], *i - start);
				if (!raw)
					return free(result), NULL;
				char *tmp = realloc(result, strlen(result) + strlen(raw) + 1);
				if (!tmp) return free(result), free(raw), NULL;
				result = tmp;
				strcat(result, raw);
				free(raw);
			}
			else
			{
				segment = strndup(&input[start], *i - start);
				if (!segment)
					return free(result), NULL;
				char *expanded = expand_variables(segment, shell);
				free(segment);
				if (!expanded)
					return free(result), NULL;
				char *tmp = realloc(result, strlen(result) + strlen(expanded) + 1);
				if (!tmp) return free(result), free(expanded), NULL;
				result = tmp;
				strcat(result, expanded);
				free(expanded);
			}
		}
	}
	return result;
}

t_token *tokenize(char *input, t_shell *shell)
{
	int		i = 0;
	int	in_heredoc = 0;
	t_token	*tokens = NULL;

	while (input[i])
	{
		while (input[i] && isspace(input[i]))
			i++;
		if (!input[i])
			break;

		if (input[i] == '|')
			add_token(&tokens, "|", T_PIPE), i++;
		else if (input[i] == '>' && input[i + 1] == '>')
			add_token(&tokens, ">>", T_APPEND), i += 2;
		else if (input[i] == '<' && input[i + 1] == '<')
		{
			add_token(&tokens, "<<", T_HEREDOC);
			i += 2;
			in_heredoc = 1;
		}
		else if (input[i] == '>')
			add_token(&tokens, ">", T_REDIR_OUT), i++;
		else if (input[i] == '<')
			add_token(&tokens, "<", T_REDIR_IN), i++;
		else
		{
			char *word = collect_word_segments(input, &i, shell, in_heredoc);
			in_heredoc = 0;

			if (!word)
			{
				free_tokens(tokens);
				return (NULL);  // burda tüm tokenlar silinip NULL dönülür
			}
			if (*word == '\0')
			{
				free(word);
				continue;
			}
			add_token(&tokens, word, T_WORD);
			free(word);
		}
	}
	if (!tokens)
		return (NULL);
	return (tokens);
}
