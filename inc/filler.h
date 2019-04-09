/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:55 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/09 16:13:53 by psentilh         ###   ########.fr       */
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

typedef struct		s_board
{
	char	**board;
	int		h;
	int		w;
}					t_board;

typedef struct		s_player
{
	char	*name;
	int		nb;
	char	id;
}					t_player;

t_board		*init_board(t_board *board);
t_board		*check_board(t_board *board, char **line);

#endif
