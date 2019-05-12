/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:35:47 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/09 14:44:03 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game		*free_game(t_game *board)
{
	int i;

	i = 0;
	if (board)
	{
		if (board->form)
			ft_tabdel(board->form);
		if (board->oform)
			ft_tabdel(board->oform);
		free(board);
		board = NULL;
	}
	return (NULL);
}

t_player	*free_player(t_player *player)
{
	if (player)
	{
		free(player);
		player = NULL;
	}
	return (NULL);
}

char		*free_line(char *line)
{
	if (line)
		ft_strdel(&line);
	return (NULL);
}

void		free_prog(t_game **b, t_game **p, t_player **ply, char **line)
{
	if (b && *b)
		*b = free_game(*b);
	if (p && *p)
		*p = free_game(*p);
	if (ply && *ply)
		*ply = free_player(*ply);
	if (line && *line)
		*line = free_line(*line);
}

t_game		*init_game(t_game *game)
{
	if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		return (NULL);
	game->h = -1;
	game->w = -1;
	game->form = NULL;
	game->oform = NULL;
	return (game);
}

t_player	*init_player(t_player *player)
{
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	player->y = -1;
	player->x = -1;
	player->nb = 0;
	player->id = 0;
	player->enmy = 0;
	return (player);
}
