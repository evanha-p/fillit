/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:07:50 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/17 16:25:21 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordCount(char const *str, char deli)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != deli && i == 0)
			words++;
		else if (str[i] == deli && str[i + 1] && str[i + 1] != deli)
		{
			words++;
			i++;
			while (str[i] != deli && str[i])
				i++;
			i--;
		}
		i++;
	}
	return (words);
}

static	char	*ft_writeString(char const *str, char deli, int i)
{
	int		temp;
	int		j;
	size_t	len;
	char	*ret;

	temp = i;
	j = 0;
	len = 0;
	while (str[i] != deli && str[i])
	{
		len++;
		i++;
	}
	ret = ft_strnew(len);
	i = temp;
	while (str[i] != deli && str[i] && ret != NULL)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	return (ret);
}

static	int	ft_skipper(char const *str, char deli, int i)
{
	while (str[i] != deli && str[i])
		i++;
	return (i);
}

static	char	**ft_splitter(char const *str, char deli,
		int *iCount, char **ret)
{
	while (str[iCount[0]])
	{
		if (str[iCount[0]] != deli && iCount[0] == 0)
		{
			ret[iCount[1]] = ft_writeString(str, deli, iCount[0]);
			if (!ret[iCount[1]++])
				return (ft_arrclean(ret));
		}
		else if (str[iCount[0]] == deli && str[iCount[0] + 1]
			&& str[iCount[0] + 1] != deli)
		{
			ret[iCount[1]] = ft_writeString(str, deli, iCount[0] + 1);
			if (!ret[iCount[1]++])
				return (ft_arrclean(ret));
			iCount[0] = ft_skipper(str, deli, iCount[0] + 1) - 1;
		}
		iCount[0]++;
	}
	ret[iCount[1]] = NULL;
	return (ret);
}

char	**ft_strsplit(char const *str, char deli)
{
	int		iCount[2];
	char	**ret;

	ft_memset(iCount, 0, sizeof(iCount));
	if (!str)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * ft_wordCount(str, deli) + 1);
	if (!ret)
		return (NULL);
	ret = ft_splitter(str, deli, iCount, ret);
	return (ret);
}
