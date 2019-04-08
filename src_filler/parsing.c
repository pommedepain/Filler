/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:38:59 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 19:43:37 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**check_map(t_map *map, int fd)
{
	char **tmp[BUFF_SIZE + 1];
	int ret;

	ret = 0;
	tmp = NULL;
	if ((ret = read(fd, tmp, BUFF_SIZE)) == -1)
		return (NULL);
	tmp[ret] = '\0';
	return (tmp);
}

int		parsing(t_map *map, int fd)
{
	map->map = check_map(map, fd);
	return (0);
}
