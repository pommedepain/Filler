/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:40:59 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/02 13:41:34 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_count_board(t_game *board, char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i++])
		count++;
	i = (board->w + 4);
	if (count != (board->w + 4))
	{
		ft_strdel(board->form);
		return (-1);
	}
	return (0);
}

t_game		*get_board(t_game *board, char **line, int fd)
{
	if ((board = init_game(board)) == NULL)
		return (NULL);
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
