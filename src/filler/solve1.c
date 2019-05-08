/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:15:58 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/08 16:43:36 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_borders(t_game *board, t_player *player)
{
	int y;
	int x;

	y = -1;
	while (board->form[++y])
	{
		x = -1;
		while (board->form[y][++x])
		{
			if (board->form[y][x] == player->id && board->form[y][x] != '.' && y == 0)
				return (player->border_1 = 1);
			if (board->form[y][x] == player->id && board->form[y][x] != '.' && x == 0)
				return (player->border_2 = 1);
			if (board->form[y][x] == player->id && board->form[y][x] != '.' && y == (board->h - 1))
				return (player->border_3 = 1);
			if (board->form[y][x] == player->id && board->form[y][x] != '.' && x == (board->w - 1))
				return (player->border_4 = 1);
		}
	}	
	return (0);
}

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
			if ((board->form[y][x] != '.' && board->form[y][x] != player->id) || board->form[y][x] == player->enmy)
			{
				enmy[0] = y;
				enmy[1] = x;
			}
		}
	}
	return (enmy);
}

int			is_pos_valid(t_game *b, t_game *p, t_player *ply, int *cord)
{
	int i;
	int j;
	int	check;

	i = -1;
	check = -1;
	while (p->form[++i])
	{
		j = -1;
		while (p->form[i][++j])
		{
			if (p->form[i][j] == '*' && cord[0] + i < b->h
				&& cord[1] + j < b->w
				&& b->form[cord[0] + i][cord[1] + j] == ply->id && check == -1)
				check = 1;
			else if (p->form[i][j] == '*' && (cord[0] + i >= b->h
				|| cord[1] + j >= b->w
				|| (b->form[cord[0] + i][cord[1] + j] == ply->id && check)
				|| b->form[cord[0] + i][cord[1] + j] != '.'))
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
				if (dist > ((enmy[0] - i - cord[0]) * (enmy[0] - i - cord[0]))
					+ ((enmy[1] - j - cord[1]) * (enmy[1] - j - cord[1])))
				{
					dist = ((enmy[0] - i - cord[0]) * (enmy[0] - i - cord[0]))
					+ ((enmy[1] - j - cord[1]) * (enmy[1] - j - cord[1]));
				}
			}
		}
	}
	return (dist);
}

int			where_am_i(t_game *board, t_player *player, int *enmy, int fd)
{
	while (board->form[++enmy[0]])
	{
		while (board->form[enmy[0][++enmy[1]]])
		{
			if (board->form[enmy[0][enmy[1]]] == player->id && board->form[enmy[0][enmy[1]]] != '.')
			{
				player->y = enmy[0];
				player->x = enmy[1];
				return (1);
			}
		}
		enmy[1] = -1;
	}
	return (0);
}

int			deploy(t_game *board, t_player *player, int *enmy, int fd)
{
	if (where_am_i(board, player, enmy, fd) == 1)
	{
		if (player->y <= (board->h / 2))
			
	}
}

t_player	*first_solving(t_game *b, t_player *ply, t_game *p, int *enmy, int fd)
{
	int		cord[2];
	int		dist;

	cord[0] = -1;
	dist = 100000;
	while (b->form[++cord[0]])
	{
		cord[1] = -1;
		while (b->form[cord[0]][++cord[1]])
		{
			if (is_pos_valid(b, p, ply, cord) == 1)
			{
				if (dist > check_dist(cord, enmy, p))
				{
					dprintf(fd, "\ndist = %d\nenmy[0] = %d && enmy[1] = %d\ncord[0] = %d && cord[1] = %d\n", dist, enmy[0], enmy[1], cord[0], cord[1]);
					dist = check_dist(cord, enmy, p);
					if (dist <= 25)
						deploy(b, ply, enmy, fd);
					dprintf(fd, "dist final = %d\n", dist);
					ply->y = cord[0];
					ply->x = cord[1];
					dprintf(fd, "ply->y = %d\nply->x = %d\n", ply->y, ply->x);
				}
			}
		}
	}
	return (ply);
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
	dprintf(fd, "1st enmy[0] = %d\nenmy[1] = %d\n", enmy[0], enmy[1]);
	player = first_solving(board, player, piece, enmy, fd);
	dprintf(fd, "\n\nFINAL CORD : %d %d\n", player->y, player->x);
	free(enmy);
	return (ft_printf("%d %d\n", player->y, player->x));
}
