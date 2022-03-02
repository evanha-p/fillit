/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:53:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 15:58:52 by evanha-p         ###   ########.fr       */
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

t_block	*char2list(char **arr)
{
	t_block	*temp;
	t_block	*next;
	t_block *head;
	int		x;
	int		y;
	int		letter;
	int		i;

	x = 0;
	y = 0;
	letter = 'A';
	i = 0;
	temp = (t_block *)malloc(sizeof(t_block));
	head = temp;
	while (arr[i])
	{
		while (arr[i][x])
		{
			if (arr[i][x] == '.')
				temp->arr[y][x] = '.';
			else
				temp->arr[y][x] = letter;
			x++;
		}
		x = 0;
		y++;
		if (!(arr[i][x]))
		{
			letter++;
			next = (t_block *)malloc(sizeof(t_block));
			temp->next = next;
			temp = next;
			y = 0;
		}
		i++;
	}
	temp->next = NULL;
	temp = head;
	return (temp);
}
