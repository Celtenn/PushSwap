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

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

t_stack *new_node(int value)
{
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

int main()
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    a = new_node(5);
    a->next = new_node(2);
    a->next->next = new_node(9);

    b = new_node(3);
    b->next = new_node(1);

    printf("Before rrr:\n");
    printf("a stack: ");
    print_stack(a);
    printf("b stack: ");
    print_stack(b);

    rrr(&a, &b);

    printf("\nAfter rrr:\n");
    printf("a stack: ");
    print_stack(a);
    printf("b stack: ");
    print_stack(b);
}