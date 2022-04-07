/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:53:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/04/07 13:03:45 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_shape(t_block *shape)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			ft_putchar(shape->arr[y][x]);
			x++;
		}
		x = 0;
		ft_putchar('\n');
		y++;
	}
}

void	print_array(int **arr)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			ft_putchar(arr[y][x]);
			x++;
		}
		x = 0;
		ft_putchar('\n');
		y++;
	}
}

void	shapes_to_top_left(t_block *block, t_var *var)
{
	int	smallest_y;
	int	smallest_x;
	int	x;
	int	y;

	smallest_y = 10;
	smallest_x = 10;
	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (block->arr[y][x] != '.' && smallest_y > y)
				smallest_y = y;
			if (block->arr[y][x] != '.' && smallest_x > x)
				smallest_x = x;
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (block->arr[y][x] != '.')
			{
				block->arr[y][x] = '.';
				block->arr[y - smallest_y][x - smallest_x] = var->letter;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

t_block	*place_values(char **arr, t_block *temp, t_var *var)
{
	t_block	*next;

	while (arr[var->i][var->x])
	{
		if (arr[var->i][var->x] == '.')
			temp->arr[var->y][var->x] = '.';
		else
			temp->arr[var->y][var->x] = var->letter;
		var->x++;
	}
	var->x = 0;
	var->y++;
	if (!(arr[var->i][var->x]))
	{
		shapes_to_top_left(temp, var);
		if (!(check_block(temp->arr)))
			return (NULL);
		var->letter++;
		next = (t_block *)malloc(sizeof(t_block));
		temp->next = next;
		temp = next;
		var->y = 0;
	}
	return (temp);
}

t_var	*set_values(void)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	var->i = 0;
	var->x = 0;
	var->y = 0;
	var->letter = 'A';
	return (var);
}

t_block	*char2list(char **arr)
{
	t_block	*temp;
	t_block	*head;
	t_var	*var;

	if (!(check_valid(arr)))
		return (NULL);
	var = set_values();
	temp = (t_block *)malloc(sizeof(t_block));
	head = temp;
	while (arr[var->i])
	{
		temp = place_values(arr, temp, var);
		if (!temp)
			return (NULL);
		var->i++;
	}
	temp->next = NULL;
	temp = head;
	return (temp);
}
