/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:14:06 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:14:07 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sep(char c, char sep)
{
	int		i;

	i = 0;
	if (sep == c)
		return (1);
	else
		return (0);
}

static int		ft_count_word(const char *str, char c)
{
	int		i;
	int		wcount;

	wcount = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_sep(str[i], c))
			i++;
		while (str[i] && !(ft_sep(str[i], c)))
			i++;
		wcount++;
	}
	if (ft_sep(str[i - 1], c))
		wcount--;
	return (wcount);
}

static int		ft_len(const char *str, char c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i] && !ft_sep(str[i], c))
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *str, char c)
{
	int		j;
	int		i;
	int		k;
	char	**tab;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(tab) * (ft_count_word(str, c) + 1))))
		return (0);
	while (i < ft_count_word(str, c))
	{
		k = 0;
		while (str[j] && ft_sep(str[j], c))
			j++;
		if (!(tab[i] = malloc(sizeof(*tab) * (ft_len(&str[j], c)) + 1)))
			return (0);
		while (str[j] && !(ft_sep(str[j], c)))
			tab[i][k++] = str[j++];
		tab[i++][k] = '\0';
	}
	tab[ft_count_word(str, c)] = 0;
	return (tab);
}
