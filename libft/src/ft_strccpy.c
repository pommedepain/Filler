/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:24:56 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/09 18:54:19 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, char c)
{
	size_t	i;

	i = 0;
	ft_putchar('\n');
	ft_putendl(src);
	while (src[i] != c)
		i++;
	while (src[i] != '\0')
	{
		ft_putchar(src[i]);
		ft_putchar('\n');
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	ft_putendl(dst);
	return (dst);
}
