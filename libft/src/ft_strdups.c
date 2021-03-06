/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:11:53 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:11:54 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdups(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dst;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlens(s1);
	if (!(dst = (char *)malloc(sizeof(*dst) * (len + 1))))
		return (0);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
