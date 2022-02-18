/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:36:01 by evanha-p          #+#    #+#             */
/*   Updated: 2022/02/18 16:29:36 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_strdup(const char *source)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(*copy) * ft_strlen(source) + 1);
	if (copy == NULL)
		return (NULL);
	while (source[i])
	{
		copy[i] = source[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

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

int	main(int argc, char **argv)
{
	char	**arr;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	arr = read_file(argv[1]);
	while (arr[i])
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
