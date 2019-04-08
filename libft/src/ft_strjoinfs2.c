/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:12:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:12:38 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfs2(char *s1, char *s2)
{
	char	*join;

	join = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (ft_strdups(s1));
	if (!(join = ft_strnew(ft_strlens(s1) + ft_strlens(s2) + 1)))
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	free(s2);
	s1 = NULL;
	return (join);
}
