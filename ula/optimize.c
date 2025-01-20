/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:53:05 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/20 17:53:07 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_size(t_node *stack, int order, int size)
{
	t_node	*current;

	current = stack;
	if (current == NULL || current->next == NULL)
		return (1);
	if (order == 0)
	{
		while (current->next != NULL && size--)
		{
			if (current->value > current->next->value)
				return (0);
			current = current->next;
		}
	}
	else if (order == 1)
	{
		while (current->next != NULL && size--)
		{
			if (current->value < current->next->value)
				return (0);
			current = current->next;
		}
	}
	return (1);
}

void	optimize_a_check(t_stack *stack, int numbers, int len)
{
	if ((check_sorted_size(stack->a, 1, len) == 1))
	{
		while (len > numbers)
		{
			push_b(stack);
			numbers++;
		}
		while (numbers > 0)
		{
			rotate_b(stack);
			numbers--;
		}
		while (numbers < len)
		{
			reverse_rotate_b(stack);
			push_a(stack);
			numbers++;
		}
	}
}

int	optimize_b_check(t_stack *stack, int numbers)
{
	if (check_sorted(stack->b, 0) == 1)
	{
		while (numbers < (stack->size_b))
		{
			reverse_rotate_b(stack);
			push_a(stack);
		}
	}
	if (!stack->b)
		return (1);
	return (0);
}