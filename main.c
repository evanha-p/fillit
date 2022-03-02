/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:26:59 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 15:58:08 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_shape(t_block shape)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			ft_putchar(shape.arr[y][x]);
			x++;
		}
		x = 0;
		ft_putchar('\n');
		y++;
	}
}

t_block	*char2blocks(char **arr)
{
	t_block	*temp;
	int		x;
	int		y;
	int		letter;
	int		block;
	int		i;

	x = 0;
	y = 0;
	letter = 'A';
	block = 0;
	i = 0;
	temp = (t_block	*)malloc(sizeof(t_block) * 26);
	while (arr[i])
	{
		while (arr[i][x])
		{
			if (arr[i][x] == '.')
				temp[block].arr[y][x] = '.';
			else
				temp[block].arr[y][x] = letter;
			x++;
		}
		x = 0;
		y++;
		if (!(arr[i][x]))
		{
			letter++;
			block++;
			y = 0;
		}
		i++;
	}
	temp[block].arr[0][0] = 0;
	return (temp);
}
char	**read_file(char *argv)
{
	int		i;
	int		fd;
	char	*line;
	int		ret;
	char	**arr;

	i = 0;
	ret = 1;
	arr = (char **)malloc(sizeof(char *) * (125 + 1));
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			arr[i] = ft_strdup(line); 
			free(line);
		}
		else
			arr[i] = NULL;
		i++;
	}
	close(fd);
	return (arr);
}

int		main(int argc, char **argv)
{
	char	**arr;
	t_block	*pieces;
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (argc != 2)
		return (0);
	arr = read_file(argv[1]);
	pieces = char2blocks(arr);
	while (arr[y])
	{
		ft_putstr(arr[y]);
		ft_putchar('\n');
		y++;
	}
	y = 0;
	while (pieces[y].arr[0][0] != 0)
	{
		print_shape(pieces[y]);
		ft_putchar('\n');
		y++;
	}
	return (0);
}
