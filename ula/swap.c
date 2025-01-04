#include "push_swap.h"

void swap_a(t_stack *stack, int bonus) 
{
    t_node *first, *second;

    if (!stack->a || !stack->a->next) // Liste boşsa veya tek elemanlıysa işlem yapma.
        return;

    first = stack->a;             // İlk düğüm.
    second = stack->a->next;      // İkinci düğüm.

    // Değerleri değiştir.
    int temp = first->value;
    first->value = second->value;
    second->value = temp;

    if (!bonus)
        printf("sa\n");
}

void swap_b(t_stack *stack, int bonus) 
{
    t_node *first, *second;

    if (!stack->b || !stack->b->next) // Liste boşsa veya tek elemanlıysa işlem yapma.
        return;

    first = stack->b;             // İlk düğüm.
    second = stack->b->next;      // İkinci düğüm.

    // Değerleri değiştir.
    int temp = first->value;
    first->value = second->value;
    second->value = temp;

    if (!bonus)
        printf("sb\n");
}

void swap_s(t_stack *stack, int bonus) 
{
    if ((!stack->a || !stack->a->next) && (!stack->b || !stack->b->next)) // Her iki liste de boş veya tek elemanlıysa işlem yapma.
        return;

    swap_a(stack, 1);             // A yığını için değişim işlemini gerçekleştir.
    swap_b(stack, 1);             // B yığını için değişim işlemini gerçekleştir.

    if (!bonus)
        printf("ss\n");
}
