/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/02 19:24:13 by psentilh         ###   ########.fr       */
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
	return (enmy);
}

int			*dist_enmy(t_game *board, t_player *player, int *enmy, int *enmy2, int *cord, int fd)
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
				enmy2[0] = y;
				enmy2[1] = x;
				//dprintf(fd, "\ndist_enmy 1 :\nenmy2[0] = %d\nenmy2[1] = %d\n", enmy2[0], enmy2[1]);
			}
			if ((cord[0] - enmy[0]) > (cord[0] - enmy2[0]) || (cord[1] - enmy[1]) > (cord[1] - enmy2[1]))
			{
				dprintf(fd, "\ndist_enmy 2 :\ncord[0] = %d\ncord[1] = %d\nres enmy[0] = %d\nres enmy[1] = %d\nres enmy2[0] = %d\nres enmy2[1] = %d\n", cord[0], cord[1], (cord[0] - enmy[0]), (cord[1] - enmy[1]), (cord[0] - enmy2[0]), (cord[1] - enmy2[1]));
				enmy[0] = y;
				enmy[1] = x;
				dprintf(fd, "dist_enmy NEW :\nenmy[0] = %d\nenmy[1] = %d\n", enmy[0], enmy[1]);
			}
		}
	}
	//dprintf(fd, "\ndist_enmy 3 :\nenmy[0] = %d\nenmy[1] = %d\n", enmy[0], enmy[1]);
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
					//dprintf(fd, "dist = %d\nenmy[0] = %d && enmy[1] = %d\ncord[0] = %d && cord[1] = %d\ni = %d && j = %d\n", dist, enmy[0], enmy[1], cord[0], cord[1], i, j);
				}
			}
		}
	}
	dprintf(fd, "check_dist = %d\n", dist);
	return (dist);
}

/*t_player	*first_solving(t_game *b, t_player *ply, t_game *p, int *enmy, int fd)
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
				if (dist > check_dist(cord, enmy, p, fd))
				{
					dist = check_dist(cord, enmy, p, fd);
					dprintf(fd, "dist final = %d\n", dist);
					ply->y = cord[0];
					ply->x = cord[1];
				}
			}
		}
	}
	return (ply);
}*/

t_player	*first_solving(t_game *b, t_player *ply, t_game *p, int *enmy, int fd)
{
	int		cord[2];
	int		dist;
	int		*enmy2;

	cord[0] = -1;
	if (!(enmy2 = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	enmy2[0] = -1;
	enmy2[1] = -1;
	dist = 100000;
	while (b->form[++cord[0]])
	{
		cord[1] = -1;
		while (b->form[cord[0]][++cord[1]])
		{
			if (is_pos_valid(b, p, ply, cord) == 1 || (enmy2 = dist_enmy(b, ply, enmy, enmy2, cord, fd)) < enmy)
			{
				if (dist > check_dist(cord, enmy, p, fd))
				{
					dist = check_dist(cord, enmy, p, fd);
					dprintf(fd, "dist final = %d\n", dist);
					ply->y = cord[0];
					ply->x = cord[1];
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
