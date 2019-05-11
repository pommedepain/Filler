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

int		copy_board(t_game **b, int fd)
{
	int y;
	int x;

	if (!((*b)->oform))
		if (!(((*b)->oform) = (char **)ft_memalloc(sizeof(char *) * (*b)->h + 1)))
			return (-1);
	y = -1;
	while ((*b)->form[++y])
	{
		if (!((*b)->oform[y]))
			if (!((*b)->oform[y] = ft_strnew((*b)->w)))
				return (-1);
		x = -1;
		while ((*b)->form[y][++x])
			(*b)->oform[y][x] = (*b)->form[y][x];
		dprintf(fd, "%s\n", (*b)->oform[y]);
	}
	return (1);
}

t_game		*get_board(t_game *board, char **line, int fd)
{
	if (!board)
		if (!(board = init_game(board)))
			return (free_game(board, fd));
	if (board && board->form)
	{
		dprintf(fd, "\ncopy_board:\n");
		if (copy_board(&board, fd) == -1)
			return (free_game(board, fd));
	}
	if (!get_next_line(0, line) || !ft_strstr(*line, "Plateau "))
	{
		free_line(*line, fd);
		dprintf(fd, "Get_board, fail strstr = %s\n", *line);
		return (NULL);
	}
	dprintf(fd, "\nGet_size, Board =");
	ft_tabdel(board->form);
	if (get_size(board, *line, fd) == -1)
	{
		dprintf(fd, "Get_size, fail = %s\n", *line);
		return (free_game(board, fd));
	}
	if (!get_next_line(0, line))
		return (NULL);
	dprintf(fd, "get_board line we jump = %s\n\n", (*line));
	ft_strdel(line);
	return (game_loop(board, line, fd));
}
