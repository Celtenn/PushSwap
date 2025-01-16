/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:01:57 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/16 01:01:59 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_three_stack_a(t_stack *stack, int len)
{
	if (len == 2)
	{
		if (stack->a->value > stack->a->next->value)
			swap_a(stack);
	}
	else if (len == 3)
	{
		if (stack->a->value > stack->a->next->value)
			swap_a(stack);
		if (stack->a->next->value > stack->a->next->next->value)
		{
			rotate_a(stack);
			swap_a(stack);
			reverse_rotate_a(stack);
		}
		if (stack->a->value > stack->a->next->value)
			swap_a(stack);
	}
}

int	sort_three_b(t_stack *stack, int len)
{
	if (len == 1)
		push_a(stack);
	else if (len == 2)
	{
		if (stack->b->value < stack->b->next->value)
			swap_b(stack);
		while (len--)
			push_a(stack);
	}
	else if (len == 3)
	{
		while (len > 0)
		{
			if (len == 1 && stack->a->value > stack->a->next->value)
				swap_a(stack);
			else if (len == 1
				|| (len >= 2 && stack->b->value > stack->b->next->value)
				|| (len == 3 && stack->b->value > stack->b->next->next->value))
				len = ft_push(stack, len, 1);
			else
				swap_b(stack);
		}
	}
	return (0);
}
