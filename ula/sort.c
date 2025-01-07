#include "push_swap.h"

void	temporary_sort(t_node *head)
{
	t_node	*current;
	t_node	*next_node;
	int		temp;

	if (head == NULL && head->next == NULL)
		return ;
	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		while (next_node != NULL)
		{
			if (current->value > next_node->value)
			{
				temp = current->value;
				current->value = next_node->value;
				next_node->value = temp;
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
}

void	three_numbers(t_stack *three)
{
	int	a;
	int	b;
	int	c;

	a = three->a->value;
	b = three->a->next->value;
	c = three->a->next->next->value;
	three_numbers_case_stack_a(three, a, b, c);
}

void	three_numbers_case_stack_a(t_stack *three, int a, int b, int c)
{
	if (!three || !three->a || !three->a->next || !three->a->next->next)
		return ;
	if (a > b && a < c && b < c)
		swap_a(three);
	else if (a > b && a > c && b > c)
	{
		swap_a(three);
		reverse_rotate_a(three);
	}
	else if (a > b && a > c && b < c)
		rotate_a(three);
	else if (a < b && a < c && b > c)
	{
		swap_a(three);
		rotate_a(three);
	}
	else if (a < b && a > c && b > c)
		reverse_rotate_a(three);
}

int	sort(t_stack *stack, int size)
{
	if (!stack || !stack->a)
		return (0);
	stack->size_a = list_size(stack->a);
	stack->size_b = 0;
	if (check_sorted(stack->a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack);
		else if (size == 3)
			three_numbers(stack);
		else
			quicksort_stack_a(stack, size, 0);
	}
	return (0);
}

int	ft_push(t_stack *stack, int len, int push)
{
	if (!stack || len <= 0)
		return (len);
	if (push == 0)
		push_b(stack);
	else
		push_a(stack);
	len--;
	return (len);
}
