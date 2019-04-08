/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:11:24 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:11:25 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmps(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (0 - ((unsigned char *)s2)[i]);
	if (s1 && !s2)
		return (((unsigned char *)s1)[i] - 0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
