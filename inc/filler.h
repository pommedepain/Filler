/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:55 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/25 16:46:28 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <ncurses.h>

typedef struct		s_game
{
	char	**form;
	int		h;
	int		w;
}					t_game;

typedef struct		s_player
{
	int		y;
	int		x;
	char	id;
}					t_player;

typedef struct		s_viewer
{
	int		h;
	int		w;
	char	player;
	char	enmy;
}					t_viewer;

/*
**							FILLER:
*/

/*
** board.c
*/
int			check_count_board(t_game *board, char *str);
int			check_first_board(t_game *board);
t_game		*get_board(t_game *board, char **line, int fd);

/*
** piece.c
*/
void		get_size_sign(t_game *game);
t_game		*get_piece(t_game *piece, char **line, int fd);

/*
** parsing.c
*/
int			game_malloc(t_game *game/*, int fd*/);
int			get_size(t_game *game, char *line, int fd);
t_game		*game_loop(t_game *game, char **line, int fd);

/*
** solve.c
*/
int			*find_enmy(t_game *board, t_player *player, int *enmy);
int			solve(t_game *board, t_game *piece, t_player *player, int fd);

/*
** utils.c
*/
t_game		*free_game(t_game *board, int fd);
t_player	*free_player(t_player *player, int fd);
char		*free_line(char *line, int fd);
void		free_prog(t_game **board, t_game **piece, t_player **player, char **line, int fd);
t_game		*init_game(t_game *game);
t_player	*init_player(t_player *player);

/*
**						VIEWER:
*/

#endif
