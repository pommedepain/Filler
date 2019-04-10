/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:55 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/10 14:57:01 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define NUM 0123456789

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

t_game		*init_board(t_game *board);

#endif
