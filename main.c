#include <stdio.h>
#include <stdlib.h>

struct deneme 
{
	char *str;
	int age;
	struct deneme *next;
};

void	created(struct deneme **head, int age, char *str)
{
	struct deneme *newdeneme = malloc(sizeof(struct deneme));
	struct deneme *tmp;
	
	newdeneme->age = age;
	newdeneme->str = str;
	newdeneme->next = NULL;

	if (*head == NULL)
	{
		*head = newdeneme;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newdeneme;
	}
}

int	ft_atoi(char *str)
{
	int i = 0;
	int neg = 1;
	int result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
		{
			neg *= -1;
			i++;
		}
		else
			i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result *= 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

void	printnumber(struct deneme **head)
{
	struct deneme *current = *head;
	while (current != NULL)
	{
		printf("%d\n%s", current->age, current->str);
		current = current->next;
	}
}

void	freelist(struct deneme *head)
{
	struct deneme *current = head;
	struct deneme *tmp;

	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	
}
void	deletenumber(struct deneme **head)
{
	struct deneme *current = *head;
	struct deneme *temp = current;

	while (current != NULL)
	{
		if (current->next->age == 30)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			break;
		}
		else
			current = current->next;
	}
}
int main()
{
	int i;
	char *str = "ali";
	struct deneme *deneme2;
	struct deneme *deneme1 = NULL;
	 
	created(&deneme1, 50, str);
	created(&deneme1, 30, str);
	created(&deneme1, 20, str);
	created(&deneme1, 60, str);
	created(&deneme1, 70, str);

	deletenumber(&deneme1);
	printnumber(&deneme1);
}
