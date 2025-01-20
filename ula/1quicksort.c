#include "push_swap.h"

int	pivot_of_numbers(int *pivot, t_node *head, int size)
{
	t_node	*temporaire_stack;
	t_node	*current;
	int		i;

	i = 0;
	temporaire_stack = NULL;
	if (head == NULL)
		return (0);
	current = head;
	while (current != NULL && i < size)
	{
		add_node(&temporaire_stack, current->value);
		current = current->next;
		i++;
	}
	temporary_sort(temporaire_stack);
	i = 0;
	current = temporaire_stack;
	while (i++ < size / 2)
		current = current->next;
	*pivot = current->value;
	free_list(temporaire_stack);
	return (1);
}

int	quicksort_stack_a(t_stack *stack, int len, int count_r)
{
	int	pivot;
	int	numbers = 0;

	if (check_sorted(stack->a, 0) == 1)
		return (1);
	if ((check_sorted_lo(stack->a, 1, len) == 1))
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
	numbers = len;
	if (len <= 3)
	{
		quicksort_three_stack_a(stack, len);
		return (1);
	}
	if (!pivot_of_numbers(&pivot, stack->a, len))
		return (0);
	while (len != (numbers / 2 + numbers % 2))
	{
		if (stack->a->value < pivot && len--)
			push_b(stack);
		else if (++count_r)
			rotate_a(stack);
	}
	while (numbers / 2 + numbers % 2 != stack->size_a && count_r--)
		reverse_rotate_a(stack);
	return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
}

int	quicksort_stack_b(t_stack *stack, int len, int count_r)
{
	int	pivot;
	int	numbers = 0;

	if (check_sorted(stack->b, 1) == 1)
		while (len--)
			push_a(stack);
	if (check_sorted(stack->b, 0) == 1)
	{
		while (numbers < (stack->size_b))
		{
			reverse_rotate_b(stack);
			push_a(stack);
		}
	}
	if (len <= 3)
	{
		sort_three_b(stack, len);
		return (1);
	}
	numbers = len;
	if (!pivot_of_numbers(&pivot, stack->b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stack->b->value >= pivot && len--)
			push_a(stack);
		else if (++count_r)
			rotate_b(stack);
	}
	while (numbers / 2 != stack->size_b && count_r--)
		reverse_rotate_b(stack);
	return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
}