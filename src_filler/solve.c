/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:37 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/19 15:25:24 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			*find_enmy(t_game *board, t_player *player, int *enmy, int beg)
{
	int x;
	int y;

	y = -1;
	while (board->form[++y])
	{
		x = -1;
		while (board->form[y][++x])
		{
			if ((board->form[y][x] != '.' && board->form[y][x] != player->id && !beg) || (board->form[y][x] != '.' && board->form[y][x] != player->id && beg))
			{
				//printf("Enmy y = %d\nx = %d\n", y, x);
				enmy[0] = y;
				enmy[1] = x;
			}
		}
	}
	if (enmy[0] == -1)
	{
		//printf("Enmy[0] == -1\n");
		return (find_enmy(board, player, enmy, 1));
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
			{
				//printf("Pos valid\ni = %d & j = %d\n", i, j);
				check = 1;
			}
			else if (piece->form[i][j] == '*' && (cord[0] + i >= board->h
				|| cord[1] + j >= board->w
				|| (board->form[cord[0] + i][cord[1] + j] == player->id && check)
				|| board->form[cord[0] + i][cord[1] + j] != '.'))
			{
				//printf("Pos non valid\n");
				return (0);
			}
		}
	}
	if (check == -1)
	{
		//printf("int check == -1\n");
		return (0);
	}
	return (1);
}

int			check_dist(int *cord, int *enmy, t_game *piece)
{
	int i;
	int j;
	int dist;

	i = -1;
	dist = 99999;
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
	dist = 999999;
	while (board->form[++cord[0]])
	{
		cord[1] = -1;
		while (board->form[cord[0]][++cord[1]])
		{
			if (is_pos_valid(board, piece, player, cord) == 1)
			{
				//printf("cord[0] = %d\ncord[1] = %d\n", cord[0], cord[1]);
				if (dist > check_dist(cord, enmy, piece))
				{
					dist = check_dist(cord, enmy, piece);
					//printf("dist = %d\n", dist);
					player->y = cord[0];
					player->x = cord[1];
				}
			}
		}
	}
	return (player);
}

int			solve(t_game *board, t_game *piece, t_player *player)
{
	int		*enmy;

	if (!(enmy = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	enmy[0] = -1;
	enmy[1] = -1;
	enmy = find_enmy(board, player, enmy, 0);
	//printf("enmy[0] = %d\nenmy[1] = %d\n", enmy[0], enmy[1]);
	player = first_solving(board, player, piece, enmy);
	return (ft_printf("%d %d\n", player->y, player->x));
}
