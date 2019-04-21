/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:23:14 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/21 18:52:40 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			game_malloc(t_game *game)
{
	//int i;

	if (!(game->form = (char **)ft_memalloc(sizeof(char *) * (game->h + 1))))
		return (-1);
	game->form[game->h] = 0;
	/*i = -1;
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
	game->form[game->h - 1][game->w] = '\0';*/
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
		gnl(0, line);
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
	ft_printf("\nh = %d\nw = %d\n", game->h, game->w);
	if (game_malloc(game) == -1)
	{
		ft_tabdel(game->form);
		ft_strdel(line);
		return (-1);
	}
	//ft_strdel(line);
	return (0);
}

t_game		*game_loop(t_game *game, char **line)
{
	int i;
	int j;

	i = -1;
	while (++i < game->h)
	{
		if (!game->form[i])
			if (!(game->form[i] = ft_strnew(game->w)))
				return (NULL);
		get_next_line(0, line);
			//return (NULL);
		if (ft_char_only(line[0], '.', '*') == 0)
		{
			j = 4;
			while (j - 4 < game->w)
			{
				game->form[i][j - 4] = (*line)[j];
				j++;
			}
		}
		else
		{
			j = 0;
			while (j < game->w)
			{
				game->form[i][j] = (*line)[j];
				j++;
			}
		}
		//ft_strdel(line);
	}
	ft_print_words_tables(game->form);
	//ft_tabdel(line);
	return (game);
}
