/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:55 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/09 14:44:13 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <ncurses.h>

typedef struct	s_game
{
	char	**form;
	char	**oform;
	int		h;
	int		w;
}				t_game;

typedef struct	s_player
{
	int		y;
	int		x;
	int		nb;
	char	id;
	char	enmy;
}				t_player;

typedef WINDOW*	t_window;

typedef struct	s_viewer
{
	char	**visual;
	int		h;
	int		w;
	char	p1;
	char	p2;
	int		status;
	WINDOW	*ptr;
}				t_viewer;

/*
**							FILLER:
*/

/*
** board.c
*/
t_game			*get_board(t_game *board, char **line);

/*
** piece.c
*/
t_game			*get_piece(t_game *piece, char **line);

/*
** parsing.c
*/
int				get_size(t_game *game, char *line);
t_game			*game_loop(t_game *game, char **line);

/*
** solve.c
*/
int				solve(t_game *board, t_game *piece, t_player *player);

/*
** utils.c
*/
void			*free_game(t_game *board);
void			*free_player(t_player *player);
void			*free_prog(t_game **board, t_game **piece, t_player **player,
				char **line);
t_player		*init_player(t_player *player);

/*
**						VIEWER:
*/
t_viewer		*get_visual(t_viewer *viewer, char **line);
t_viewer		*free_viewer(t_viewer *viewer);
int				start_viewer(t_viewer *viewer);
int				print_viewer(t_viewer *viewer);
int				end_viewer(t_viewer	*viewer);

#endif
