/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:10:31 by evanha-p          #+#    #+#             */
/*   Updated: 2022/02/24 23:33:58 by evanha-p         ###   ########.fr       */
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

int	get_next_line(const int fd, char **line);

#endif
