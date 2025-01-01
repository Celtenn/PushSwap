#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

void	sa(t_stack **head)
{
	t_stack *one;
	t_stack *two;
	if (*head && (*head)->next)
	{
		one = *head;
		two = (*head)->next;
		one->next = two->next;
		two->next = one;
		*head = two;
	}
}

void	sb(t_stack **head)
{
	t_stack *one;
	t_stack *two;
	if (*head && (*head)->next)
	{
		one = *head;
		two = (*head)->next;
		one->next = two->next;
		two->next = one;
		*head = two;
	}
}

void	ss(t_stack **a, t_stack **b)
{	
	sa(a);
	sb(b);
}
