/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfs1s2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:12:31 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:12:32 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfs1s2(char *s1, char *s2)
{
	char	*join;

	join = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdups(s2));
	if (!s2)
		return (s1);
	if (!(join = ft_strnew(ft_strlens(s1) + ft_strlens(s2) + 1)))
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (join);
}
