/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:35:47 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/15 18:00:30 by psentilh         ###   ########.fr       */
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
