/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:11:58 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/09 14:44:24 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_viewer	*free_viewer(t_viewer *viewer)
{
	int i;

	if (viewer)
	{
		if (viewer->visual)
		{
			i = -1;
			while (viewer->visual[++i])
				free(viewer->visual[i]);
		}
		free(viewer);
		viewer = NULL;
	}
	return (viewer);
}

void		ft_color_viewer(t_viewer *viewer)
{
	init_pair(1, 2, 0);
	init_pair(2, 1, 0);
	init_pair(3, 7, 0);
	wattron(viewer->ptr, A_BOLD);
}

int			print_viewer(t_viewer *viewer)
{
	int			i;
	int			j;

	ft_color_viewer(viewer);
	i = -1;
	while (viewer->visual[++i])
	{
		j = -1;
		while (viewer->visual[i][++j])
		{
			if (viewer->visual[i][j] == 'o' || viewer->visual[i][j] == 'O')
			{
				wattron(viewer->ptr, COLOR_PAIR(1));
				mvwaddch(viewer->ptr, i + 1, j + 1, 'O');
				wrefresh(viewer->ptr);
			}
			if (viewer->visual[i][j] == 'x' || viewer->visual[i][j] == 'X')
			{
				wattron(viewer->ptr, COLOR_PAIR(2));
				mvwaddch(viewer->ptr, i + 1, j + 1, 'X');
				wrefresh(viewer->ptr);
			}
		}
	}
	return (0);
}

int			start_viewer(t_viewer *viewer)
{
	t_window	ptr_win;
	int			h;
	int			w;

	initscr();
	noecho();
	cbreak();
	ptr_win = newwin(viewer->h + 2, viewer->w + 2, 0, 0);
	refresh();
	start_color();
	init_pair(3, 7, 0);
	wborder(ptr_win, 0, 0, 0, 0, 0, 0, 0, 0);
	h = 0;
	while (++h < viewer->h + 1)
	{
		w = 0;
		while (++w < viewer->w + 1)
		{
			wattron(ptr_win, COLOR_PAIR(3));
			mvwaddch(ptr_win, h, w, '.');
			wrefresh(ptr_win);
		}
	}
	viewer->ptr = ptr_win;
	return (0);
}

int			end_viewer(t_viewer *viewer)
{
	endwin();
	viewer->status = 3;
	return (0);
}
