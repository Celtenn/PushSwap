#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

void	rra(t_stack **a)
{
    t_stack *temp;
    t_stack *first;

    if (*a == NULL || (*a)->next == NULL)
        return;

	temp = *a;
    while (temp->next != NULL)
	{
        temp = temp->next;
	}
    first = temp;

	temp = *a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	first->next = *a;
	*a = first;
}

void	rrb(t_stack **b)
{
    t_stack *temp;
    t_stack *first;

    if (*b == NULL || (*b)->next == NULL)
        return;

	temp = *b;
    while (temp->next != NULL)
	{
        temp = temp->next;
	}
    first = temp;

	temp = *b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	first->next = *b;
	*b = first;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
