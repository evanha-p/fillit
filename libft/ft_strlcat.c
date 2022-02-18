/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:03:26 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/07 19:30:25 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t destSize)
{
	size_t	i;
	size_t	j;
	int		destLen;
	int		intSize;
	size_t	ret;

	i = ft_strlen(dest);
	j = 0;
	destLen = i;
	intSize = destSize;
	if (destSize > ft_strlen(dest))
		ret = ft_strlen(dest) + ft_strlen(source);
	else
		ret = destSize + ft_strlen(source);
	while (intSize - (destLen + 1) > 0 && source[j])
	{
		dest[i] = source[j];
		i++;
		j++;
		intSize--;
	}
	dest[i] = '\0';
	return (ret);
}
