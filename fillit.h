/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:10:31 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 14:58:00 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_block
{
	int		arr[4][4];
}		t_block;

typedef	struct	s_sol
{
	int		*arr;
	int		size;
}		t_solution;

int	get_next_line(const int fd, char **line);

#endif
