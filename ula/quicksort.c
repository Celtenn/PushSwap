#include "push_swap.h"

void quicksort_three_stack_a_and_b(t_stack *stack, int len) {
    if (len == 3 && list_size(stack->a) == 3) {
        three_numbers_case_stack_a(stack);
    } 
    else if (len == 2) 
    {
        if (stack->a->value > stack->a->next->value)
            swap_a(stack, 0);
    } 
    else if (len == 3) 
    {
        while (len != 3 || !(stack->a->value < stack->a->next->value
                             && stack->a->next->value < stack->a->next->next->value)) {
            if (len == 3 && stack->a->value > stack->a->next->value && stack->a->next->next) {
                swap_a(stack, 0);
            } 
            else if (len == 3 && !(stack->a->next->next->value > stack->a->value
                                     && stack->a->next->next->value > stack->a->next->value)) {
                len = ft_push(stack, len, 0);
            } 
            else if (stack->a->value > stack->a->next->value) 
            {
                swap_a(stack, 0);
            } 
            else if (len++) 
            {
                push_a(stack, 0);
            }
        }
    }
}

int sort_three_b(t_stack *stack, int len) {
    if (len == 1) 
    {
        push_a(stack, 0);
    } else if (len == 2) 
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
            if (len == 1 && stack->a->value > stack->a->next->value) {
                swap_a(stack, 0);
            } 
            else if (len == 1 || (len >= 2 && stack->b->value > stack->b->next->value)
                       || (len == 3 && stack->b->value > stack->b->next->next->value)) {
                len = ft_push(stack, len, 1);
            } 
            else 
            {
                swap_b(stack, 0);
            }
        }
    }
    return 0;
}

int mediane_of_numbers(int *pivot, t_node *head, int size)
{
    t_node *temporaire_stack;
    t_node *current;
    int i;
    i = 0;

    if (head == NULL)
        return 0;

    temporaire_stack = NULL;

    current = head;
    while (current != NULL && i < size)
    {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node)
            return 0;
        new_node->value = current->value;
        new_node->next = temporaire_stack;
        temporaire_stack = new_node;
        current = current->next;
        i++;
    }

    temporary_sort(temporaire_stack);

    i = 0;
    current = temporaire_stack;
    while (i < size / 2)
    {
        current = current->next;
        i++;
    }

    *pivot = current->value;

    while (temporaire_stack != NULL)
    {
        t_node *next = temporaire_stack->next;
        free(temporaire_stack);
        temporaire_stack = next;
    }
    return 1;
}

int quicksort_stack_a(t_stack *stack, int len, int count_r) {
    int pivot;
    int numbers;

    if (check_sorted(stack->a, 0) == 1) {
        return 1;
    }

    numbers = len;
    if (len <= 3) {
        quicksort_three_stack_a_and_b(stack, len);
        return 1;
    }

    if (!mediane_of_numbers(&pivot, stack->a, len))
        return 0;
    printf("PİVOT = %d\n", pivot);
    printf("A: ");
    print_stack(stack->a);
    printf("B: ");
    print_stack(stack->b);

    while (len != (numbers / 2 + numbers % 2)) 
    {
        if (stack->a->value < pivot) 
        {
            push_b(stack, 0);
            len--;
        } 
        else
        {
            rotate_a(stack, 0);
            count_r++;
        }
    }
    printf("A: ");
    print_stack(stack->a);
    printf("B: ");
    print_stack(stack->b);

    while (numbers / 2 + numbers % 2 != stack->size_a && count_r--) {
        reverse_rotate_a(stack, 0);
    }
    printf("A: ");
    print_stack(stack->a);
    printf("B: ");
    print_stack(stack->b);

    return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
            && quicksort_stack_b(stack, numbers / 2, 0));
}

int quicksort_stack_b(t_stack *stack, int len, int count_r) {
    int pivot;
    int numbers;

    if (check_sorted(stack->b, 1) == 1) {
        while (len--) {
            push_a(stack, 0);
        }
    }

    if (len <= 3) {
        sort_three_b(stack, len);
        return 1;
    }

    numbers = len;
    if (!mediane_of_numbers(&pivot, stack->b, len)) {
        return 0;
    }
    printf("PİVOT B = %d\n", pivot);
    printf("A: ");
    print_stack(stack->a);
    printf("B: ");
    print_stack(stack->b);

    while (len != numbers / 2) {
        if (stack->b->value >= pivot && len--) {
            push_a(stack, 0);
        } else if (++count_r) {
            rotate_b(stack, 0);
        }
    }
    printf("A: ");
    print_stack(stack->a);
    printf("B: ");
    print_stack(stack->b);

    while (numbers / 2 != stack->size_b && count_r--) {
        reverse_rotate_b(stack, 0);
    }
    printf("A: ");
    print_stack(stack->a);
    printf("B: ");
    print_stack(stack->b);

    return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
            && quicksort_stack_b(stack, numbers / 2, 0));
}
