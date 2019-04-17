/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:46:41 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/17 16:01:56 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_size_sign(t_game *game)
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
}

t_game		*parse_piece(t_game *piece)
{
	get_size(piece);
	if (game_loop(piece) == NULL)
	{
		free_game(piece, piece, (t_player *)piece);
		return(NULL);
	}
	return (piece);
}

t_game		*get_piece(t_game *piece/*, char *line*/)
{
	piece = init_game(piece);
	piece = parse_piece(piece);
	get_size_sign(piece);
	//ft_strdel(line);
	return (piece);
}
