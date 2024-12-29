struct deneme 
{
	int age;
	struct deneme *next;
};

struct deneme1
{
	int age;
	struct deneme *next;
};

void	sa(struct deneme **head)
{
	struct deneme *one;
	struct deneme *two;
	if (*head && (*head)->next)
	{
		one = *head;
		two = (*head)->next;
		one->next = two->next;
		two->next = one;
		*head = two;
	}
}



void	sb(struct deneme1 **head)
{
	struct deneme1 *one;
	struct deneme1 *two;
	if (*head && (*head)->next)
	{
		one = *head;
		two = (*head)->next;
		one->next = two->next;
		two->next = one;
		*head = two;
	}
}


void	ss()
{
	struct deneme *a;
	struct deneme1 *b;
	
	sa(&a);
	sb(&b);
}


