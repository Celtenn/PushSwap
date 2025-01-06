#include "push_swap.h"

void reverse_rotate_a(t_stack *stack) 
{
    t_node *last, *second_last;

    if (!stack->a || !stack->a->next) // Liste boşsa veya tek elemanlıysa işlem yapma.
        return;

    last = stack->a;
    second_last = NULL;

    // Liste sonuna git ve son düğüm ile sondan bir önceki düğümü bul.
    while (last->next) 
    {
        second_last = last;
        last = last->next;
    }

    // Son düğümü başa taşı.
    last->next = stack->a;
    stack->a = last;
    second_last->next = NULL;

    printf("rra\n");
}

void reverse_rotate_b(t_stack *stack) 
{
    t_node *last, *second_last;

    if (!stack->b || !stack->b->next) // Liste boşsa veya tek elemanlıysa işlem yapma.
        return;

    last = stack->b;
    second_last = NULL;

    // Liste sonuna git ve son düğüm ile sondan bir önceki düğümü bul.
    while (last->next) 
    {
        second_last = last;
        last = last->next;
    }

    // Son düğümü başa taşı.
    last->next = stack->b;
    stack->b = last;
    second_last->next = NULL;

    printf("rrb\n");
}

void reverse_rotate_r(t_stack *stack) 
{
    // Hem A hem de B yığınları için reverse rotate işlemini gerçekleştir.
    if (stack->a && stack->a->next)
        reverse_rotate_a(stack); // Bonus ile çağır, çünkü ayrı bir printf yazılmayacak.

    if (stack->b && stack->b->next)
        reverse_rotate_b(stack); // Bonus ile çağır, çünkü ayrı bir printf yazılmayacak.

    printf("rrr\n");
}
