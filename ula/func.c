/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:01:39 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/21 09:26:06 by idkahram         ###   ########.fr       */
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

void	ft_split_free(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_atoi(char *str, t_node *head)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_detected(head);
		number = (str[i] - '0') + (number * 10);
		i++;
		if ((number > 2147483648 && sign == -1)
			|| (number > 2147483647 && sign == 1))
			error_detected(head);
	}
	return (number * sign);
}

int	check_sorted(t_node *stack, int order)
{
	t_node	*current;

	current = stack;
	if (current == NULL || current->next == NULL)
		return (1);
	if (order == 0)
	{
		while (current->next != NULL)
		{
			if (current->value > current->next->value)
				return (0);
			current = current->next;
		}
	}
	else if (order == 1)
	{
		while (current->next != NULL)
		{
			if (current->value < current->next->value)
				return (0);
			current = current->next;
		}
	}
	return (1);
}

void	check_doubles(t_node *head)
{
	t_node	*current;
	t_node	*checker;

	current = head;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				error_detected(head);
			checker = checker->next;
		}
		current = current->next;
	}
}
