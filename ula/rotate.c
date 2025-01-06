#include "push_swap.h"

void rotate_a(t_stack *stack) 
{
    t_node *temp, *last;

    if (!stack->a || !stack->a->next) // Liste boşsa veya tek elemanlıysa işlem yapma.
        return;

    temp = stack->a;                // İlk düğümü geçici olarak sakla.
    stack->a = stack->a->next;       // Liste başını güncelle.
    temp->next = NULL;             // Eski ilk düğümün `next` işaretçisini sıfırla.

    last = stack->a;                // Listeyi son düğüme kadar ilerlet.
    while (last->next)
        last = last->next;

    last->next = temp;             // Eski ilk düğümü sona ekle.

    printf("ra\n");
}

void rotate_b(t_stack *stack) 
{
    t_node *temp, *last;

    if (!stack->b || !stack->b->next) // Liste boşsa veya tek elemanlıysa işlem yapma.
        return;

    temp = stack->b;                // İlk düğümü geçici olarak sakla.
    stack->b = stack->b->next;       // Liste başını güncelle.
    temp->next = NULL;             // Eski ilk düğümün `next` işaretçisini sıfırla.

    last = stack->b;                // Listeyi son düğüme kadar ilerlet.
    while (last->next)
        last = last->next;

    last->next = temp;             // Eski ilk düğümü sona ekle.

    printf("rb\n");
}

void rotate_r(t_stack *stack) 
{
    if ((!stack->a || !stack->a->next) && (!stack->b || !stack->b->next)) // Her iki liste de boş veya tek elemanlıysa işlem yapma.
        return;

    rotate_a(stack);             // A yığını için döndürme işlemini gerçekleştir.
    rotate_b(stack);             // B yığını için döndürme işlemini gerçekleştir.

    printf("rr\n");
}
