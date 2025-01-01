#include <stdio.h>
#include <stdlib.h>

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

    printf("Before rr:\n");
    printf("a stack: ");
    print_stack(a);
    printf("b stack: ");
    print_stack(b);

    rr(&a, &b);

    printf("\nAfter rr:\n");
    printf("a stack: ");
    print_stack(a);
    printf("b stack: ");
    print_stack(b);
}