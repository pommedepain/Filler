/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/18 19:11:23 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*begin_vm(char *line, t_player *player)
{
	//int i;

	//i = -1;
	while (get_next_line(0, &line) && ft_strstr(line, "$$$ exec p"))
	{
		if (/*ft_strstr(line, "$$$ exec p") &&*/ ft_strstr(line, "psentilh")
			&& (line[10] == '1' || line [10] == '2'))
		{
			player->id = (line[10] == '1' ? 'O' : 'X');
			player->id_enmy = (line[10] == '1' ? 'X' : 'O');
			return (line);
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
	//int i;

	line = NULL;
	board = NULL;
	player = NULL;
	piece = NULL;
	player = init_player(player);
	get_next_line(0, &line);
	line = begin_vm(line, player);
	//printf("player id = %c\n", player->id);
	if (!(board = get_board(board, line)) || !(piece = get_piece(piece/*, line*/))
		|| !solve(board, piece, player))
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
