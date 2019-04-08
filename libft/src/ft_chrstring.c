/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:27 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:16:32 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Search if one of multiple characteres (written in the string chr) are
** contained in a string (str)
*/

int		ft_chrstring(const char *str, char *chr)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (str && chr)
	{
		while (str[i])
		{
			j = 0;
			while (chr[j])
			{
				if (chr[j] == str[i])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}
