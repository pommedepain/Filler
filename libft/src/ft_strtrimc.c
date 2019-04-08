/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:22:30 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:22:31 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	int		st;
	int		len;
	char	*new;

	if (s == NULL)
		return (NULL);
	st = 0;
	new = NULL;
	while (s[st] && (s[st] == c))
		st++;
	if (ft_strlens(s) == 0 || st == (int)ft_strlens(s))
	{
		ft_strdel((char **)&s);
		return (ft_strnew(0));
	}
	len = ft_strlens(s) - 1;
	while (s[len] && (s[len] == c))
		len--;
	new = ft_strsub(s, st, len - st + 1);
	ft_strdel((char **)&s);
	return (new);
}
