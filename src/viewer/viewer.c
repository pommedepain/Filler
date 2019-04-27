/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:35:07 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/27 18:34:48 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_viewer	*init_viewer(t_viewer *viewer)
{
	if (!(viewer = (t_viewer *)ft_memalloc(sizeof(t_viewer))))
		return (NULL);
	viewer->h = -1;
	viewer->w = -1;
	viewer->p1 = 0;
	viewer->p2 = 0;
	viewer->over = -1;
	return (viewer);
}

t_viewer	*free_viewer(t_viewer *viewer, int fd)
{
	int i;

	if (viewer)
	{
		if (viewer->visual)
		{
			i = -1;
			//ft_tabdel(viewer->visual);
			while (viewer->visual[++i])
				free(viewer->visual[i]);
		}
		free(viewer);
		viewer = NULL;
		dprintf(fd, "free viewer\n");
	}
	return (viewer);
}

t_viewer	*begin_vm(t_viewer *viewer, char **line, int fd)
{
	if (!*line)
	{
		dprintf(fd, "begin_vm, line == NULL\n");
		return (NULL);
	}
	while (!ft_strstr(*line, "$$$ exec p"))
	{
		ft_strdel(line);
		get_next_line(0, line);
		//dprintf(fd, "line = %s\n", *line);
		//dprintf(fd, "char[10] = %c\n", (*line)[10]);
		if ((*line)[10] == '1')
		{
			viewer->p1 = ((*line)[10] == '1' ? 'O' : 'X');
			viewer->p2 = ((*line)[10] == '1' ? 'X' : 'O');
			return (viewer);
		}
	}
	dprintf(fd, "begin_vm, if doesn't work\n");
	ft_strdel(line);
	return (NULL);
}

int			main(void)
{
	//WINDOW		*ptr_win;
	t_viewer	*viewer;
	int			fd;
	char		*line;

	viewer = NULL;
	if (!(fd = open("test_viewer", O_WRONLY | O_CREAT, 0644)))
		return (-1);
	dprintf(fd, "test\n");
	if (!(viewer = init_viewer(viewer)))
	{
		dprintf(fd, "FAIL init_viewer\n");
		return (-1);
	}
	if (get_next_line(0, &line) != 1 || !(viewer = begin_vm(viewer, &line, fd)))
	{
		ft_strdel(&line);
		dprintf(fd, "Fail gnl ou parse player\n");
		return (-1);
	}
	dprintf(fd, "main 1 line = %s\n", line);
	ft_strdel(&line);
	dprintf(fd, "main 2 line = %s\n", line);
	dprintf(fd, "\nMain, success	p1 = %c\n				p2 = %c\n", viewer->p1, viewer->p2);
	while (1)
	{
		if (!(viewer = get_visual(viewer, &line, fd)))
		{
			dprintf(fd, "fail get_visual\n");
			break ;
		}
		if (viewer->over == 1)
			break ;
		//ft_tabdel(viewer->visual);
		ft_strdel(&line);
	}
	/*initscr();
	cbreak();
	ptr_win = newwin(20, 30, 10, 40);
	refresh();
	start_color();
	init_pair(1, 2, 0);
	wborder(ptr_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(ptr_win, COLOR_PAIR(1));
	wattron(ptr_win, A_BOLD);
	mvwprintw(ptr_win, 1, 1, "This is my box !");
	wrefresh(ptr_win);
	wattroff(ptr_win, COLOR_PAIR(1));
	wattroff(ptr_win, A_BOLD);
	getch();
	endwin();*/
	dprintf(fd, "main 3 line = %s\n", line);
	ft_strdel(&line);
	free_viewer(viewer, fd);
	dprintf(fd, "End of viewer\n");
	return (0);
}
