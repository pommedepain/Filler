/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/15 18:07:47 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point		*choose_place_board(t_game *board, t_game *piece, t_player *player, t_point *point)
{
	int x;
	int y;
	int nb_sharp;

	y = 0;
	nb_sharp = 0;
	while ((grid->size > y + point->y) && y < 4)
	{
		x = 0;
		while ((grid->size > x + point->x) && x < 4)
		{
			if ((tetri->piece[y][x] == '#')
				&& (grid->tab[point->y + y][point->x + x] == '.'))
				nb_sharp++;
			if (nb_sharp == 4)
				return (point);
			x++;
		}
		y++;
	}
	point = NULL;
	return (point);
}
