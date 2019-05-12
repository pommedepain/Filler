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
	if (!(piece = init_game(piece)))
		return (NULL);
	if (!get_next_line(0, line) || !ft_strstr(*line, "Piece "))
		return (NULL);
	if (get_size(piece, *line) == -1)
		return (NULL);
	return (game_loop(piece, line));
}
