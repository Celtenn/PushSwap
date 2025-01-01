#include <stdio.h>
#include <stdlib.h>
#include "deneme.h"

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

void ra(t_stack **a)
{
    t_stack *temp;
    t_stack *last;

    if (*a == NULL || (*a)->next == NULL)
        return;

    temp = *a;
    *a = (*a)->next;

    last = *a;
    while (last->next != NULL)
	{
        last = last->next;
	}
    last->next = temp;
    temp->next = NULL;
}

void	rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;
	if (*b == NULL || (*b)->next == NULL)
		return;

	temp = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
