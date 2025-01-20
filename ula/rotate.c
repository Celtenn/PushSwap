/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:50:11 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/21 01:14:20 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_node	*temp;
	t_node	*last;

	if (!stack->a || !stack->a->next)
		return ;
	temp = stack->a;
	stack->a = stack->a->next;
	temp->next = NULL;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	t_node	*temp;
	t_node	*last;

	if (!stack->b || !stack->b->next)
		return ;
	temp = stack->b;
	stack->b = stack->b->next;
	temp->next = NULL;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "rb\n", 3);
}
