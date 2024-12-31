struct deneme 
{
	int	*data;
	int top;
};

struct deneme1
{
	int	*data;
	int top;
};

void	pa(deneme *a, deneme1 *b)
{
	if (b->top < 0)
	{
		return;
	}
	int value = b->data[b->top];
	a->data[++(a->top)] = value;
	b->top--;
}

void	pb(deneme *a, deneme1 *b)
{
	if (a->top < 0)
	{
		return;
	}
	int value = a->data[a->top];
	b->data[++(b->top)] = value;
	a->top--;
}