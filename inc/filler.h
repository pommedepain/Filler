/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:55 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/19 15:25:46 by psentilh         ###   ########.fr       */
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
	int		nb;
	int		y;
	int		x;
	char	id;
	char	id_enmy;
}					t_player;

/*
** board.c
*/
int			check_count_board(t_game *board, char *str);
int			check_first_board(t_game *board);
t_game		*get_board(t_game *board, char *line);

/*
** piece.c
*/
void		get_size_sign(t_game *game);
t_game		*get_piece(t_game *piece, char *line);

/*
** parsing.c
*/
int			game_malloc(t_game *game);
int			get_size(t_game *game, char **line);
t_game		*game_loop(t_game *game);

/*
** solve.c
*/
int			*find_enmy(t_game *board, t_player *player, int *enmy, int beg);
int			solve(t_game *board, t_game *piece, t_player *player);

/*
** utils.c
*/
void		free_bp(t_game *board, t_player *player);
void		free_game(t_game *board, t_game *piece, t_player *player);
t_game		*init_game(t_game *game);
t_player	*init_player(t_player *player);

#endif
