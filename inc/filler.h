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
int				check_count_board(t_game *board, char *str);
int				check_first_board(t_game *board);
t_game			*get_board(t_game *board, char **line);

/*
** piece.c
*/
void			get_size_sign(t_game *game);
t_game			*get_piece(t_game *piece, char **line);

/*
** parsing.c
*/
int				game_malloc(t_game *game);
int				get_size(t_game *game, char *line);
t_game			*game_loop(t_game *game, char **line);

/*
** solve.c
*/
int				solve(t_game *board, t_game *piece, t_player *player);

/*
** utils.c
*/
t_game			*free_game(t_game *board);
t_player		*free_player(t_player *player);
char			*free_line(char *line);
void			free_prog(t_game **board, t_game **piece, t_player **player, char **line);
t_game			*init_game(t_game *game);
t_player		*init_player(t_player *player);

/*
**						VIEWER:
*/

/*
** parsing.c
*/
t_viewer		*get_visual(t_viewer *viewer, char **line, int fd);
t_viewer		*free_viewer(t_viewer *viewer, int fd);
int				start_viewer(t_viewer *viewer, int fd);
int				print_viewer(t_viewer *viewer, int fd);
int				end_viewer(t_viewer	*viewer, int fd);

#endif
