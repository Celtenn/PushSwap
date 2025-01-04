#include "push_swap.h"

void rotate_a(t_stack *stack, int bonus) {
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
    if (!bonus)
        printf("ra\n");
}

void rotate_b(t_stack *stack, int bonus) {
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
    if (!bonus)
        printf("rb\n");
}

void rotate_r(t_stack *stack, int bonus) {
    if ((!stack->a || !stack->a->next) && (!stack->b || !stack->b->next)) // Her iki liste de boş veya tek elemanlıysa işlem yapma.
        return;

    rotate_a(stack, 1);             // A yığını için döndürme işlemini gerçekleştir.
    rotate_b(stack, 1);             // B yığını için döndürme işlemini gerçekleştir.
    if (!bonus)
        printf("rr\n");
}
