/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:23:14 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/11 18:01:28 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_size(t_game *game)
{
	int i;
	int nb;
	char *line;

	i = 0;
	nb = 0;
	line = NULL;
	if (get_next_line(0, &line) != 1 || (!ft_strncmp(line, "Plateau ", 9) || !ft_strncmp(line, "Piece ", 7)))
		return (-1);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i++] - 48);
	game->h = nb;
	nb = 0;
	while (line[++i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i] - 48);
	game->w = nb;
	ft_printf("\nh = %d\nw = %d\n", game->h, game->w);
	if (game_malloc(game) == -1)
		return (-1);
	return (0);
}

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
		//printf("Error = %d\n", count);
		return (-1);
	}
	//printf("right count = %d\n", i);
	return (0);
}

t_game		*game_loop(t_game *game)
{
	int i;
	char **tmp;

	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (game->h + 1))))
		return (NULL);
	tmp[game->h] = 0;
	i = 0;
	while (i < game->h)
	{
		if (!(tmp[i] = (char *)ft_memalloc(sizeof(char) * (game->w + 1))))
			return (NULL);
		i++;
	}
	tmp[game->h - 1][game->w] = '\0';
	i = -1;
	while (++i < game->h)
	{
		get_next_line(1, tmp);
		if (ft_char_only(tmp[0], '.', '*') == 0)
		{
			if (check_count_board(game, tmp[0]) == 0)
				ft_strccpy(game->form[i], tmp[0], ' ');
			else
			{
				//free_game(game);
				return (NULL);
			}
		}
		else
			ft_strcpy(game->form[i], tmp[0]);
	}
	ft_print_words_tables(game->form);
	ft_tabdel(tmp);
	return (game);
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
		//free_game(board);
		return (-1);
	}
	return (0);
}

void		parse_piece(void)
{
	t_game *piece;

	piece = NULL;
	piece = init_game(piece);
	get_size(piece);
	game_loop(piece);
}