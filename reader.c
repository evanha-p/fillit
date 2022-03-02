/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:55:17 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 14:59:30 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**read_file(char *argv)
{
	int		i;
	int		fd;
	char	*line;
	int		ret;
	char	**arr;

	i = 0;
	ret = 1;
	arr = (char **)malloc(sizeof(char *) * (125 + 1));
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			arr[i] = ft_strdup(line); 
			free(line);
		}
		else
			arr[i] = NULL;
		i++;
	}
	return (arr);
}
