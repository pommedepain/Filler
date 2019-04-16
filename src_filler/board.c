/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:40:59 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/16 19:56:47 by psentilh         ###   ########.fr       */
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
		//printf("Error = %d\n", count);
		return (-1);
	}
	//printf("right count = %d\n", i);
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
	//printf("\nright nb . = %d\n", i);
	//printf("count = %d\ncount O = %d\ncount X = %d\n", count, count_O, count_X);
	if (count_O != 1 || count_X != 1 || count != (board->h * board->w - 2))
	{
		free_game(board, board, (t_player *)board);
		return (-1);
	}
	return (0);
}

int			get_board(t_game *board, char *line)
{
	board = init_game(board);
	if(get_size(board) == -1)
		return (-1);
	ft_strdel(&line);
	// on jump la ligne 0123456789
	get_next_line(0, &line);
	ft_strdel(&line);
	if (game_loop(board) == NULL)
		return (-1);
	return (0);
}
