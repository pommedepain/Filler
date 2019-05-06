/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/06 18:01:20 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_borders(t_game *board, t_player *player, int *cord, int fd)
{
	if ((board->form[cord[0]][cord[1]] == player->id || (board->form[cord[0]][cord[1]] != '.' && board->form[cord[0]][cord[1]] != player->enmy))
		&& (cord[0] == 0 || cord[1] == 0 || cord[0] == board->h - 1 || cord[1] == board->w - 1))
	{
		dprintf(fd, "\ncheck_borders:\nborder 1 = %d\nborder 2 = %d\nborder 3 = %d\nborder 4 = %d\n", player->border_1, player->border_2, player->border_3, player->border_4);
		if (cord[0] == 0)
		{
			dprintf(fd, "check_border of border_1 reached\n");
			return (player->border_1 = 1);
		}
		if (cord[1] == 0)
		{
			dprintf(fd, "check_border of border_2 reached\n");
			return (player->border_2 = 1);
		}
		if (cord[0] == board->h - 1)
		{
			dprintf(fd, "check_border of border_3 reached\n");
			return (player->border_3 = 1);
		}
		if (cord[1] == board->w - 1)
		{
			dprintf(fd, "check_border of border_4 reached\n");
			return (player->border_4 = 1); 
		}
		if ((player->border_1 == 1 && player->border_2 == 1) || (player->border_1 == 1 && player->border_3 == 1) || (player->border_1 == 1 && player->border_4 == 1)
					|| (player->border_2 == 1 && player->border_3 == 1) || (player->border_2 && player->border_4 == 1)
					|| (player->border_3 == 1 && player->border_4 == 1))
		{
			//player->nb = (player->nb == 1) ? 2 : 1;
			dprintf(fd, "player->nb = %d\n", player->nb);
			return (0);
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
			if (((board->form[y][x] != '.' && board->form[y][x] != player->id) || board->form[y][x] == player->enmy) && player->nb == 1)
			{
				enmy[0] = y;
				enmy[1] = x;
				return (enmy);
			}
			else if (((board->form[y][x] != '.' && board->form[y][x] != player->id) || board->form[y][x] == player->enmy) && player->nb == 2)
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

int			check_dist(int *cord, int *enmy, t_game *piece, int fd)
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
					dprintf(fd, "\ndist = %d\nenmy[0] = %d && enmy[1] = %d\ncord[0] = %d && cord[1] = %d\n", dist, enmy[0], enmy[1], cord[0], cord[1]);
				}
			}
		}
	}
	dprintf(fd, "check_dist = %d\n", dist);
	return (dist);
}

int			*attack_elsewhere(t_game *board, t_player *player, int fd)
{
	int		*n_enmy;

	if (!(n_enmy = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	n_enmy[0] = -1;
	n_enmy[1] = -1;
	if (player->nb == 1)
		player->nb = 2;
	else if (player->nb == 2)
		player->nb = 1;
	n_enmy = find_enmy(board, player, n_enmy);
	dprintf(fd, "\nattack_elsewhere:\nn_enmy[0] = %d\nn_enmy[1] = %d\n", n_enmy[0], n_enmy[1]);
	if (n_enmy[0] == -1)
		return (NULL);
	return (n_enmy);
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
			if (check_borders(b, ply, cord, fd) == 1 && (enmy2 = attack_elsewhere(b, ply, fd) != enmy))
			{
				enmy = attack_elsewhere(b, ply, fd);
				dprintf(fd, "check_borders true\n");
				if (ply->border_1 == 1 || ply->border_2 == 1 || ply->border_3 == 1 || ply->border_4 == 1)
				{
					cord[0] = 0;
					cord[1] = 0;
				}
				else if ((ply->border_1 == 1 && ply->border_2 == 1) || (ply->border_1 == 1 && ply->border_3 == 1) || (ply->border_1 == 1 && ply->border_4 == 1)
					|| (ply->border_2 == 1 && ply->border_3 == 1) || (ply->border_2 && ply->border_4 == 1)
					|| (ply->border_3 == 1 && ply->border_4 == 1))
				{
					dprintf(fd, "borders reached:\nborder 1 = %d\nborder 2 = %d\nborder 3 = %d\nborder 4 = %d\n", ply->border_1, ply->border_2, ply->border_3, ply->border_4);
				}
			}
			if (is_pos_valid(b, p, ply, cord) == 1)
			{
				if (ply->border_1 == 1 || ply->border_2 == 1 || ply->border_3 == 1 || ply->border_4 == 1)
					dist = 100000;
				if (dist > check_dist(cord, enmy, p, fd))
				{
					dist = check_dist(cord, enmy, p, fd);
					dprintf(fd, "dist final = %d\n", dist);
					ply->y = cord[0];
					ply->x = cord[1];
					if (ply->border_1 == 1 || ply->border_2 == 1 || ply->border_3 == 1 || ply->border_4 == 1)
						return (ply);
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
