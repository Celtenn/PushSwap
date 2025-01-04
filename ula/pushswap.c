#include "push_swap.h"

t_node *create_node(int value) 
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

void free_list(t_node *list) 
{
    t_node *tmp;
    while (list) 
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void append_node(t_node **list, int value) 
{
    t_node *new_node = create_node(value);
    if (!new_node)
        return;
    if (!*list) 
    {
        *list = new_node;
    } 
    else 
    {
        t_node *temp = *list;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

int list_size(t_node *list) 
{
    int size = 0;
    while (list) 
    {
        size++;
        list = list->next;
    }
    return size;
}

void push_swap(char **av) 
{
    t_stack stack = {NULL, NULL};
    int     i = -1;


    while (av[++i]) 
    {
        int value = push_swap_atoi(av[i], NULL);
        append_node(&stack.a, value);
    }

    check_doubles(stack.a);
    printf("eski a : ");
    print_stack(stack.a);
    printf("eski b : ");
    print_stack(stack.b);

    int size = list_size(stack.a);
    sort(&stack, size);

    printf("a : ");
    print_stack(stack.a);
    printf("b : ");
    print_stack(stack.b);
    free_list(stack.a);
    free_list(stack.b);
}
void print_stack(t_node *stack) 
{
    while (stack) 
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main(int ac, char **av) 
{
    if (ac > 1) 
    {
        av++;
        if (ac == 2)
            av = ft_split(*av, ' ');
        push_swap(av);
        return (0);
    }
    return (0);
}
