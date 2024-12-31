#include <stdio.h>
#include <stdlib.h>

// Yığın düğüm yapısı
typedef struct s_node 
{
    int value;
    struct s_node *next;
} t_node;

// Yeni bir değeri yığına ekle
t_node *push(t_node *stack, int value) 
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = stack;
    return (new_node);
}

// Yığının üstündeki değeri çıkar
int pop(t_node **stack) 
{
    if (!(*stack))
        return (-1);
    int value = (*stack)->value;
    t_node *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return (value);
}

// Yığını yazdır
void print_stack(t_node *stack) 
{
    while (stack) 
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

// Yığındaki düğüm sayısını say
int stack_size(t_node *stack) 
{
    int count = 0;
    while (stack) 
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

// Yığındaki maksimum değeri bul
int find_max(t_node *stack) 
{
    int max = stack->value;
    while (stack) 
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

// Radix Sort'un optimize edilmiş versiyonu
void radix_sort(t_node **stack_a, t_node **stack_b) 
{
    int max = find_max(*stack_a); // En büyük sayıyı bul
    int digit_pos = 1; // Başlangıç basamağı: Birler basamağı
    int ra_count = 0, pb_count = 0, pa_count = 0; // Aksiyon sayaçları

    while (digit_pos <= max) 
    {
        // Yığındaki her elemanı uygun kovanın içine yerleştir
        int size = stack_size(*stack_a);
        int i = 0;
        while (i < size) 
        {
            int num = pop(stack_a);
            int digit = (num / digit_pos) % 10; // Basamağı al
            *stack_b = push(*stack_b, num); // Kova B'ye yerleştir
            pb_count++;
            i++;
        }

        // Kova B'yi küçükten büyüğe sıralayarak stack_a'ya geri ekleyelim
        while (*stack_b) 
        {
            int min_value = pop(stack_b);
            t_node **current = stack_a;
            // Her yeni değeri küçükten büyüğe ekleyecek şekilde sıralıyoruz
            while (*current && (*current)->value < min_value) 
            {
                current = &((*current)->next);
            }
            t_node *new_node = malloc(sizeof(t_node));
            new_node->value = min_value;
            new_node->next = *current;
            *current = new_node;
            ra_count++;
        }

        digit_pos *= 10; // Bir sonraki basamağa geç
    }

    // Toplam aksiyon sayısını yazdır
    printf("\nToplam aksiyonlar: ra=%d, pb=%d, toplam=%d\n", ra_count, pb_count, ra_count + pb_count);
}

int main() 
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    int numbers[] = {73, 28, 94, 18, 53, 63, 40, 35, 2, 75, 46, 83, 90, 7, 54, 86, 15, 69, 32, 44,
        99, 6, 88, 51, 41, 78, 23, 61, 4, 22, 95, 11, 9, 84, 67, 71, 37, 8, 29, 97,
        17, 52, 19, 55, 12, 33, 38, 10, 76, 59, 96, 80, 21, 72, 34, 3, 68, 56, 42, 24,
        13, 1, 25, 26, 20, 30, 81, 45, 5, 87, 36, 48, 39, 85, 50, 60, 77, 74, 16, 31,
        98, 43, 62, 89, 27, 14, 49, 64, 70, 66, 57, 100, 79, 47, 92, 91, 65, 100, 82, 93, 58, 0, -100, -3};
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
