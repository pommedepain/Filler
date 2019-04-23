/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:35:47 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/23 18:59:33 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game		*free_game(t_game *board)
{
	if (board)
	{
		if (board->form)
			ft_tabdel(board->form);
		free(board);
		board = NULL;
	}
	return (NULL);
}

void		free_prog(t_game *board, t_game *piece, t_player *player, char **line)
{
	if (board)
	{
		if (board->form)
			ft_tabdel(board->form);
		free(board);
		board = NULL;
	}
	if (piece)
	{
		if (piece->form)
			ft_tabdel(piece->form);
		free(piece);
		piece = NULL;
	}
	if (player)
	{
		free(player);
		player = NULL;
	}
	if (line)
	{
		ft_strdel(line);
		line = NULL;
	}
}

t_game		*init_game(t_game *game)
{
	if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		return (NULL);
	game->h = 0;
	game->w = 0;
	//game->size = 0;
	game->form = NULL;
	return (game);
}

t_player	*init_player(t_player *player)
{
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	//player->nb = 0;
	player->y = -1;
	player->x = -1;
	player->id = 0;
	return (player);
}
