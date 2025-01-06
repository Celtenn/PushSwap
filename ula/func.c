#include "push_swap.h"

void print_stack(t_node *stack) 
{
    while (stack) 
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void error_detected(t_node *head) 
{
    t_node *tmp;

    while (head) 
	{
        tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("Error\n");
    exit(1);
}

int push_swap_atoi(char *str, t_node *head) 
{
    unsigned int i = 0;
    int sign = 1;
    unsigned long int number = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            error_detected(head);
        number = (str[i] - '0') + (number * 10);
        i++;
    }
    if ((number > 2147483648 && sign == -1) || (number > 2147483647 && sign == 1))
        error_detected(head);
    return (number * sign);
}

int push_swap_strlen(char **av) 
{
    int i = 0;
    while (*av) 
	{
        av++;
        i++;
    }
    return (i);
}

int check_sorted(t_node *stack, int order) 
{
    t_node *current = stack;

    if (current == NULL || current->next == NULL) 
	{
        return 1;
    }

    if (order == 0) 
	{
        while (current->next != NULL) 
		{
            if (current->value > current->next->value) 
			{
                return 0;
            }
            current = current->next;
        }
    }

    else if (order == 1) 
	{
        while (current->next != NULL) 
		{
            if (current->value < current->next->value) 
			{
                return 0;
            }
            current = current->next;
        }
    }
    return 1;
}

void check_doubles(t_node *head) 
{
    t_node *current, *checker;

    current = head;
    while (current) 
	{
        checker = current->next;
        while (checker) 
		{
            if (current->value == checker->value)
                error_detected(head);
            checker = checker->next;
        }
        current = current->next;
    }
}
