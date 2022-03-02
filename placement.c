void	print_placement(int *arr)
{
	int i;

	i = 0;
	while(arr[i])
	{
		ft_putchar(arr[i]);
		i++;
	}
}

void	find_placement(t_block *pieces)
{
	int *solution;
	int	size;
	int b = 0;
	int i = 0;
	int j = 0;
	int c = 0;
	int r = 0;

	size = 4;
	solution = (int *)malloc(sizeof(int) * (size * size));
	while(pieces[b].arr[0][0] != 0)
	{
		while (i < 4)
		{
			while (solution[(r * size) + c] != '.')
			{
				c++;
				if (c == 4)
				{
					r++;
					c = 0;
				}
				if (!solution[(r * size) + c])
				{
					break ; // voisko tassa ola  recursio ja suurentua size jos se tuis parametrina
				}
			}
			while (j < 4)
			{
				if (pieces[b].arr[i][j] != '.')
					solution[(r * size) + c] = pieces[b].arr[i][j];
				c++;
				j++;
			}
			while (c < 4)
			{
				solution[(r * size) + c] = '.';
				c++;
			}
			i++;
			j = 0;
			c = 0;
			r++;
		}
		r = 0;
		i = 0;
		b++;
	}
	print_placement(solution);
}