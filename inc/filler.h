/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:55 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/11 18:00:49 by psentilh         ###   ########.fr       */
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
}					t_game;

typedef struct		s_player
{
	char	*name;
	int		nb;
	char	id;
	char	id_enmy;
}					t_player;

/*
** main.c
*/
t_game		*init_game(t_game *game);
t_player	*init_player(t_player *player);
int			game_malloc(t_game *game);

/*
** parsing.c
*/
int			get_size(t_game *game);
int			check_count_board(t_game *board, char *str);
t_game		*game_loop(t_game *game);
int			check_first_board(t_game *board);
void		parse_piece(void);

#endif
