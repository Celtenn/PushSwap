#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *a;
    t_node *b;
    int size_a;
    int size_b;
} t_stack;

// functions
void validate_stacks(t_stack *stack);
void    error_detected(t_node *head);
int     push_swap_atoi(char *str, t_node *head);
int     push_swap_strlen(char **av);
int check_sorted(t_node *stack, int order);
void    check_doubles(t_node *head);
char	**ft_split(char const *s, char c);
int list_size(t_node *head);

// Stack Manipulation Functions
void print_stack(t_node *stack);
void    push_a(t_stack *stack, int bonus);
void    push_b(t_stack *stack, int bonus);
void    rotate_a(t_stack *stack, int bonus);
void    rotate_b(t_stack *stack, int bonus);
void    rotate_r(t_stack *stack, int bonus);
void    reverse_rotate_a(t_stack *stack, int bonus);
void    reverse_rotate_b(t_stack *stack, int bonus);
void    reverse_rotate_r(t_stack *stack, int bonus);
void    swap_a(t_stack *stack, int bonus);
void    swap_b(t_stack *stack, int bonus);
void    swap_s(t_stack *stack, int bonus);

// Sorting Functions
void temporary_sort(t_node *head);
void    three_numbers_case_stack_a(t_stack *three);
int sort(t_stack *stack, int size);
int     ft_push(t_stack *stack, int len, int push);
void    quicksort_three_stack_a_and_b(t_stack *stack, int len);
int     sort_three_b(t_stack *stack, int len);
int mediane_of_numbers(int *pivot, t_node *stack, int size);
int quicksort_stack_a(t_stack *stack, int len, int count_r);
int     quicksort_stack_b(t_stack *stack, int len, int count_r);

// Utility Functions
void    append_node(t_node **head, int value);
void    free_list(t_node *head);

#endif
