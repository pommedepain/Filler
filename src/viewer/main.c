/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:35:07 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/30 15:19:19 by psentilh         ###   ########.fr       */
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
	t_viewer	*viewer;
	int			fd;
	char		*line;

	viewer = NULL;
	line = NULL;
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
		dprintf(fd, "Fail gnl ou parse player\n");
		return (-1);
	}
	ft_strdel(&line);
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
		ft_strdel(&line);
	}
	dprintf(fd, "main 3 line = %s\n", line);
	ft_strdel(&line);
	free_viewer(viewer, fd);
	dprintf(fd, "End of viewer\n");
	return (0);
}
