#include <stdio.h>
#include <stdlib.h>
#include "deneme.h"

void *push(t_stack *stack, int value) 
{
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = stack;
}

int pop(t_stack **stack) 
{
    if (!(*stack))
        return (-1);
    int value = (*stack)->value;
    t_stack *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return (value);
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
int stack_size(t_stack *stack) 
{
    int count = 0;
    while (stack) 
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b) 
{
    int ra_count = 0, pb_count = 0, pa_count = 0;
	int size = stack_size(*stack_a);

    while (size > 0) 
    {
        pb(stack_a, stack_b);
        pb_count++;
    }

    while (*stack_b) 
    {
        int min_value = pop(stack_b);
        t_stack **current = stack_a;
        while (*current && (*current)->value < min_value) 
        {
            current = &((*current)->next);
        }
        t_stack *new_node = malloc(sizeof(t_stack));
        new_node->value = min_value;
        new_node->next = *current;
        *current = new_node;
        ra_count++;
    }
    printf("\nToplam aksiyonlar: ra=%d, pb=%d, toplam=%d\n", ra_count, pb_count, ra_count + pb_count);
}

int main() 
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    int numbers[] = {73, 28, 94, 18, 53, 63, 40, 35, 2, 75, 46, 83, 90, 7, 54, 86, 15, 69, 32, 44,
        99, 6, 88, 51, 41, 78, 23, 61, 4, 22, 95, 11, 9, 84, 67, 71, 37, 8, 29, 97,
        17, 52, 19, 55, 12, 33, 38, 10, 76, 59, 96, 80, 21, 72, 34, 3, 68, 56, 42, 24,
        13, 1, 25, 26, 20, 30, 81, 45, 5, 87, 36, 48, 39, 85, 50, 60, 77, 74, 16, 31,
        98, 43, 62, 89, 27, 14, 49, 64, 70, 66, 57, 1000000, 79, 47, 92, 91, 65, 100, 82, 93, 58, 0, -100, -3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int i = size - 1;
    while (i >= 0) 
    {
        stack_a = push(stack_a, numbers[i]);
        i--;
    }
    printf("Başlangic stack_a: ");
    print_stack(stack_a);
    radix_sort(&stack_a, &stack_b);
    printf("\nSirali stack_a: ");
    print_stack(stack_a);
    return 0;
}	