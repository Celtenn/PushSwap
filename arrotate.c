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

void	rra(struct deneme *a)
{
	int	temp;
	int i;

	
	if (a->top <= 0)
		return;
	i = a->top;
	temp = a->data[a->top];
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = temp;
}

void	rrb(struct deneme1 *b)
{
	int	temp;
	int i;

	
	if (b->top <= 0)
		return;
	i = b->top;
	temp = b->data[b->top];
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = temp;
}

void	rrr(struct deneme *a, struct deneme1 *b)
{
	rra(&a);
	rrb(&b);
}