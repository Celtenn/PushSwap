#include "push_swap.h"

// Yeni düğüm oluşturur
t_node *create_node(int value) {
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

// Listeyi temizler
void free_list(t_node *list) {
    t_node *tmp;
    while (list) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

// Listeye eleman ekler
void append_node(t_node **list, int value) {
    t_node *new_node = create_node(value);
    if (!new_node)
        return;
    if (!*list) {
        *list = new_node;
    } else {
        t_node *temp = *list;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

// Listenin uzunluğunu hesaplar
int list_size(t_node *list) {
    int size = 0;
    while (list) {
        size++;
        list = list->next;
    }
    return size;
}

// push_swap algoritması
void push_swap(char **av) {
    t_stack stack = {NULL, NULL};
    int     i = -1;

    // Listeyi oluştur
    while (av[++i]) {
        int value = push_swap_atoi(av[i], NULL); // push_swap_atoi fonksiyonuna göre düzenle
        append_node(&stack.a, value);
    }

    // Tekrarları kontrol et
    check_doubles(stack.a);

    // Boyutu hesapla ve sıralama yap
    int size = list_size(stack.a);
    sort(&stack, size);

    // Belleği temizle
    printf("a : ");
    print_stack(stack.a);
    printf("b : ");
    print_stack(stack.b);
    free_list(stack.a);
    free_list(stack.b);
}
void print_stack(t_node *stack) 
{
    while (stack) 
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}
// Ana fonksiyon
int main(int ac, char **av) {
    if (ac > 1) {
        av++;
        if (ac == 2)
            av = ft_split(*av, ' ');
        push_swap(av);
        return (0);
    }
    return (0);
}
