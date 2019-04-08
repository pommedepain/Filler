/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 19:31:52 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*char		*find_name(char *info, int pos)
{
	char	*name;
	int		i;

	name = NULL;
	while (info[pos] != '[')
		pos++;
	i = 0;
	while (info[pos] != ']')
			i++;
	name = ft_strnew(i);
	pos = 0;
	while (info[pos] != '[')
		pos++;
	i = 0;
	while (info[pos] != ']')
	{
		name[i] = info[pos++];
		i++;
	}
	name[i] = '\0';
	return (name);
}*/

/*t_player	*init_player(char *info, t_player *player)
{
	int i;

	if (!info)
	{
		//free_player(player);
		return (NULL);
	}
	player->nb = 0;
	i = 0;
	while (info[i++])
	{
		if (ft_isdigit(i))
			player->nb = ft_atoi(&info[i]);
		else
			return (NULL);
	}
	player->name = find_name(info, i);
	return (player);
}*/

t_map		*init_map(t_map *map)
{
	map->h = 0;
	map->w = 0;
	map->map = NULL;
}

int			main(int ac, char **av)
{
	t_map	*map;
	int		fd;

	fd = 0;
	map = NULL;
	if (ac > 4)
		return (-1);
	if (!(fd = open(av[1], O_RDONLY)))
		return (-1);
	map = init_map(map);
	if (!parsing(map, fd))
	{
		close(fd);
		//free_map(map);
		return (-1);
	}
	close(fd);
	return (0);
}
