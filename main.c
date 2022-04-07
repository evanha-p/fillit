/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:28:18 by evanha-p          #+#    #+#             */
/*   Updated: 2022/04/07 13:03:37 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**arr;
	t_block	*list;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	arr = read_file(argv[1]);
	list = char2list(arr);
	if (!list)
	{
		ft_putstr("error\n");
		return (0);
	}

}
