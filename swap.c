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

    printf("Before ss:\n");
    printf("a stack: ");
    print_stack(a);
    printf("b stack: ");
    print_stack(b);

    ss(&a, &b);

    printf("\nAfter ss:\n");
    printf("a stack: ");
    print_stack(a);
    printf("b stack: ");
    print_stack(b);
}
