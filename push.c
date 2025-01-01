#include <stdio.h>
#include <stdlib.h>
#include "deneme.h"

void pa(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*b == NULL)
        return;

    temp = *b;
    *b = (*b)->next;

    temp->next = *a;
    *a = temp;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (*a == NULL)
		return;

	temp = *a;
	*a = (*a)->next;

	temp->next = *b;
	*b = temp;
}
