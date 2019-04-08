/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:09:32 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:09:33 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_no_whitespaces(char *str)
{
	int		i;
	int		j;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		while (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
			i++;
		j = 0;
		while (str[i + j] != '\0')
		{
			str[i + j] = str[i + j + 1];
			j++;
		}
	}
	str[i] = '\0';
	return (str);
}
