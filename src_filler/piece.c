/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:46:41 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/16 20:04:23 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_size_sign(t_game *game)
{
	int		nb;
	int		i;
	int		j;

	nb = 0;
	i = 0;
	while (game->form[i])
	{
		j = 0;
		while (game->form[i][j++])
			if (game->form[i][j] == '*')
				nb++;
		i++;
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

int			get_piece(t_game *piece/*, char *line*/)
{
	piece = init_game(piece);
	piece = parse_piece(piece);
	get_size_sign(piece);
	//ft_strdel(line);
	return (0);
}
