/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:01:57 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/21 00:34:22 by idkahram         ###   ########.fr       */
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
		if (stack->size_a == 3)
		{
			three_numbers(stack);
			return ;
		}	
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
