/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:23:14 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/23 19:02:39 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			game_malloc(t_game *game)
{
	int i;
	int	w;

	w = game->w;
	if (!(game->form = (char **)ft_memalloc(sizeof(char *) * (game->h + 1))))
		return (-1);
	game->form[game->h] = 0;
	i = -1;
	while (++i < game->h)
	{
		if (!(game->form[i] = (char *)ft_memalloc(sizeof(char) * (w + 1))))
		{
			//ft_tabdel(game->form);
			//free(game);
			//game = NULL;
			return (-1);
		}
	}
	game->form[game->h - 1][game->w] = '\0';
	return (0);
}

int			get_size(t_game *game, char *line, int fd)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i++] - 48);
	game->h = nb;
	nb = 0;
	while (line[++i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i] - 48);
	game->w = nb;
	dprintf(fd, "\nh = %d\nw = %d\n\n", game->h, game->w);
	if (game_malloc(game) == -1)
	{
		dprintf(fd, "game_malloc failed\n");
		//ft_tabdel(game->form);
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (0);
}

t_game		*game_loop(t_game *game, char **line, int fd)
{
	int i;
	int j;

	i = -1;
	while (++i < game->h)
	{
		if (get_next_line(0, line) != 1)
		{
			dprintf(fd, "game_loop, get_next_line failed\n");
			return (free_game(game));
		}
		//dprintf(fd, "Game_loop, get_next_line %d = %s\n", i, (*line));
		if (ft_char_only(*line, '.', '*') == 0)
		{
			j = 4;
			while (j - 4 < game->w)
			{
				game->form[i][j - 4] = (*line)[j];
				j++;
			}
		}
		else
		{
			j = 0;
			while (j < game->w)
			{
				game->form[i][j] = (*line)[j];
				j++;
			}
		}
		ft_strdel(line);
	}
	i = -1;
	while (++i < game->h)
		dprintf(fd, "Game_loop, game->form %d =	%s\n", i, game->form[i]);
	return (game);
}
