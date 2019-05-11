/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/11 15:13:04 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			*find_enmy(t_game *board, t_player *player, int *enmy, int check, int fd)
{
	int x;
	int y;

	y = -1;
	enmy[0] = -1;
	enmy[1] = -1;
	while (board->form[++y])
	{
		x = -1;
		while (board->form[y][++x])
		{
			if ((board->oform && board->form[y][x] != '.' && board->form[y][x] != player->id
				&& board->oform[y][x] == '.' && !check)
				|| (board->form[y][x] != '.' && board->form[y][x] != player->id && check))
			{
				enmy[0] = y;
				enmy[1] = x;
			}
		}
	}
	if (enmy[0] == -1)
		return (find_enmy(board, player, enmy, 1, fd));
	return (enmy);
}

int			is_pos_valid(t_game *b, t_game *p, t_player *ply, int *cord)
{
	int i;
	int j;
	int	check;

	i = -1;
	check = 0;
	while (p->form[++i])
	{
		j = -1;
		while (p->form[i][++j])
		{
			if (p->form[i][j] == '*' && cord[0] + i < b->h
				&& cord[1] + j < b->w
				&& b->form[cord[0] + i][cord[1] + j] == ply->id && !check)
				check = 1;
			else if (p->form[i][j] == '*' && (cord[0] + i >= b->h
				|| cord[1] + j >= b->w
				|| (b->form[cord[0] + i][cord[1] + j] == ply->id && check)
				|| b->form[cord[0] + i][cord[1] + j] != '.'))
				return (0);
		}
	}
	if (!check)
		return (0);
	return (1);
}

float			check_dist(int *cord, int *enmy, t_game *piece)
{
	int		i;
	int		j;
	float	dist;

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

t_player	*first_solving(t_game *b, t_player *ply, t_game *p, int *enmy, int fd)
{
	int		cord[2];
	float	dist;

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
					dprintf(fd, "\ndist = %f\nenmy[0] = %d && enmy[1] = %d\ncord[0] = %d && cord[1] = %d\n", dist, enmy[0], enmy[1], cord[0], cord[1]);
					dist = check_dist(cord, enmy, p);
					dprintf(fd, "dist final = %f\n", dist);
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
	int i;

	dprintf(fd, "\n\nSOLVE :\n");
	if (!board || !piece || !player)
		return(-1);
	if (!(enmy = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	//enmy[0] = -1;
	//enmy[1] = -1;
	i = -1;
	if (board->oform != NULL)
		while (++i < board->h)
			dprintf(fd, "OFORM %d :	%s\n", i, board->oform[i]);
	enmy = find_enmy(board, player, enmy, 0, fd);
	dprintf(fd, "1st enmy[0] = %d\nenmy[1] = %d\n", enmy[0], enmy[1]);
	player = first_solving(board, player, piece, enmy, fd);
	dprintf(fd, "\n\nFINAL CORD : %d %d\n", player->y, player->x);
	free(enmy);
	return (ft_printf("%d %d\n", player->y, player->x));
}
