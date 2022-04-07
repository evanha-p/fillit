/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:26:59 by evanha-p          #+#    #+#             */
/*   Updated: 2022/04/04 15:42:34 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**arr;
	t_block	*list;
	int		y;

	y = 0;
	if (argc != 2)
		return (0);
	arr = read_file(argv[1]);
	list = char2list(arr);
	while (arr[y])
	{
		ft_putstr(arr[y]);
		if (!(arr[y][0]))
			ft_putstr("Found null\n");
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
	y = 0;
	while(list->next)
	{
		print_shape(list);
		ft_putchar('\n');
		list = list->next;
	}
	ft_putchar('\n');
	return (0);
}
