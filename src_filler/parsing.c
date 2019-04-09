/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:38:59 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/09 15:05:21 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_board	*check_board(t_board *board, char **line)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strclen(*line, '\n');
	while (line[i++])
	{
		if (!(board->board[i] = ft_strnew(size + 1)))
			return (NULL);
	}
	board->board[i][size] = '\0';
	ft_tabcpy(board->board, line);
	ft_print_words_tables(board->board);
	return (board);
}

/*int		parsing(t_board *board, char *line)
{
	if (!(board = check_board(board, line)))
		return (-1);
	return (0);
}*/
