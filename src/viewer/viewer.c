/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:11:58 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/30 17:11:04 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// Tenter de starter le viewer avec l'initialisation de la map, comme ça le fond reste fixe comme le cadre; puis entre chaque map, parser uniquement les X et O
// == pas de saut d'image sur la map, uniquement sur les pieces mais ne se verra pas

int			print_viewer(t_viewer *viewer, WINDOW *ptr_win, int fd)
{
	int			i;
	int			j;
	int			h;
	int			w;
	
	start_color();
	init_pair(1, 2, 0);
	init_pair(2, 1, 0);
	init_pair(3, 7, 0);
	wattron(ptr_win, A_BOLD);
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
				wattron(ptr_win, COLOR_PAIR(1));
				mvwaddch(ptr_win, h, w, viewer->visual[i][j]);
				wrefresh(ptr_win);
				dprintf(fd, "%c", viewer->visual[i][j]);
			}
			if (viewer->visual[i][j] == 'x' || viewer->visual[i][j] == 'X')
			{
				wattron(ptr_win, COLOR_PAIR(2));
				mvwaddch(ptr_win, h, w, viewer->visual[i][j]);
				wrefresh(ptr_win);
				dprintf(fd, "%c", viewer->visual[i][j]);
			}
			/*else if (viewer->visual[i][j] == '.')
			{
				wattron(ptr_win, COLOR_PAIR(3));
				mvwaddch(ptr_win, h, w, viewer->visual[i][j]);
				wrefresh(ptr_win);
				dprintf(fd, "%c", viewer->visual[i][j]);
			}*/
			j++;
			w++;
		}
		dprintf(fd, "\n");
		i++;
		h++;
	}
	wattroff(ptr_win, COLOR_PAIR(1));
	wattroff(ptr_win, A_BOLD);
	getch();
	return (0);
}

WINDOW		*start_viewer(t_viewer *viewer, int fd)
{
	WINDOW		*ptr_win;
	int			h;
	int			w;

	initscr();
	cbreak();
	ptr_win = newwin(viewer->h + 2, viewer->w + 2, 1, 1);
	refresh();
	start_color();
	init_pair(3, 7, 0);
	wborder(ptr_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(ptr_win, COLOR_PAIR(1));
	//wattron(ptr_win, A_BOLD);
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
	wattroff(ptr_win, A_BOLD);
	getch();
	endwin();
	return (ptr_win);
}
