/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:09:39 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:09:40 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(unsigned long long int n, int b_size)
{
	int		i;

	i = 1;
	while (n >= (unsigned long long)b_size)
	{
		(b_size != 2 && b_size != 8 && b_size != 16) ? n /= b_size : 0;
		b_size == 2 ? n >>= 1 : 0;
		b_size == 8 ? n >>= 3 : 0;
		b_size == 16 ? n >>= 4 : 0;
		i++;
	}
	return (i);
}
