/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:01:50 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/21 15:39:23 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_node **list, int value)
{
	t_node	*newnode;
	t_node	*tmp;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (0);
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
	return (1);
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

void	helper_func(t_stack *stack, int check, char **av)
{
	int	value;

	check_doubles(stack->a, check, av);
	if (check == 1)
		ft_split_free(av);
	value = list_size(stack->a);
	sort(stack, value);
	free_list(stack->a);
	free_list(stack->b);
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
		if (ft_strlen(av[i]) == 0 || is_all_whitespace(av[i])
			|| after_sign(av[i]))
		{
			error_detected(stack.a, check, av);
		}
		value = ft_atoi(av[i], stack.a, check, av);
		if (!add_node(&stack.a, value))
		{
			if (check == 1)
				ft_split_free(av);
			error_detected(stack.a, check, av);
		}
	}
	helper_func(&stack, check, av);
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
			if ((ft_strlen(av[0]) > 0) && is_all_whitespace(av[0]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			av = ft_split(*av, ' ');
			if (av == NULL)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			check = 1;
		}
		push_swap(av, check);
	}
	return (0);
}
