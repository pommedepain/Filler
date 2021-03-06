/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:06:58 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:07:00 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrchar(char c, char *chr)
{
	int i;

	i = 0;
	while (chr[i])
	{
		if (c == chr[i])
			return (1);
		i++;
	}
	return (0);
}
