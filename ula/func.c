#include "push_swap.h"

void error_detected(t_node *head) {
    t_node *tmp;

    // Listeyi serbest bırak
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("Error\n");
    exit(1);
}

int push_swap_atoi(char *str, t_node *head) {
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

int push_swap_strlen(char **av) {
    int i = 0;
    while (*av) {
        av++;
        i++;
    }
    return i;
}

int check_sorted(t_node *stack, int order) {
    t_node *current = stack;

    if (current == NULL || current->next == NULL) 
	{
        return 1;  // Liste boş ya da sadece bir eleman var, sıralıdır
    }

    // Küçükten büyüğe sıralama kontrolü
    if (order == 0) {
        while (current->next != NULL) 
		{
            if (current->value > current->next->value) 
			{
                return 0;  // Liste sıralı değil
            }
            current = current->next;
        }
    }
    // Büyükten küçüğe sıralama kontrolü
    else if (order == 1) {
        while (current->next != NULL) {
            if (current->value < current->next->value) {
                return 0;  // Liste sıralı değil
            }
            current = current->next;
        }
    }

    return 1;  // Liste sıralı
}



void check_doubles(t_node *head) {
    t_node *current, *checker;

    current = head;
    while (current) {
        checker = current->next;
        while (checker) {
            if (current->value == checker->value)
                error_detected(head);
            checker = checker->next;
        }
        current = current->next;
    }
}

int	countw(char const *s, char c)
{
	int	i;
	int	wnumber;

	i = 0;
	wnumber = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
		}
		else
		{
			wnumber++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
	}
	return (wnumber);
}

char	*creatw(char *daz, char const *s, int first_i, int last_i)
{
	int	i;

	i = 0;
	while (i < last_i)
	{
		daz[i] = s[first_i + i];
		i++;
	}
	daz[i] = '\0';
	return (daz);
}

char	*create_single_word(char const *s, int *index, char c)
{
	int		w_len;
	int		first;
	char	*word;

	w_len = 0;
	first = *index;
	while (s[*index] != c && s[*index])
	{
		w_len++;
		(*index)++;
	}
	word = (char *)malloc(sizeof(char) * (w_len + 1));
	if (!word)
		return (0);
	creatw(word, s, first, w_len);
	return (word);
}

char	**create_word(char **daza, char const *s, char c, int k_len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] && k < k_len)
	{
		if (s[i] != c)
		{
			daza[k] = create_single_word(s, &i, c);
			if (!daza[k])
			{
				while (--k > -1)
					free(daza[k]);
				free(daza);
				return (0);
			}
			k++;
		}
		else
			i++;
	}
	daza[k] = NULL;
	return (daza);
}

char	**ft_split(char const *s, char c)
{
	int		k_len;
	char	**str;

	if (!s)
		return (0);
	k_len = countw(s, c);
	str = (char **)malloc(sizeof(char *) * (k_len + 1));
	if (!str)
		return (0);
	str = create_word(str, s, c, k_len);
	return (str);
}