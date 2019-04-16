/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:55 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/16 20:04:51 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_game
{
	char	**form;
	int		h;
	int		w;
	int		size;
}					t_game;

typedef struct		s_player
{
	char	*name;
	int		nb;
	char	id;
	char	id_enmy;
}					t_player;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

/*
** board.c
*/
int			check_count_board(t_game *board, char *str);
int			check_first_board(t_game *board);
int			get_board(t_game *board, char *line);

/*
** piece.c
*/
void		get_size_sign(t_game *game);
t_game		*parse_piece(t_game *piece);
int			get_piece(t_game *piece/*, char *line*/);

/*
** parsing.c
*/
int			game_malloc(t_game *game);
int			get_size(t_game *game);
t_game		*game_loop(t_game *game);

/*
** place.c
*/
t_point		*choose_place_board(t_game *board, t_game *piece, t_player *player, t_point *point);

/*
** utils.c
*/
void		free_bp(t_game *board, t_player *player);
void		free_game(t_game *board, t_game *piece, t_player *player);
t_game		*init_game(t_game *game);
t_player	*init_player(t_player *player);
t_point		*new_point(int x, int y);

#endif
