#include "push_swap.h"

void quicksort_three_stack_a_and_b(t_stack *stack, int len)
{
    if (len == 2)
    {
        if (stack->a->value > stack->a->next->value)
            swap_a(stack, 0);
    }
    else if (len == 3)
    {
        // Sadece 3 eleman varsa minimal sıralama işlemi
        if (stack->a->value > stack->a->next->value)
            swap_a(stack, 0);
        if (stack->a->next->value > stack->a->next->next->value)
        {
            rotate_a(stack, 0);
            swap_a(stack, 0);
            reverse_rotate_a(stack, 0);
        }
        if (stack->a->value > stack->a->next->value)
            swap_a(stack, 0);
    }
}

int sort_three_b(t_stack *stack, int len) 
{
    if (len == 1)
        push_a(stack, 0); 
    else if (len == 2) 
    {
        if (stack->b->value < stack->b->next->value)
            swap_b(stack, 0);
        while (len--)
            push_a(stack, 0);
    } 
    else if (len == 3) 
    {
        while (len || !(stack->a->value < stack->a->next->value
                        && stack->a->next->value < stack->a->next->next->value)) {
            if (len == 1 && stack->a->value > stack->a->next->value)
                swap_a(stack, 0);
            else if (len == 1 || (len >= 2 && stack->b->value > stack->b->next->value)
                       || (len == 3 && stack->b->value > stack->b->next->next->value)) {
                len = ft_push(stack, len, 1);
            } 
            else 
                swap_b(stack, 0);
        }
    }
    return 0;
}

int mediane_of_numbers(int *pivot, t_node *head, int size)
{
    t_node *temporaire_stack = NULL;
    t_node *current;
    int i;

    i = 0;
    if (head == NULL)
        return 0;
    current = head;
    while (current != NULL && i < size)
    {
        append_node(&temporaire_stack, current->value);
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

int hrotate(t_stack *stack, int *len, int *count_r, int pivot, int is_stack_a)
{
    if ((is_stack_a && stack->a->value < pivot) ||
        (!is_stack_a && stack->b->value >= pivot)) 
        {
        if (is_stack_a)
            push_b(stack, 0);
        else
            push_a(stack, 0);
        (*len)--;
    } 
    else 
    {
        if (is_stack_a)
            rotate_a(stack, 0);
        else 
            rotate_b(stack, 0);
        (*count_r)++;
    }
    return (0);
}

void rrotations(t_stack *stack, int count_r, int is_stack_a, int target_size) 
{
    while (target_size != (is_stack_a ? stack->size_a : stack->size_b) &&
           count_r--) {
        if (is_stack_a) 
            reverse_rotate_a(stack, 0);
        else 
            reverse_rotate_b(stack, 0);
    }
}

int quicksort_stack(t_stack *stack, int len, int count_r, int is_stack_a) 
{
    int pivot;
    int numbers;

    numbers = len;
    if ((is_stack_a && check_sorted(stack->a, 0) == 1) ||
        (!is_stack_a && check_sorted(stack->b, 1) == 1)) 
        {
            if (!is_stack_a)
                while (len--)
                    push_a(stack, 0);
            return 1;
        }
    if (len <= 3) 
    {
        if (is_stack_a) 
            quicksort_three_stack_a_and_b(stack, len);
        else
            sort_three_b(stack, len);
        return 1;
    }
    if (!mediane_of_numbers(&pivot, is_stack_a ? stack->a : stack->b, len))
        return 0;
    while (len != (is_stack_a ? (numbers / 2 + numbers % 2) : (numbers / 2)))
        hrotate(stack, &len, &count_r, pivot, is_stack_a);
    rrotations(stack, count_r, is_stack_a,
                                is_stack_a ? (numbers / 2 + numbers % 2)
                                           : (numbers / 2));
    return (quicksort_stack(stack, numbers / 2 + numbers % 2, 0, 1) &&
            quicksort_stack(stack, numbers / 2, 0, 0));
}
