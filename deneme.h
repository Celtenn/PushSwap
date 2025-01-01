#ifndef DENEME_H
#define DENEME_H

typedef struct s_stack 
{
    int value;
    struct s_stack *next;
} t_stack;

void radix_sort(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);



#endif

