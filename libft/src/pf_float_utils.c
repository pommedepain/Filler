/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:20:14 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:20:16 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_search_c(char *str, char c)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_large_number(int pow, char *fraction)
{
	char	*to_process;
	char	*zeros;
	int		i;
	int		size;

	if (!(zeros = (char *)malloc(sizeof(char) * (pow + 1))))
	{
		free(fraction);
		return (NULL);
	}
	i = -1;
	while (++i < pow)
		zeros[i] = '0';
	zeros[i] = '\0';
	fraction = ft_strjoinfs2("1", fraction);
	to_process = ft_strjoinfs2(fraction, zeros);
	free(fraction);
	zeros = ft_strsub(to_process, 0, (pow + 1));
	free(to_process);
	size = ft_strlens(zeros);
	return (zeros);
}

char		*ft_carry(char *str)
{
	int		i;

	i = ft_search_c(str, ':');
	if (i == -1)
		return (str);
	while (str[i] && i)
	{
		if (str[i] == '/')
		{
			str[i]--;
			i--;
			str[i]++;
		}
		if (str[i] == ':')
		{
			str[i] -= 10;
			str[i - 1]++;
		}
		i--;
	}
	return (str);
}

char		*ft_round(char *str, int prec)
{
	char	*str1;
	char	*str2;
	int		i;
	int		size;

	i = ft_search_c(str, '.');
	str1 = ft_strsub(str, 0, i);
	str2 = ft_strsub(str, i + 1, 66);
	size = ft_strlens(str2);
	if (prec == 0)
		return (case1(str, str1, str2, i));
	else if (size < prec)
		return (case2(str, str1, str2, prec));
	else if (str2[prec])
		return (case3(str, str1, str2, prec));
	return (str);
}

char		*final_process(char *tmp)
{
	char		*str1;
	char		*str2;
	int			i;

	i = ft_search_c(tmp, '.');
	str1 = ft_strsub(tmp, 0, i);
	str2 = ft_strsub(tmp, i + 1, 66);
	str1 = ft_leftatoulltoa(str1);
	if (ft_search_c(str2, '1') >= 0)
		str2 = ft_rightatoulltoa(str2);
	else
	{
		free(str2);
		str2 = ft_strnew(1);
		str2[0] = '0';
	}
	str1 = ft_strjoinfs1(str1, ".");
	str1 = ft_strjoinfs1(str1, str2);
	free(tmp);
	free(str2);
	return (str1);
}
