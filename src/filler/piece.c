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

t_game		*get_piece(t_game *piece, char **line)
{
	if (!(piece = (t_game *)ft_memalloc(sizeof(t_game))))
		return (NULL);
	if (!get_next_line(0, line) || !ft_strstr(*line, "Piece "))
		return (free_game(piece));
	get_size(piece, *line);
	ft_strdel(line);
	if (!(piece->form = (char **)ft_memalloc(sizeof(char *) * (piece->h + 1))))
		return (free_game(piece));
	return (game_loop(piece, line));
}
