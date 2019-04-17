/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/17 16:43:01 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			*find_enmy(t_game *board, t_player *player, int *enmy)
{
	int x;
	int y;

	y = -1;
	while (board->form[++y])
	{
		x = -1;
		while (board->form[y][++x])
		{
			if (board->form[y][x] != '.' && board->form[y][x] != player->id)
			{
				enmy[0] = y;
				enmy[1] = x;
			}
		}
	}
	if (enmy[0] == -1 || enmy[1] == -1)
		return ((int *)-1);
	return (enmy);
}

int			is_pos_valid(t_game *board, t_game *piece, t_player *player, int *cord)
{
	int i;
	int j;

	i = -1;
	while (piece->form[++i])
	{
		j = -1;
		while (piece->form[i][++j])
		{
			if (piece->form[i][j] == '*' && cord[0] + i < board->h
				&& cord[1] + j < board->w
				&& board->form[cord[0] + i][cord[1] + j] == player->id)
				return (1);
		}
	}
	return (0);
}

t_player	*first_solving(t_game *board, t_player *player, t_game *piece, int *enmy)
{
	int		cord[2];

	cord[0] = -1;
	while (board->form[++cord[0]])
	{
		cord[1] = -1;
		while (board->form[cord[0]][++cord[1]])
		{
			if (is_pos_valid(board, piece, player, cord))
				if (check_dist())
		}
	}
	return (player);
}

int			solve(t_game *board, t_game *piece, t_player *player)
{
	t_point	*point;
	int		*enmy;

	point = NULL;
	point = new_point(0, 0);
	if (!(enmy = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	enmy[0] = -1;
	enmy[1] = -1;
	enmy = find_enmy(board, player, enmy);
	printf("enmy[0] = %d\nenmy[1] = %d\n", enmy[0], enmy[1]);
	player = first_solving(board, player, piece, enmy);
	return (ft_printf("%d %d\n", point->y, point->x));
}

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
