/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:47:45 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/24 16:23:18 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **as)
{
	int i;

	i = 0;
	if (as)
	{
		while (as[i])
			free(as[i++]);
		free(as);
	}
	as = NULL;
}
