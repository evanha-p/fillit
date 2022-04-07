/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:58:46 by evanha-p          #+#    #+#             */
/*   Updated: 2022/04/01 17:34:27 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	can_place_part(int grid[4][4], int tetrimino[4][4], t_var *grid_var, t_var *tet_var)
{
	if (grid[grid_var->y][grid_var->x] != '.' &&
			tetrimino[tet_var->y][tet_var->x] != '.')
		return (false);
	else
		return (true);
}

t_bool	place_part(int grid[4][4], int tetrimino[4][4], t_var *grid_var, t_var *tet_var)
{
	t_var	*temp_grid;
	int		temp_int;

	temp_grid = set_values();
	if (tet_var->y < 4)
	{
		*temp_grid = *grid_var;
		temp_int = grid[grid_var->y][grid_var->x];
		if (can_place_part(grid, tetrimino, grid_var, tet_var))
		{
			if (grid[grid_var->y][grid_var->x] == '.')
				grid[grid_var->y][grid_var->x] = tetrimino[tet_var->y][tet_var->x];
			if (tet_var->x == 3)
			{
				tet_var->y++;
				grid_var->y++;
				tet_var->x = 0;
				grid_var->x -= 3;
			}
			else
			{
				tet_var->x++;
				grid_var->x++;
			}
			if (place_part(grid, tetrimino, grid_var, tet_var))
				return (true);
			grid[temp_grid->y][temp_grid->x] = temp_int;
			return (false);
		}
		else
			return (false);
	}
	return (true);
}

