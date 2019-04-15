/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:35:47 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/15 17:39:08 by psentilh         ###   ########.fr       */
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
