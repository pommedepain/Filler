/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/23 14:33:29 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			*find_enmy(t_game *board, t_player *player, int *enmy/*, int beg*/)
{
	int x;
	int y;

	y = -1;
	while (board->form[++y])
	{
		x = -1;
		while (board->form[y][++x])
		{
			if ((board->form[y][x] != '.' && board->form[y][x] != player->id) || (board->form[y][x] != '.' && board->form[y][x] != player->id))
			{
				enmy[0] = y;
				enmy[1] = x;
			}
		}
	}
	return (enmy);
}

int			is_pos_valid(t_game *board, t_game *piece, t_player *player, int *cord)
{
	int i;
	int j;
	int	check;

	i = -1;
	check = -1;
	while (piece->form[++i])
	{
		j = -1;
		while (piece->form[i][++j])
		{
			if (piece->form[i][j] == '*' && cord[0] + i < board->h
				&& cord[1] + j < board->w
				&& board->form[cord[0] + i][cord[1] + j] == player->id && check == -1)
				check = 1;
			else if (piece->form[i][j] == '*' && (cord[0] + i >= board->h
				|| cord[1] + j >= board->w
				|| (board->form[cord[0] + i][cord[1] + j] == player->id && check)
				|| board->form[cord[0] + i][cord[1] + j] != '.'))
				return (0);
		}
	}
	if (check == -1)
		return (0);
	return (1);
}

int			check_dist(int *cord, int *enmy, t_game *piece)
{
	int i;
	int j;
	int dist;

	i = -1;
	dist = 10000;
	while (piece->form[++i])
	{
		j = -1;
		while (piece->form[i][++j])
		{
			if (piece->form[i][j] != '.')
			{
				if (dist > (enmy[0] - i - cord[0]) * (enmy[0] - i - cord[0])
					+ (enmy[1] - j - cord[1]) * (enmy[1] - j - cord[1]))
				{
					dist = (enmy[0] - i - cord[0]) * (enmy[0] - i - cord[0])
					+ (enmy[1] - j - cord[1]) * (enmy[1] - j - cord[1]);
				}
			}
		}
	}
	return (dist);
}

t_player	*first_solving(t_game *board, t_player *player, t_game *piece, int *enmy)
{
	int		cord[2];
	int		dist;

	cord[0] = -1;
	dist = 100000;
	while (board->form[++cord[0]])
	{
		cord[1] = -1;
		while (board->form[cord[0]][++cord[1]])
		{
			if (is_pos_valid(board, piece, player, cord) == 1)
			{
				if (dist > check_dist(cord, enmy, piece))
				{
					dist = check_dist(cord, enmy, piece);
					player->y = cord[0];
					player->x = cord[1];
				}
			}
		}
	}
	return (player);
}

int			solve(t_game *board, t_game *piece, t_player *player, int fd)
{
	int		*enmy;

	dprintf(fd, "\n\nSOLVE :\n");
	if (!(enmy = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	enmy[0] = -1;
	enmy[1] = -1;
	enmy = find_enmy(board, player, enmy);
	dprintf(fd, "enmy[0] = %d\nenmy[1] = %d\n", enmy[0], enmy[1]);
	player = first_solving(board, player, piece, enmy);
	dprintf(fd, "\n\nFINAL CORD : %d %d\n", player->y, player->x);
	return (ft_printf("%d %d\n", player->y, player->x));
}
