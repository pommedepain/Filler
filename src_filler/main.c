/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/09 18:28:46 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_board		*init_board(t_board *board)
{
	if (!(board = (t_board *)ft_memalloc(sizeof(t_board))))
		return (NULL);
	board->h = 0;
	board->w = 0;
	board->board = NULL;
	return (board);
}

t_player	*init_player(t_player *player)
{
	player->nb = 0;
	player->id = 0;
	player->name = NULL;
	return (player);
}

int			board_malloc(t_board *board)
{
	int i;

	i = 0;
	if (!(board->board = (char **)ft_memalloc(sizeof(char *) * (board->h + 1))))
		return (-1);
	while (i < (board->w - 1))
	{
		if (!(board->board[i] = (char *)ft_memalloc(sizeof(char) * (board->w + 1))))
			return (-1);
		i++;
	}
	board->board[board->h][board->w] = '\0';
	return (0);
}

int			get_size(t_board *board, char *line)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i++] - 48);
	board->h = nb;
	nb = 0;
	while (line[++i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i] - 48);
	board->w = nb;
	if (!board_malloc(board))
		return (-1);
	ft_printf("h = %d\nw = %d\n", board->h, board->w);
	return (0);
}

int			board_loop(t_board *board)
{
	int i;
	char **tmp;

	i = 0;
	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (board->h + 1))))
		return (-1);
	while (i < (board->w - 1))
	{
		if (!(tmp[i] = (char *)ft_memalloc(sizeof(char) * (board->w + 1))))
			return (-1);
		i++;
	}
	tmp[board->h][board->w] = '\0';
	i = 0;
	while (1)
	{
		get_next_line(1, tmp);
		ft_putendl(tmp[i]);
		ft_strccpy(board->board[i], tmp[i], '.');
		ft_putendl(board->board[i++]);
	}
	ft_print_words_tables(board->board);
	return (0);
}

int			main(void)
{
	t_board		*board;
	t_player	*player;
	char		*line;

	line = NULL;
	board = NULL;
	player = NULL;
	if (get_next_line(0, &line) && ft_strlens(line) > 10 && ft_strncmp(line, "$$$ exec p", 9) && (line[10] == '1' || line [10] == '2'))
	{
		player = init_player(player);
		player->id = (line[10] == '1' ? 'O' : 'X');
	}
	//ft_printf("player id  = %c\n", player->id);
	board = init_board(board);
	if (get_next_line(0, &line) != 1 || !ft_strstr(line, "Plateau "))
		return (-1);
	if(!get_size(board, line))
		return (-1);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	board_loop(board);
	/*if (get_next_line(0, &line))
		return (-1);*/
	/*if (!parsing(board, line))
	{
		//free_board(board);
		return (-1);
	}*/
	return (0);
}
