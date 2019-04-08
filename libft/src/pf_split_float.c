/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_split_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:15:50 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:15:51 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_zero(char *str)
{
	int		i;

	i = 0;
	while (str[i] && i < 5)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char			*case1(char *str, char *str1, char *str2, int i)
{
	if (str2[0] > '5' || (str2[0] == '5' && (!(is_zero(&str2[1]))
	|| str1[i - 1] % 2)))
	{
		str1[i - 1]++;
		free(str);
		free(str2);
		return (ft_carry(str1));
	}
	else
	{
		free(str);
		free(str2);
		return (str1);
	}
}

char			*case2(char *str, char *str1, char *str2, int prec)
{
	int		size;
	char	*to_print;

	size = ft_strlens(str2);
	while (size < prec)
	{
		str2 = ft_strjoinfs1(str2, "0");
		size++;
	}
	to_print = ft_strjoinfs1(str1, ".");
	to_print = ft_strjoinfs1(to_print, str2);
	free(str2);
	free(str);
	return (to_print);
}

char			*case3(char *str, char *str1, char *str2, int prec)
{
	char	*to_print;

	str2[prec] >= '5' ? str2[prec - 1]++ : 0;
	str2[prec] = '\0';
	if (str2[prec - 1] == ':')
	{
		to_print = ft_strjoinfs1(str1, ".");
		to_print = ft_strjoinfs1(to_print, str2);
		free(str2);
		free(str);
		ft_carry(to_print);
	}
	else
	{
		to_print = ft_strjoinfs1(str1, ".");
		to_print = ft_strjoinfs1(to_print, str2);
		free(str2);
		free(str);
	}
	return (to_print);
}
