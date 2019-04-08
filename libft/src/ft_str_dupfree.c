/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:10:40 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:10:43 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_dupfree(char *str)
{
	char	*new;

	new = NULL;
	new = ft_strdups(str);
	free(str);
	str = NULL;
	return (new);
}
