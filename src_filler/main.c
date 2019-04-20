/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/20 16:25:16 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_player		*begin_vm(t_player *player, char **line)
{
	if (!*line)
		return (NULL);
	while (!ft_strstr(*line, "$$$ exec p") || !ft_strstr(*line, "psentilh"))
	{
		if ((*line)[10] == '1' || (*line)[10] == '2')
		{
			player->id = ((*line)[10] == '1' ? 'O' : 'X');
			player->id_enmy = ((*line)[10] == '1' ? 'X' : 'O');
			return (player);
		}
		gnl(0, line);
	}
	return (NULL);
}

int			main(void)
{
	t_game		*board;
	t_game		*piece;
	t_player	*player;
	char		*line;
	//int i;

	line = NULL;
	board = NULL;
	player = NULL;
	piece = NULL;
	player = init_player(player);
	if (!gnl(0, &line) || !(player = begin_vm(player, &line)))
		return (-1);
	//printf("\nplayer id = %c\n", player->id);
	while (1)
	{
		if (!(board = get_board(board, &line)) || !(piece = get_piece(piece, &line))
		|| !solve(board, piece, player))
			break ;
		free_game(board, piece, player);
	}
	/*i = 0;
	if ((i = check_first_board(board) == -1))
	{
		free_bp(board, player);
		//printf("Error i = %d\n", i);
		return (-1);
	}*/
	//printf("Valid i = %d\n", i);
	// fait buguer car deja player deja free ligne 36
	//free_game(board, piece, player);
	ft_strdel(&line);
	return (0);
}
