/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/04 18:17:32 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_player	*begin_vm(t_player *player, char **line)
{
	if (!*line)
		return (NULL);
	if (ft_strstr(*line, "$$$ exec p") && ft_strstr(*line, "psentilh"))
	{
		if ((ft_strlens(*line) > 11)
		&& ((*line)[10] == '1' || (*line)[10] == '2'))
		{
			player->id = ((*line)[10] == '1' ? 'O' : 'X');
			player->enmy = ((*line)[10] == '1' ? 'X' : 'O');
			player->nb = ((*line)[10] == '1') ? 1 : 2;
			return (player);
		}
	}
	return (NULL);
}

int			main(void)
{
	t_game		*board;
	t_game		*piece;
	t_player	*player;
	char		*line;

	line = NULL;
	board = NULL;
	player = NULL;
	piece = NULL;
	if (!(player = init_player(player)))
		return (-1);
	if (!get_next_line(0, &line) || !(player = begin_vm(player, &line)))
		return (free_prog(&board, &piece, &player, &line) == NULL ? 0 : 0);
	ft_strdel(&line);
	while (1)
	{
		if (!(board = get_board(board, &line))
			|| !(piece = get_piece(piece, &line))
			|| !solve(board, piece, player))
			break ;
		free_prog(NULL, &piece, NULL, &line);
	}
	free_prog(&board, &piece, &player, &line);
	return (0);
}
