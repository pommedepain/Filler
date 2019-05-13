/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:23:14 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/24 16:46:03 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_size(t_game *game, char *line)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i++] - 48);
	game->h = nb;
	nb = 0;
	while (line[++i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i] - 48);
	game->w = nb;
	if (game->h == -1 || game->w == -1)
		return (-1);
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
				return (free_game(game));
		if (get_next_line(0, line) != 1)
			return (free_game(game));
		j = 3;
		if (ft_char_only(*line, '.', '*') == 0)
			while (++j - 4 < game->w)
				game->form[i][j - 4] = (*line)[j];
		else
		{
			j = -1;
			while (++j < game->w)
				game->form[i][j] = (*line)[j];
		}
		ft_strdel(line);
	}
	return (game);
}
