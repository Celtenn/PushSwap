/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:56:06 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/20 17:59:22 by idkahram         ###   ########.fr       */
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

// functions
int		check_sorted_size(t_node *stack, int order, int size);
void	optimize_a_check(t_stack *stack, int numbers, int len);
int		optimize_b_check(t_stack *stack, int numbers);
int		stack_a_check(t_stack *stack, int len);
int		stack_b_check(t_stack *stack, int len);
void	error_detected(t_node *head, int check, char **str);
int		ft_atoi(char *str, t_node *head, int check, char **av);
int		check_sorted(t_node *stack, int order);
void	check_doubles(t_node *head, int check, char **str);
char	**ft_split(char const *s, char c);
int		list_size(t_node *head);

// Stack Manipulation Functions
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_r(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_r(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack);

// Sorting Functions
void	temporary_sort(t_node *head);
void	three_numbers(t_stack *three);
void	three_numbers_stack_a(t_stack *three, int a, int b, int c);
int		sort(t_stack *stack, int size);
int		ft_push(t_stack *stack, int len, int push);
void	quicksort_three_stack_a(t_stack *stack, int len);
int		sort_three_b(t_stack *stack, int len);
int		pivot_of_numbers(int *pivot, t_node *stack, int size);
int		quicksort_stack_a(t_stack *stack, int len, int count_r);
int		quicksort_stack_b(t_stack *stack, int len, int count_r);

// Utility Functions
void	add_node(t_node **head, int value);
void	free_list(t_node *head);
void	ft_split_free(char	**str);

#endif
