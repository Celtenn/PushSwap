/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:52:59 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/21 01:14:13 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack->a || !stack->a->next)
		return ;
	last = stack->a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack->a;
	stack->a = last;
	second_last->next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack->b || !stack->b->next)
		return ;
	last = stack->b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack->b;
	stack->b = last;
	second_last->next = NULL;
	write(1, "rrb\n", 4);
}
