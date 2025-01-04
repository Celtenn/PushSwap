#include "push_swap.h"

void validate_stacks(t_stack *stack) {
    int count_a = 0, count_b = 0;
    t_node *temp;

    temp = stack->a;
    while (temp) {
        count_a++;
        temp = temp->next;
    }
    temp = stack->b;
    while (temp) {
        count_b++;
        temp = temp->next;
    }

    if (count_a != stack->size_a || count_b != stack->size_b) {
        printf("HATA: a boyut: %d, gerçek: %d | b boyut: %d, gerçek: %d\n",
            stack->size_a, count_a, stack->size_b, count_b);
        exit(EXIT_FAILURE);
    }
}


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
        validate_stacks(stack);
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
        validate_stacks(stack);
    }
}
