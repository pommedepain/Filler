/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:35:47 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/06 15:19:23 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game		*free_game(t_game *board, int fd)
{
	int i;

	i = 0;
	if (board)
	{
		if (board->form)
			ft_tabdel(board->form);
		free(board);
		board = NULL;
		dprintf(fd, "free game\n");
	}
	return (NULL);
}

t_player	*free_player(t_player *player, int fd)
{
	if (player)
	{
		free(player);
		player = NULL;
		dprintf(fd, "free player\n");
	}
	return (NULL);
}

char		*free_line(char *line, int fd)
{
	if (line)
	{
		ft_strdel(&line);
		dprintf(fd, "free line\n");
	}
	return (NULL);
}

void		free_prog(t_game **board, t_game **piece, t_player **player, char **line, int fd)
{
	if (board && *board)
	{
		*board = free_game(*board, fd);
		dprintf(fd, "free board\n");
	}
	if (piece && *piece)
	{
		*piece = free_game(*piece, fd);
		dprintf(fd, "free piece\n");
	}
	if (player && *player)
		*player = free_player(*player, fd);
	if (line && *line)
		*line = free_line(*line, fd);
}

t_game		*init_game(t_game *game)
{
	if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		return (NULL);
	game->h = -1;
	game->w = -1;
	//game->size = 0;
	game->form = NULL;
	game->oform = NULL;
	game->start = -1;
	return (game);
}

t_player	*init_player(t_player *player)
{
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	//player->nb = 0;
	player->y = -1;
	player->x = -1;
	player->nb = 0;
	player->id = 0;
	player->enmy = 0;
	return (player);
}
