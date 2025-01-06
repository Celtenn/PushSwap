#include "push_swap.h"

t_node *create_node(int value) 
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

void free_list(t_node *list) 
{
    t_node *tmp;
    while (list) 
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void append_node(t_node **list, int value) 
{
    t_node *newnode = malloc(sizeof(t_node));
	t_node *tmp;
	
	newnode->value = value;
	newnode->next = NULL;

	if (*list == NULL)
	{
		*list = newnode;
	}
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
}

int list_size(t_node *list) 
{
    int size = 0;
    while (list) 
    {
        size++;
        list = list->next;
    }
    return size;
}

void push_swap(char **av, int bonus) 
{
    t_stack stack = {NULL, NULL};
    int     i = -1;

    while (av[++i]) 
    {
        int value = push_swap_atoi(av[i], NULL);
        append_node(&stack.a, value);
    }

    check_doubles(stack.a);

    int size = list_size(stack.a);
    sort(&stack, size);
    //print_stack(stack.a);
    i = 0;
    if (bonus == 1)
    {
        while (av[i])
        {
            free(av[i]);
            i++;
        }
        free(av);
    }
    free_list(stack.a);
    free_list(stack.b);
}

int main(int ac, char **av) 
{
    int bonus;

    bonus = 0;
    if (ac > 1) 
    {
        av++;
        if (ac == 2)
        {
            av = ft_split(*av, ' ');
            bonus = 1;
        }
        push_swap(av, bonus);
        return (0);
    }
    return (0);
}
