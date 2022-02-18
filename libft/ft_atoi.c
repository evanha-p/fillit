/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:31 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 19:27:34 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checkSign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	preValue;
	int	sign;

	i = 0;
	value = 0;
	preValue = 0;
	sign = 0;
	while (ft_iswspace(str[i]) != 0)
		i++;
	sign = ft_checkSign(str[i]);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		preValue = value;
		value = value * 10 + sign * (str[i] - '0');
		if ((sign == 1 && value < preValue) || (sign == -1 && value > preValue))
			return (-1);
		i++;
	}
	return (value);
}
