/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:35:47 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/18 18:10:02 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_bp(t_game *board, t_player *player)
{
	if (board)
	{
		ft_tabdel(board->form);
		free(board);
		board = NULL;
	}
	if (player)
	{
		free(player);
		player = NULL;
	}
}

void		free_game(t_game *board, t_game *piece, t_player *player)
{
	if (board)
	{
		ft_tabdel(board->form);
		free(board);
		board = NULL;
	}
	if (piece)
	{
		ft_tabdel(piece->form);
		free(piece);
		piece = NULL;
	}
	if (player)
	{
		free(player);
		player = NULL;
	}
}

t_game		*init_game(t_game *game)
{
	if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		return (NULL);
	game->h = 0;
	game->w = 0;
	game->size = 0;
	game->form = NULL;
	return (game);
}

t_player	*init_player(t_player *player)
{
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	player->nb = 0;
	player->y = -1;
	player->x = -1;
	player->id = 0;
	return (player);
}

t_point		*new_point(int x, int y)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = 0;
	point->y = 0;
	point->x = x;
	point->y = y;
	return (point);
}
