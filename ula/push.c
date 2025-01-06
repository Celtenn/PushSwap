#include "push_swap.h"

void push_b(t_stack *stack, int bonus) 
{
    t_node *temp;

    if (stack->a) 
    {
        temp = stack->a;               // İlk düğümü kaydediyoruz.
        stack->a = stack->a->next;      // `a` listesini bir ileri taşıyoruz.
        temp->next = stack->b;         // Taşınan düğümü `b` listesinin başına ekliyoruz.
        stack->b = temp;               // `b` listesini güncelliyoruz.
        stack->size_a--;               // `a` listesinin boyutunu azaltıyoruz.
        stack->size_b++;               // `b` listesinin boyutunu artırıyoruz.
        if (!bonus)
            printf("pb\n");
    }
}

void push_a(t_stack *stack, int bonus) 
{
    t_node *temp;

    if (stack->b) 
    {
        temp = stack->b;               // İlk düğümü kaydediyoruz.
        stack->b = stack->b->next;      // `b` listesini bir ileri taşıyoruz.
        temp->next = stack->a;         // Taşınan düğümü `a` listesinin başına ekliyoruz.
        stack->a = temp;               // `a` listesini güncelliyoruz.
        stack->size_b--;               // `b` listesinin boyutunu azaltıyoruz.
        stack->size_a++;               // `a` listesinin boyutunu artırıyoruz.
        if (!bonus)
            printf("pa\n");
    }
}
