/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:26:59 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/19 17:18:35 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**arr;
	t_block	*list;
	int		y;
	int		x;
	t_block	test_grid;
	t_block *test_ptr;
	t_var	*test_var_grid;
	t_var	*test_var_tet;
	t_bool	test_bool;

	y = 0;
	x = 0;
	if (argc != 2)
		return (0);
	arr = read_file(argv[1]);
	list = char2list(arr);
	while (arr[y])
	{
		ft_putstr(arr[y]);
		ft_putchar('\n');
		y++;
	}
	y = 0;

	test_ptr = &test_grid;
	while (y < 4)
	{
		while (x < 4)
		{
			if (x == 0)
				test_grid.arr[y][x] = '#';
			else
				test_grid.arr[y][x] = '.';
			x++;
		}
		y++;
		x = 0;
	}
	print_shape(test_ptr);
	ft_putchar('\n');
	test_var_grid = set_values();
	test_var_tet = set_values();
	test_bool = place_part(test_ptr->arr, list->arr, test_var_grid, test_var_tet);
	print_shape(test_ptr);
	ft_putstr("Boolian is: ");
	ft_putnbr(test_bool);
	ft_putchar('\n');
	y = 0;
	while(list->next)
	{
		print_shape(list);
		ft_putchar('\n');
		list = list->next;
	}
	return (0);
}
