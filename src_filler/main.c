/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/17 11:16:20 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	if (get_next_line(0, &line) && ft_strlens(line) > 10
		&& ft_strncmp(line, "$$$ exec p", 11) && (line[10] == '1'
		|| line [10] == '2'))
	{
		player = init_player(player);
		player->id = (line[10] == '1' ? 'O' : 'X');
		player->id_enmy = (line[10] == '1' ? 'X' : 'O');
	}
	printf("player id = %c\n", player->id);
	if (!get_board(board, line) && !get_piece(piece/*, line*/))
		free_game(board, piece, player);
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
	//ft_strdel(&line);
	return (0);
}
