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

int			*find_enmy(t_game *b, t_player *ply, int *enmy, int check)
{
	int x;
	int y;

	y = -1;
	enmy[0] = -1;
	enmy[1] = -1;
	while (b->form[++y])
	{
		x = -1;
		while (b->form[y][++x])
		{
			if ((b->oform && b->form[y][x] != '.' && b->form[y][x] != ply->id
			&& b->oform[y][x] == '.' && !check)
			|| (b->form[y][x] != '.' && b->form[y][x] != ply->id && check))
			{
				enmy[0] = y;
				enmy[1] = x;
			}
		}
	}
	if (enmy[0] == -1)
		return (find_enmy(b, ply, enmy, 1));
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

float		check_dist(int *cord, int *enmy, t_game *piece)
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

t_player	*first_solving(t_game *b, t_player *ply, t_game *p, int *enmy)
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
					dist = check_dist(cord, enmy, p);
					ply->y = cord[0];
					ply->x = cord[1];
				}
			}
		}
	}
	return (ply);
}

int			solve(t_game *board, t_game *piece, t_player *player)
{
	int		*enmy;

	if (!board || !piece || !player)
		return (-1);
	if (!(enmy = (int *)ft_memalloc(sizeof(int) * 2)))
		return (-1);
	enmy = find_enmy(board, player, enmy, 0);
	player = first_solving(board, player, piece, enmy);
	free(enmy);
	return (ft_printf("%d %d\n", player->y, player->x));
}
