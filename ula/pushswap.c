/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:01:50 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/20 14:47:44 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *list)
{
	t_node	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	add_node(t_node **list, int value)
{
	t_node	*newnode;
	t_node	*tmp;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return ;
	newnode->value = value;
	newnode->next = NULL;
	if (*list == NULL)
	{
		*list = newnode;
	}
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
}

int	list_size(t_node *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

void	push_swap(char **av, int check)
{
	t_stack	stack;
	int		value;
	int		i;

	i = -1;
	stack.a = NULL;
	stack.b = NULL;
	while (av[++i])
	{
		value = ft_atoi(av[i], stack.a, check, av);
		add_node(&stack.a, value);
	}
	check_doubles(stack.a, check, av);
	value = list_size(stack.a);
	sort(&stack, value);
	i = 0;
	if (check == 1)
	{
		ft_split_free(av);
	}
	free_list(stack.a);
	free_list(stack.b);
}

int	main(int ac, char **av)
{
	int	check;

	check = 0;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			av = ft_split(*av, ' ');
			check = 1;
		}
		push_swap(av, check);
	}
	return (0);
}
