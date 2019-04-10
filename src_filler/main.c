/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/10 16:43:45 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game		*init_game(t_game *game)
{
	if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		return (NULL);
	game->h = 0;
	game->w = 0;
	game->form = NULL;
	return (game);
}

t_player	*init_player(t_player *player)
{
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	player->nb = 0;
	player->id = 0;
	player->name = NULL;
	return (player);
}

int			game_malloc(t_game *game)
{
	int i;

	if (!(game->form = (char **)ft_memalloc(sizeof(char *) * (game->h + 1))))
		return (-1);
	game->form[game->h] = 0;
	i = 0;
	while (i < game->h)
	{
		if (!(game->form[i] = (char *)ft_memalloc(sizeof(char) * (game->w + 1))))
			return (-1);
		i++;
	}
	game->form[game->h - 1][game->w] = '\0';
	return (0);
}

int			get_size(t_game *game)
{
	int i;
	int nb;
	char *line;

	i = 0;
	nb = 0;
	line = NULL;
	if (get_next_line(0, &line) != 1 || (!ft_strncmp(line, "Plateau ", 9) || !ft_strncmp(line, "Piece ", 7)))
	{
		ft_putendl("coucou");
		return (-1);
	}
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i++] - 48);
	game->h = nb;
	nb = 0;
	while (line[++i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i] - 48);
	game->w = nb;
	ft_printf("h = %d\nw = %d\n", game->h, game->w);
	if (game_malloc(game) == -1)
	{
		ft_putendl("coucou 2");
		return (-1);
	}
	return (0);
}

/*int		piece_loop(t_game *board)
{
	int		i;
	char	**tmp;

	get_size(board);
	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (board->piece_h + 1))))
		return (-1);
	tmp[board->piece_h] = 0;
	i = 0;
	while (i < board->piece_h)
	{
		if (!(tmp[i] = (char *)ft_memalloc(sizeof(char) * (board->piece_w + 1))))
			return (-1);
		i++;
	}
	tmp[board->piece_h - 1][board->piece_w] = '\0';
	i = 0;
	while (i < board->piece_h)
	{
		get_next_line(1, tmp);
		ft_strccpy(board->piece[i], tmp[0], ' ');
		i++;
	}
	ft_print_words_tables(board->piece);
}*/

t_game		*game_loop(t_game *game)
{
	int i;
	int k;
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
	k = 0;
	while (++i < game->h)
	{
		printf("i = %d\n", i);
		printf("k = %d\n", (k = get_next_line(1, tmp)));
		/*{
			ft_putendl("oups");
			return (NULL);
		}*/
		if (ft_char_only(tmp[0], '.', '*') == 0)
			ft_strccpy(game->form[i], tmp[0], ' ');
		else
		{
			ft_putendl(tmp[0]);
			ft_strcpy(game->form[i], tmp[0]);
		}
	}
	ft_print_words_tables(game->form);
	//free(tmp);
	return (game);
}

int			main(void)
{
	t_game		*board;
	t_game		*piece;
	t_player	*player;
	char		*line;

	line = NULL;
	board = NULL;
	player = NULL;
	piece = NULL;
	if (get_next_line(0, &line) && ft_strlens(line) > 10 && ft_strncmp(line, "$$$ exec p", 11) && (line[10] == '1' || line [10] == '2'))
	{
		player = init_player(player);
		player->id = (line[10] == '1' ? 'O' : 'X');
		player->id_enmy = (line[10] == '1' ? 'X' : 'O');
	}
	printf("\nplayer id = %c\nplayer id_enmy = %c\n", player->id, player->id_enmy);
	board = init_game(board);
	if(get_size(board) == -1)
		return (-1);
	ft_strdel(&line);
	// on jump la ligne 0123456789
	get_next_line(0, &line);
	ft_strdel(&line);
	game_loop(board);
	piece = init_game(piece);
	if (get_size(piece) == -1)
		return (-1);
	//on jump la ligne Piece
	get_next_line(0, &line);
	ft_strdel(&line);
	game_loop(piece);
	return (0);
}
