/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:39:05 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/11 18:00:34 by psentilh         ###   ########.fr       */
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

int			main(void)
{
	t_game		*board;
	t_player	*player;
	char		*line;
	int i;

	line = NULL;
	board = NULL;
	player = NULL;
	if (get_next_line(0, &line) && ft_strlens(line) > 10 && ft_strncmp(line, "$$$ exec p", 11) && (line[10] == '1' || line [10] == '2'))
	{
		player = init_player(player);
		player->id = (line[10] == '1' ? 'O' : 'X');
		player->id_enmy = (line[10] == '1' ? 'X' : 'O');
	}
	board = init_game(board);
	if(get_size(board) == -1)
		return (-1);
	ft_strdel(&line);
	// on jump la ligne 0123456789
	get_next_line(0, &line);
	ft_strdel(&line);
	if (game_loop(board) == NULL)
	{
		//free_game(board);
		return (-1);
	}
	i = 0;
	if ((i = check_first_board(board) == -1))
	{
		//printf("Error i = %d\n", i);
		//free_game(board);
		return (-1);
	}
	//printf("Valid i = %d\n", i);
	parse_piece();
	return (0);
}
