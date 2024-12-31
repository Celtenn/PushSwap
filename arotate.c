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

void	ra(struct deneme *a)
{
	int	temp;
	int i = 0;

	if (a->top <= 0)
		return;

	temp = a->data[0];
	while (i < a->top)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->top] = temp;
}

void	rb(struct deneme1 *b)
{
	int	temp;
	int i = 0;

	if (b->top <= 0)
		return;

	temp = b->data[0];
	while (i < b->top)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->top] = temp;
}

void	rr(struct deneme *a, struct deneme1 *b)
{
	ra(&a);
	rb(&b);
}