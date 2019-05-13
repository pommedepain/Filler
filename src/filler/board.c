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

void		copy_board(t_game **b)
{
	int y;
	int x;

	if (!((*b)->oform))
		if (!(((*b)->oform) =
		(char **)ft_memalloc(sizeof(char *) * (*b)->h + 1)))
			return ;
	y = -1;
	while (++y < (*b)->h)
	{
		if (!((*b)->oform[y]))
			if (!((*b)->oform[y] = ft_strnew((*b)->w + 1)))
				return ;
		x = -1;
		while ((*b)->form[y][++x])
			(*b)->oform[y][x] = (*b)->form[y][x];
	}
}

t_game		*get_board(t_game *board, char **line)
{
	if (board && board->form)
		copy_board(&board);
	if (!board)
		if (!(board = (t_game *)ft_memalloc(sizeof(t_game))))
			return (board);
	if (!get_next_line(0, line) || !ft_strstr(*line, "Plateau "))
		return (free_game(board));
	get_size(board, *line);
	ft_strdel(line);
	if (!get_next_line(0, line))
		return (free_game(board));
	ft_strdel(line);
	if (!board->form)
		if (!(board->form =
		(char **)ft_memalloc(sizeof(char *) * (board->h + 1))))
			return (board);
	return (game_loop(board, line));
}
