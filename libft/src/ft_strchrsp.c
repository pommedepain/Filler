/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrsp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:02:58 by pommedepin        #+#    #+#             */
/*   Updated: 2019/04/20 15:03:01 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrsp(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)(s + 1));
	return (NULL);
}
