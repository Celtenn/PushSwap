#include "push_swap.h"

void swap_a(t_stack *stack) 
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

    printf("sa\n");
}

void swap_b(t_stack *stack) 
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

    printf("sb\n");
}

void swap_s(t_stack *stack) 
{
    if ((!stack->a || !stack->a->next) && (!stack->b || !stack->b->next)) // Her iki liste de boş veya tek elemanlıysa işlem yapma.
        return;

    swap_a(stack);             // A yığını için değişim işlemini gerçekleştir.
    swap_b(stack);             // B yığını için değişim işlemini gerçekleştir.

    printf("ss\n");
}
