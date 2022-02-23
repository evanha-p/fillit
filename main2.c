/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:56:19 by evanha-p          #+#    #+#             */
/*   Updated: 2022/02/23 18:19:01 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	trim(char	***arr)
{
	 int	x;
	 int	y;
	 int	i;
	 int	valid;
	 char	**temp;

	 x = 0;
	 y = 0;
	 i = 0;
	 valid = 0;
	 temp = (char **)malloc(sizeof(char *) * (125 + 1));
	 while(*arr[y])
	 {
		 while(*arr[y][x])
		 {
			 if (*arr[y][x] == '#')
				 valid = 1;
			 x++;
		 }
		 if (valid == 1)
		 {
			 temp[i] = ft_strdup(*arr[y]);
			 valid = 0;
			 i++;
		 }
		 y++;
		 x = 0;
	 }
	 free(*arr);
	 *arr = temp;
}

int		**char2int(char **arr)
{
	int		**temp;
	int		x;
	int		y;
	int		letter;

	x = 0;
	y = 0;
	letter = 'A';
	temp = (int **)malloc(sizeof(int *) * 125 + 1);
	while (arr[y])
	{
		temp[y] = (int *)malloc(sizeof(int) * 4);
		while(arr[y][x])
		{
			if (arr[y][x] == '.')
				temp[y][x] = '.';
			else if (arr[y][x] == '#')
				temp[y][x] = letter;
			x++;
		}
		x = 0;
		if (!(arr[y][x]))
		{
			temp[y][x] = 5;
			letter++;
		}
		y++;
	}
	temp[y] = NULL;
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
	return (arr);
}

int		main(int argc, char **argv)
{
	char	**arr;
	int		**numbarr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (argc != 2)
		return (0);
	arr = read_file(argv[1]);
	trim(&arr);
	numbarr = (int **)malloc(sizeof(int *) * 125);
	numbarr = char2int(arr);
	while (arr[y])
	{
		ft_putstr(arr[y]);
		ft_putchar('\n');
		y++;
	}
	y = 0;
	while (numbarr[y])
	{
		while (x < 4)
		{
			ft_putchar(numbarr[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
		x = 0;
	}
	ft_putchar(numbarr[4][0]);
	return (0);
}
