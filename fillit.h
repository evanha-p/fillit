/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:10:31 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/19 17:03:39 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_var
{
	int		x;
	int		y;
	int		i;
	int		letter;
}	t_var;

typedef struct s_block	t_block;
struct	s_block
{
	int		arr[4][4];
	t_block	*next;
};

typedef enum e_bool
{
	false,
	true
}	t_bool;

int		get_next_line(const int fd, char **line);
char	**read_file(char *argv);
void	print_shape(t_block *shape);
t_block *place_values(char **arr, t_block *temp, t_var *var);
t_var	*set_values(void);
t_block	*char2list(char **arr);
t_bool	can_place_part(int grid[4][4], int terimino[4][4], t_var *grid_var, t_var *tet_var);
t_bool	place_part(int	grid[4][4], int tetrimino[4][4], t_var *grid_var, t_var *tet_var);

#endif
