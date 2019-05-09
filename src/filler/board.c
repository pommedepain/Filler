/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:40:59 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/09 13:23:22 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		copy_board(t_game **board, int fd)
{
	int y;
	int x;

	dprintf(fd, "board->h = %d\n", (*board)->h);
	if (!((*board)->oform))
		if (!(((*board)->oform) = (char **)malloc(sizeof(char *) * (*board)->h + 1)))
			return ;
	y = -1;
	while ((*board)->form[++y])
	{
		if (!((*board)->oform[y] = ft_strnew((*board)->w)))
			return ;
		x = -1;
		while ((*board)->form[y][++x])
			(*board)->oform[y][x] = (*board)->form[y][x];
		dprintf(fd, "%s\n", (*board)->oform[y]);
	}
}

t_game		*get_board(t_game *board, char **line, int fd)
{
	if (!board)
		if ((board = init_game(board)) == NULL)
			return (NULL);
	if (board && board->form != NULL)
	{
		dprintf(fd, "\ncopy_board:\n");
		copy_board(&board, fd);
	}
	if (!get_next_line(0, line) || !ft_strstr(*line, "Plateau "))
	{
		dprintf(fd, "Get_board, fail strstr = %s\n", *line);
		return (free_game(board, fd));
	}
	dprintf(fd, "\nGet_size, Board =");
	if (get_size(board, *line, fd) == -1)
	{
		dprintf(fd, "Get_size, fail = %s\n", *line);
		return (NULL);
	}
	if (!get_next_line(0, line))
		return (NULL);
	dprintf(fd, "get_board line we jump = %s\n\n", (*line));
	ft_strdel(line);
	return (game_loop(board, line, fd));
}
