/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:23:14 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/19 18:14:00 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			game_malloc(t_game *game)
{
	int i;

	if (!(game->form = (char **)ft_memalloc(sizeof(char *) * (game->h + 1))))
		return (-1);
	game->form[game->h] = 0;
	i = -1;
	while (++i < game->h)
	{
		if (!(game->form[i] = (char *)ft_memalloc(sizeof(char) * (game->w + 1))))
		{
			ft_tabdel(game->form);
			free(game);
			game = NULL;
			return (-1);
		}
	}
	game->form[game->h - 1][game->w] = '\0';
	return (0);
}

int			get_size(t_game *game, char **line)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (!ft_strstr(*line, "Plateau ") && !ft_strstr(*line, "Piece "))
	{
		if (ft_strstr(*line, "Plateau ") && !ft_strstr(*line, "Piece "))
			break ;
		get_next_line(0, line);
	}
	while ((*line)[i] && !ft_isdigit((*line)[i]))
		i++;
	while ((*line)[i] && ft_isdigit((*line)[i]))
		nb = nb * 10 + ((*line)[i++] - 48);
	game->h = nb;
	nb = 0;
	while ((*line)[++i] && ft_isdigit((*line)[i]))
		nb = nb * 10 + ((*line)[i] - 48);
	game->w = nb;
	//ft_printf("\nh = %d\nw = %d\n", game->h, game->w);
	if (game_malloc(game) == -1)
	{
		ft_tabdel(game->form);
		ft_strdel(line);
		return (-1);
	}
	ft_strdel(line);
	return (0);
}

t_game		*game_loop(t_game *game)
{
	int i;
	char **tmp;

	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (game->h + 1))))
		return (NULL);
	//ft_bzero(*tmp, (game->h + 1));
	tmp[game->h] = 0;
	i = -1;
	while (++i < game->h)
	{
		if (!(tmp[i] = (char *)malloc(sizeof(char) * (game->w + 1))))
		{
			ft_tabdel(tmp);
			return (NULL);
		}
		ft_bzero(tmp[i], (game->w + 1));
	}
	tmp[game->h - 1][game->w] = '\0';
	i = -1;
	while (++i < game->h)
	{
		printf("i = %d\ngame de h = %d\n", i, game->h);
		if (i == (game->h - 1))
		{
			if (ft_char_only(tmp[0], '.', '*') == 1)
				read(1, tmp[0], 1024);
		}
		else
			if (get_next_line(1, tmp) != 1)
				return (NULL);
		printf("Yo 2\n");
		if (ft_char_only(tmp[0], '.', '*') == 0)
		{
			if (check_count_board(game, tmp[0]) == 0)
				ft_strccpy(game->form[i], tmp[0], ' ');
			else
			{
				ft_tabdel(game->form);
				free(game);
				game = NULL;
				return (NULL);
			}
		}
		else
			ft_strcpy(game->form[i], tmp[0]);
		ft_strdel(tmp);
	}
	//ft_print_words_tables(game->form);
	ft_tabdel(tmp);
	printf("Yo 3\n");
	return (game);
}
