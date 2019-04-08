/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_util_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:50:17 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/03 16:30:10 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		search_zero(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		if (str[i] == '0')
			return (1);
		while (str[i] < '0' || str[i] >= '9')
		{
			if (str[i] == '0')
				return (1);
			i++;
		}
	}
	return (0);
}

int		char_counter(char *str, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

char	*precision_string(char *str, int i)
{
	char	*res;
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (i-- > 0)
		res[k++] = str[j++];
	return (res);
}
