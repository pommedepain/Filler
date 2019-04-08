/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:14:30 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:14:31 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		st;
	int		len;

	if (s == NULL)
		return (NULL);
	st = 0;
	while (s[st] && (s[st] == '\n' || s[st] == '\t' || s[st] == ' '))
		st++;
	if (ft_strlen(s) == 0 || st == (int)ft_strlen(s))
		return (ft_strnew(0));
	len = ft_strlen(s) - 1;
	while (s[len] && (s[len] == '\n' || s[len] == '\t' || s[len] == ' '))
		len--;
	return (ft_strsub(s, st, len - st + 1));
}
