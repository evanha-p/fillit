/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:36:30 by evanha-p          #+#    #+#             */
/*   Updated: 2022/04/07 12:55:58 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	compare_block(int arr[4][4], int correct[4][4])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (correct[y][x] == '#' && !(arr[y][x] >= 'A' && arr[y][x] <= 'Z'))
				return (false);
			if (correct[y][x] == '.' && arr[y][x] != '.')
				return (false);
			x++;
		}
		x = 0;
		y++;
	}
	return (true);
}

t_bool	check_block(int arr[4][4])
{
	if (compare_block(arr, IU_BLOCK) || compare_block(arr, IS_BLOCK))
		return (true);
	if (compare_block(arr, TU_BLOCK) || compare_block(arr, TR_BLOCK))
		return (true);
	if (compare_block(arr, TD_BLOCK) || compare_block(arr, TL_BLOCK))
		return (true);
	if (compare_block(arr, SQ_BLOCK))
		return (true);
	if (compare_block(arr, LR_BLOCK) || compare_block(arr, LD_BLOCK))
		return (true);
	if (compare_block(arr, LL_BLOCK) || compare_block(arr, LU_BLOCK))
		return (true);
	if (compare_block(arr, JL_BLOCK) || compare_block(arr, JU_BLOCK))
		return (true);
	if (compare_block(arr,JR_BLOCK) || compare_block(arr, JD_BLOCK))
		return (true);
	if (compare_block(arr, SU_BLOCK) || compare_block(arr, SR_BLOCK))
		return (true);
	if (compare_block(arr, ZU_BLOCK) || compare_block(arr, ZR_BLOCK))
		return (true);
	return (false);
}

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
