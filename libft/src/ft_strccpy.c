/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:24:56 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/10 14:13:18 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, char c)
{
	size_t	i;
	size_t	j;
	int		size;

	i = 0;
	while (src[i] != c)
		i++;
	i += 1;
	size = ft_strlens(src) - i;
	dst[size] = '\0';
	j = 0;
	while (src[i] != '\0')
	{
		dst[j] = src[i++];
		j++;
	}
	return (dst);
}
