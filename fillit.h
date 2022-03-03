/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:10:31 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/03 14:27:43 by evanha-p         ###   ########.fr       */
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
t_block	*char2list(char **arr);
char	**read_file(char *argv);
void	print_shape(t_block shape);

#endif
