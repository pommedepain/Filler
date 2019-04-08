/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:22:41 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:22:46 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **dst, char **src)
{
	int k;

	k = 0;
	while (src[k])
	{
		dst[k] = ft_strcpy(dst[k], src[k]);
		k++;
	}
	return (dst);
}
