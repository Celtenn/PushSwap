/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:56:06 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/21 13:41:48 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
}	t_stack;

void	optimize_a_check(t_stack *stack, int numbers, int len);
int		check_sorted_size(t_node *stack, int order, int size);
void	error_detected_all(t_stack *stack, t_node *temp);
int		optimize_b_check(t_stack *stack, int numbers);
int		check_sorted(t_node *stack, int order);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str, t_node *head);
void	error_detected(t_node *head);
int		is_all_whitespace(char *str);
void	check_doubles(t_node *head);
int		list_size(t_node *head);
int		after_sign(char *str);
int		ft_strlen(char *str);

void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);

int		quicksort_stack_b(t_stack *stack, int len, int count_r);
int		quicksort_stack_a(t_stack *stack, int len, int count_r);
void	quicksort_three_stack_a(t_stack *stack, int len);
int		ft_push(t_stack *stack, int len, int push);
int		sort_three_b(t_stack *stack, int len);
int		sort(t_stack *stack, int size);
void	three_numbers(t_stack *three);
void	temporary_sort(t_node *head);

int		add_node(t_node **head, int value);
void	ft_split_free(char	**str);
void	free_list(t_node *head);

#endif
