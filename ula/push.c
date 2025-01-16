/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:42:53 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/16 04:43:43 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack)
{
	t_node	*temp;

	if (stack->a)
	{
		temp = stack->a;
		stack->a = stack->a->next;
		temp->next = stack->b;
		stack->b = temp;
		stack->size_a--;
		stack->size_b++;
		write(1, "pb\n", 3);
	}
}

void	push_a(t_stack *stack)
{
	t_node	*temp;

	if (stack->b)
	{
		temp = stack->b;
		stack->b = stack->b->next;
		temp->next = stack->a;
		stack->a = temp;
		stack->size_b--;
		stack->size_a++;
		write(1, "pa\n", 3);
	}
}
