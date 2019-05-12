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

int		copy_board(t_game **b)
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
	}
	return (1);
}

t_game		*get_board(t_game *board, char **line)
{
	if (!board)
		if (!(board = init_game(board)))
			return (/*free_game(board)*/NULL);
	if (board && board->form)
			if (copy_board(&board) == -1)
				return (/*free_game(board)*/NULL);
	if (!get_next_line(0, line) || !ft_strstr(*line, "Plateau "))
	{
		//free_line(*line);
		return (NULL);
	}
	ft_tabdel(board->form);
	if (get_size(board, *line) == -1)
		return (/*free_game(board)*/NULL);
	if (!get_next_line(0, line))
		return (NULL);
	ft_strdel(line);
	return (game_loop(board, line));
}
