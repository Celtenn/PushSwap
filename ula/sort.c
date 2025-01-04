#include "push_swap.h"

void temporary_sort(t_node *head)
{
    t_node *current;
    t_node *next_node;
    int temp;

    if (head == NULL)
        return;

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


void three_numbers_case_stack_a(t_stack *three) 
{
    if (!three || !three->a || !three->a->next || !three->a->next->next)
        return;

    int a = three->a->value;
    int b = three->a->next->value;
    int c = three->a->next->next->value;

    if (a > b && a < c && b < c)
        swap_a(three, 0);
    if (a > b && a > c && b > c) 
    {
        swap_a(three, 0);
        reverse_rotate_a(three, 0);
    }
    if (a > b && a > c && b < c)
        rotate_a(three, 0);
    if (a < b && a < c && b > c) 
    {
        swap_a(three, 0);
        rotate_a(three, 0);
    }
    if (a < b && a > c && b > c)
        reverse_rotate_a(three, 0);
}

int sort(t_stack *stack, int size) 
{
    if (!stack || !stack->a)
        return 0;

    if (check_sorted(stack->a, 0) == 0) 
    {
        if (size == 2)
            swap_a(stack, 0);
        else if (size == 3)
            three_numbers_case_stack_a(stack);
        else
            quicksort_stack_a(stack, size, 0);
    }
    return 0;
}



int ft_push(t_stack *stack, int len, int push) 
{
    if (!stack || len <= 0)
        return len;

    if (push == 0)
        push_b(stack, 0);
    else
        push_a(stack, 0);

    len--;
    return len;
}
