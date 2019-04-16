/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/16 19:13:06 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point		*choose_place_board(t_game *board, t_game *piece, t_player *player, t_point *point)
{
	int x;
	int y;
	int i;
	int j;
	int nb;

	y = 0;
	nb = 0;
	i = 0;
	while (board->h > y + point->y)
	{
		x = 0;
		while (board->w > x + point->x)
		{
			printf("y = %d\nx = %d\n", y, x);
			if (board->form[point->y + y][point->x + x] == player->id)
			{
				j = 0;
				while (piece->form[i][j] != '*')
					j++;
				while (nb != piece->size)
					if ((piece->form[y][x] == '*') && (board->form[point->y + y][point->x + x] == '.'))
						nb++;
				printf("y = %d\nx = %d\n", point->y, point->x);
				return (point);
			}
			i++;
			x++;
		}
		y++;
	}
	point = NULL;
	return (point);
}
