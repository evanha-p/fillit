/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:10:31 by evanha-p          #+#    #+#             */
/*   Updated: 2022/04/07 11:28:09 by evanha-p         ###   ########.fr       */
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
void	print_array(int **arr);
t_block *place_values(char **arr, t_block *temp, t_var *var);
t_var	*set_values(void);
t_block	*char2list(char **arr);
t_bool	can_place_part(int grid[4][4], int tetrimino[4][4], t_var *grid_var, t_var *tet_var);
t_bool	place_part(int	grid[4][4], int tetrimino[4][4], t_var *grid_var, t_var *tet_var);
t_bool	check_valid(char **arr);
t_bool	check_content(char *arr);

# define IU_BLOCK (int[4][4]) {\
	{'#','.','.','.'},\
	{'#','.','.','.'},\
	{'#','.','.','.'},\
	{'#','.','.','.'}}
# define IS_BLOCK (int[4][4]) {\
	{'#','#','#','#'},\
	{'.','.','.','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define TU_BLOCK (int[4][4]) {\
	{'.','#','.','.'},\
	{'#','#','#','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define TR_BLOCK (int[4][4]) {\
	{'#','.','.','.'},\
	{'#','#','.','.'},\
	{'#',',','.','.'},\
	{'.','.','.','.'}}
# define TD_BLOCK (int[4][4]) {\
	{'#','#','#','.'},\
	{'.','#','.','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define TL_BLOCK (int[4][4]) {\
	{'.','#','.','.'},\
	{'#','#','.','.'},\
	{'.','#','.','.'},\
	{'.','.','.','.'}}
# define SQ_BLOCK (int[4][4]) {\
	{'#','#','.','.'},\
	{'#','#','.','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define LR_BLOCK (int[4][4]) {\
	{'#','.','.','.'},\
	{'#',',','.','.'},\
	{'#','#','.','.'},\
	{'.','.','.','.'}}
# define LD_BLOCK (int[4][4]) {\
	{'#','#','#','.'},\
	{'#','.','.','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define LL_BLOCK (int[4][4]) {\
	{'#','#',',','.'},\
	{'.','#','.','.'},\
	{'.','#','.','.'},\
	{'.','.','.','.'}}
# define LU_BLOCK (int[4][4]) {\
	{'.','.','#','.'},\
	{'#','#','#','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define JL_BLOCK (int[4][4]) {\
	{'.','#','.','.'},\
	{'.','#','.','.'},\
	{'#','#','.','.'},\
	{'.','.','.','.'}}
# define JU_BLOCK (int[4][4]) {\
	{'#','.','.','.'},\
	{'#','#','#','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define JR_BLOCK (int[4][4]) {\
	{'#','#','.','.'},\
	{'#','.','.','.'},\
	{'#','.','.','.'},\
	{'.','.','.','.'}}
# define JD_BLOCK (int[4][4]) {\
	{'#','#','#',','},\
	{'.','.','#','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define SU_BLOCK (int[4][4]) {\
	{'#','.','.','.'},\
	{'#','#','.','.'},\
	{'.','#','.','.'},\
	{'.','.','.','.'}}
# define SR_BLOCK (int[4][4]) {\
	{'.','#','#','.'},\
	{'#','#','.','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define ZU_BLOCK (int[4][4]) {\
	{'.','#','.','.'},\
	{'#','#','.','.'},\
	{'#','.','.','.'},\
	{'.','.','.','.'}}
# define ZR_BLOCK (int[4][4]) {\
	{'#','#','.','.'},\
	{'.','#','#','.'},\
	{'.','.','.','.'},\
	{'.','.','.','.'}}
# define TEST_BLOCK (int[4][4]) {\
	{'1','1','1','1'},\
	{'2','2','2','2'},\
	{'3','3','3','3'},\
	{'4','4','4','4'}}
# define BLOCK_LIST (**int[20]) {IU_BLOCK,IS_BLOCK,TU_BLOCK,TR_BLOCK,TD_BLOCK,\
	TL_BLOCK,SQ_BLOCK,LR_BLOCK,LD_BLOCK,LL_BLOCK,LU_BLOCK,JL_BLOCK,\
	JU_BLOCK,JR_BLOCK,JD_BLOCK,SU_BLOCK,SR_BLOCK,ZU_BLOCK,ZR_BLOCK,\
	TEST_BLOCK}
#endif
