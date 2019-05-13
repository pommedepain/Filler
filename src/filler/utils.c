/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:35:47 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/09 14:44:03 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		*free_game(t_game *board)
{
	int i;

	i = -1;
	if (board)
	{
		if (board->form)
		{
			while (++i < board->h)
				free(board->form[i]);
			free(board->form);
		}
		i = -1;
		if (board->oform)
		{
			while (++i < board->h)
				free(board->oform[i]);
			free(board->oform);
		}
		free(board);
	}
	return (NULL);
}

void		*free_player(t_player *player)
{
	if (player)
		free(player);
	return (NULL);
}

void		*free_line(char *line)
{
	if (line)
		ft_strdel(&line);
	return (NULL);
}

void		*free_prog(t_game **b, t_game **p, t_player **ply, char **line)
{
	if (b && *b)
		*b = free_game(*b);
	if (p && *p)
		*p = free_game(*p);
	if (ply && *ply)
		*ply = free_player(*ply);
	if (line && *line)
		*line = free_line(*line);
	return (NULL);
}

t_player	*init_player(t_player *player)
{
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	player->y = -1;
	player->x = -1;
	player->nb = 0;
	player->id = 0;
	player->enmy = 0;
	return (player);
}
