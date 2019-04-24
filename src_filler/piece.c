/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:46:41 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/24 16:43:13 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*void		get_size_sign(t_game *game)
{
	int		nb;
	int		i;
	int		j;

	nb = 0;
	i = -1;
	while (game->form[++i])
	{
		j = -1;
		while (game->form[i][++j])
			if (game->form[i][j] == '*')
				nb++;
	}
	game->size = nb;
}*/

t_game		*get_piece(t_game *piece, char **line, int fd)
{
	if (!(piece = init_game(piece)))
		return (NULL);
	if (!get_next_line(0, line) || !ft_strstr(*line, "Piece "))
	{
		dprintf(fd, "\nGet_piece, strstr failed : %s\n", *line);
		return (NULL);
	}
	dprintf(fd, "\nGet_size, Piece =");
	if (get_size(piece, *line, fd) == -1)
	{
		dprintf(fd, "Get_size failed\n");
		return (NULL);
	}
	return (game_loop(piece, line, fd));
}
