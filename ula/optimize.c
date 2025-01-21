/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:53:05 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/21 15:38:05 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	after_sign(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	is_all_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	error_detected_all(t_stack *stack, t_node *temp)
{
	free_list(temp);
	free_list(stack->a);
	free_list(stack->b);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_detected(t_node *head, int check, char **av)
{
	if (check == 1)
		ft_split_free(av);
	free_list(head);
	write(2, "Error\n", 6);
	exit(1);
}
