#include "parser.h"

static int	count_args(t_token *start)
{
	int count = 0;
	while (start && start->type != T_PIPE)
	{
		if (start->type == T_WORD)
		{
			count++;
			start = start->next;
		}
		else if (start->type == T_REDIR_IN || start->type == T_REDIR_OUT
			|| start->type == T_APPEND || start->type == T_HEREDOC)
			{
				start = start->next;
				if (start)
					start = start->next;
			}
		else
			start = start->next;
	}
	return count;
}

static t_redir	*add_redir(t_redir **head, char *filename, int type)
{
	t_redir *new = malloc(sizeof(t_redir));
	if (!new)
		return NULL;
	new->filename = strdup(filename);
	new->type = type;
	new->next = NULL;

	if (!*head)
		*head = new;
	else {
		t_redir *tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return new;
}

static t_cmd	*parse_single_command(t_token **current)
{
	t_cmd	*cmd;
	t_token *tok = *current;
	int		i = 0;
	int		arg_count = count_args(tok);

	cmd = malloc(sizeof(t_cmd));
	cmd->argv = malloc(sizeof(char *) * (arg_count + 1));
	cmd->redirs = NULL;
	cmd->pipe_next = 0;

	while (tok && tok->type != T_PIPE)
	{
		if (tok->type == T_WORD)
			cmd->argv[i++] = strdup(tok->value);
		else if (tok->type >= T_REDIR_IN && tok->type <= T_HEREDOC)
		{
			t_token *next = tok->next;
			if (!next || next->type != T_WORD)
			{
				free(cmd->argv);
				free(cmd);
				return NULL;
			}
			add_redir(&cmd->redirs, next->value, tok->type);
			tok = tok->next;
		}
		tok = tok->next;
	}
	cmd->argv[i] = NULL;
	if (tok && tok->type == T_PIPE)
	{
		cmd->pipe_next = 1;
		tok = tok->next;
	}
	*current = tok;
	return cmd;
}

static t_list	*ft_lstnew(void *content)
{
	t_list	*node = malloc(sizeof(t_list));
	if (!node) return NULL;
	node->content = content;
	node->next = NULL;
	return node;
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp = *lst;
	if (!tmp)
		*lst = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_list	*build_command_list(t_token *tokens)
{
	t_list	*cmd_list = NULL;
	t_cmd	*cmd;
	t_token *cur = tokens;

	while (cur)
	{
		cmd = parse_single_command(&cur);
		if (!cmd)
			return NULL;
		ft_lstadd_back(&cmd_list, ft_lstnew(cmd));
	}
	return cmd_list;
}

void	clear_redirs(t_redir *r)
{
	t_redir *tmp;
	while (r)
	{
		tmp = r;
		if (r->type == T_HEREDOC)
			close(r->heredoc_fd);
		r = r->next;
		free(tmp->filename);
		free(tmp);
	}
}

void	clear_cmd_list(t_list *cmds)
{
	t_list *tmp;
	while (cmds)
	{
		tmp = cmds;
		t_cmd *cmd = (t_cmd *)cmds->content;
		cmds = cmds->next;
		for (int i = 0; cmd->argv[i]; i++)
			free(cmd->argv[i]);
		free(cmd->argv);
		clear_redirs(cmd->redirs);
		free(cmd);
		free(tmp);
	}
}

int is_all_spaces(const char *s)
{
	while (*s)
	{
		if (!(*s == ' ' || *s == '\t' || *s == '\n'
			|| *s == '\v' || *s == '\f' || *s == '\r'))
			return 0;
		s++;
	}
	return 1;
}

int	parse_input(char *input, t_shell *shell)
{
	t_token	*tokens;

	tokens = tokenize(input, shell);
	if (!tokens)
	{
		if (shell->cmds)
			clear_cmd_list(shell->cmds);
		shell->cmds = NULL;
		if (input && is_all_spaces(input))
			return (1);
		return (0);
	}

	shell->cmds = build_command_list(tokens);
	free_tokens(tokens);
	return (shell->cmds != NULL);
}
