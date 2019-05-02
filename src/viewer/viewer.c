/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:11:58 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/02 13:36:40 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// Tenter de starter le viewer avec l'initialisation de la map, comme ça le fond reste fixe comme le cadre; puis entre chaque map, parser uniquement les X et O
// == pas de saut d'image sur la map, uniquement sur les pieces mais ne se verra pas

int			print_viewer(t_viewer *viewer, int fd)
{
	int			i;
	int			j;
	int			h;
	int			w;
	
	init_pair(1, 2, 0);
	init_pair(2, 1, 0);
	init_pair(3, 7, 0);
	wattron(viewer->ptr, A_BOLD);
	h = 1;
	dprintf(fd, "\nPRINT VIEWER:\n");
	i = 0;
	while (viewer->visual[i])
	{
		j = 0;
		w = 1;
		while (viewer->visual[i][j])
		{
			if (viewer->visual[i][j] == 'o' || viewer->visual[i][j] == 'O')
			{
				wattron(viewer->ptr, COLOR_PAIR(1));
				mvwaddch(viewer->ptr, h, w, 'O');
				wrefresh(viewer->ptr);
				dprintf(fd, "%c", viewer->visual[i][j]);
			}
			if (viewer->visual[i][j] == 'x' || viewer->visual[i][j] == 'X')
			{
				wattron(viewer->ptr, COLOR_PAIR(2));
				mvwaddch(viewer->ptr, h, w, 'X');
				wrefresh(viewer->ptr);
				dprintf(fd, "%c", viewer->visual[i][j]);
			}
			j++;
			w++;
		}
		dprintf(fd, "\n");
		i++;
		h++;
	}
	wattroff(viewer->ptr, COLOR_PAIR(2));
	wattroff(viewer->ptr, COLOR_PAIR(1));
	wattroff(viewer->ptr, A_BOLD);
	wrefresh(viewer->ptr);
	return (0);
}

int			start_viewer(t_viewer *viewer, int fd)
{
	WINDOW		*ptr_win;
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
	h = 1;
	dprintf(fd, "\nSTART VIEWER:\n");
	while (h < viewer->h + 1)
	{
		w = 1;
		while (w < viewer->w + 1)
		{
			wattron(ptr_win, COLOR_PAIR(3));
			mvwaddch(ptr_win, h, w, '.');
			wrefresh(ptr_win);
			dprintf(fd, "%c", '.');
			w++;
		}
		dprintf(fd, "\n");
		h++;
	}
	dprintf(fd, "\n\n");
	wattroff(ptr_win, COLOR_PAIR(1));
	viewer->ptr = ptr_win;
	return (0);
}

int			end_viewer(t_viewer	*viewer, int fd)
{
	int ch;

	dprintf(fd, "END of viewer\n");
	ch = getch();
	endwin();
	viewer->status = 3;
	return (0);
}
