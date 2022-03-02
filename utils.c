/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:53:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 17:24:04 by evanha-p         ###   ########.fr       */
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

t_var	set_values(void)
{
	t_var	var;

	var.i = 0;
	var.x = 0;
	var.y = 0;
	var.letter = 'A';
	return (var);
}

t_block	*char2list(char **arr)
{
	t_block	*temp;
	t_block	*next;
	t_block	*head;
	t_var	var;

	var = set_values();
	temp = (t_block *)malloc(sizeof(t_block));
	head = temp;
	while (arr[var.i])
	{
		while (arr[var.i][var.x])
		{
			if (arr[var.i][var.x] == '.')
				temp->arr[var.y][var.x] = '.';
			else
				temp->arr[var.y][var.x] = var.letter;
			var.x++;
		}
		var.x = 0;
		var.y++;
		if (!(arr[var.i][var.x]))
		{
			var.letter++;
			next = (t_block *)malloc(sizeof(t_block));
			temp->next = next;
			temp = next;
			var.y = 0;
		}
		var.i++;
	}
	temp->next = NULL;
	temp = head;
	return (temp);
}
