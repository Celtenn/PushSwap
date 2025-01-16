/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:46:15 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/16 04:54:18 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack->a || !stack->a->next)
		return ;
	first = stack->a;
	second = stack->a->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack->b || !stack->b->next)
		return ;
	first = stack->b;
	second = stack->b->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sb\n", 3);
}

void	swap_s(t_stack *stack)
{
	if ((!stack->a || !stack->a->next) && (!stack->b || !stack->b->next))
		return ;
	swap_a(stack);
	swap_b(stack);
	write(1, "ss\n", 3);
}
