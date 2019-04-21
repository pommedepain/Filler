/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:40:59 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/21 18:59:55 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_count_board(t_game *board, char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while(str[i++])
		count++;
	i = (board->w + 4);
	if (count != (board->w + 4))
	{
		ft_strdel(board->form);
		return (-1);
	}
	return (0);
}

int			check_first_board(t_game *board)
{
	int i;
	int j;
	int	count_X;
	int count_O;
	int count;

	i = -1;
	count_X = 0;
	count_O = 0;
	count = 0;
	while (++i < board->h)
	{
		j = -1;
		while (board->form[i][++j])
		{
			if (board->form[i][j] == 'X')
				count_X += 1;
			if (board->form[i][j] == 'O')
				count_O += 1;
			if (board->form[i][j] == '.')
				count += 1;
		}
	}
	i = (board->h * board->w - 2);
	if (count_O != 1 || count_X != 1 || count != (board->h * board->w - 2))
	{
		free_game(board, board, (t_player *)board);
		return (-1);
	}
	return (0);
}

t_game		*get_board(t_game *board, char **line)
{
	if (!board)
		board = init_game(board);
	if(get_size(board, line) == -1)
		return (NULL);
	//ft_strdel(line);
	// on jump la ligne 0123456789
	gnl(0, line);
	return (game_loop(board, line));
}
