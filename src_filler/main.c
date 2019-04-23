/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/23 19:03:44 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_player	*begin_vm(t_player *player, char **line, int fd)
{
	if (!*line)
		return (NULL);
	if (ft_strstr(*line, "$$$ exec p") && ft_strstr(*line, "psentilh"))
	{
		if ((*line)[10] == '1' || (*line)[10] == '2')
		{
			dprintf(fd, "begin_vm, char = %c\n", (*line)[10]);
			player->id = ((*line)[10] == '1' ? 'O' : 'X');
			//player->id_enmy = ((*line)[10] == '1' ? 'X' : 'O');
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
	int			fd;

	line = NULL;
	board = NULL;
	player = NULL;
	piece = NULL;
	if (!(fd = open("fichier_test", O_WRONLY | O_CREAT, 0644)))
		return (-1);
	dprintf(fd, "test\n");
	player = init_player(player);
	if (!get_next_line(0, &line) || !(player = begin_vm(player, &line, fd)))
	{
		free_prog(NULL, NULL, player, &line);
		dprintf(fd, "Main, fail begin_vm = %s\n", line);
		return (-1);
	}
	dprintf(fd, "\nMain, success player = %c\n", player->id);
	while (1)
	{
		if (!(board = get_board(board, &line, fd))
			|| !(piece = get_piece(piece, &line, fd))
			|| !solve(board, piece, player, fd))
		{
			dprintf(fd, "while 1 break\n");
			break ;
		}
		//free_game(NULL, piece, NULL, &line);
	}
	free_prog(board, piece, player, &line);
	dprintf(fd, "\n\nEnd of program\n");
	close(fd);
	return (0);
}
