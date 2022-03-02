/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:26:59 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 15:59:00 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**arr;
	t_block	*pieces;
	t_block	*list;
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (argc != 2)
		return (0);
	arr = read_file(argv[1]);
	pieces = char2blocks(arr);
	list = char2list(arr);
	while (arr[y])
	{
		ft_putstr(arr[y]);
		ft_putchar('\n');
		y++;
	}
	y = 0;
	ft_putstr("####ARRAY####\n");
	while (pieces[y].arr[0][0] != 0)
	{
		print_shape(pieces[y]);
		ft_putchar('\n');
		y++;
	}
	y = 0;
	ft_putstr("####LIST####\n");
	while(list->next)
	{
		print_shape(list[y]);
		ft_putchar('\n');
		list = list->next;
	}
	return (0);
}
