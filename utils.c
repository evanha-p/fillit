/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:53:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/21 17:25:24 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	check_content(char *arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (!(arr[i] == '#' || arr[i] == '.' || !(arr[i])))
				return (false);
		i++;
	}
	return (true);
}

t_bool	check_valid(char **arr)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (arr[i])
	{
		if (!(arr[i][0]))
		{
			if (y != 4)
				return (false);
			y = 0;
			i++;
			continue ;
		}
		if (!(ft_strlen(arr[i]) == 4 || ft_strlen(arr[i]) == 0))
			return (false);
		if (!(check_content(arr[i])))
			return (false);
		i++;
		y++;
	}
	if (y != 0)
		return (false);
	return (true);
}

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
		ft_putstr("Kaak\n");
	var = set_values();
	temp = (t_block *)malloc(sizeof(t_block));
	head = temp;
	while (arr[var->i])
	{
		temp = place_values(arr, temp, var);
		var->i++;
	}
	temp->next = NULL;
	temp = head;
	return (temp);
}
