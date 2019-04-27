/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:27:44 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/27 18:12:47 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			viewer_malloc(t_viewer *viewer)
{
	int i;

	if (!(viewer->visual = (char **)ft_memalloc(sizeof(char *) * (viewer->h + 1))))
		return (-1);
	viewer->visual[viewer->h] = 0;
	i = -1;
	while (++i < viewer->h)
	{
		if (!(viewer->visual[i] = ft_strnew(viewer->w)))
			return (-1);
	}
	viewer->visual[viewer->h - 1][viewer->w] = '\0';
	return (0);
}

int			get_size_v(t_viewer *viewer, char *line, int fd)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i++] - 48);
	viewer->h = nb;
	nb = 0;
	while (line[++i] && ft_isdigit(line[i]))
		nb = nb * 10 + (line[i] - 48);
	viewer->w = nb;
	if (viewer->h == -1 || viewer->w == -1)
		return (-1);
	dprintf(fd, "\nh = %d\nw = %d\n\n", viewer->h, viewer->w);
	if (viewer_malloc(viewer) == -1)
	{
		dprintf(fd, "viewer_malloc failed\n");
		ft_strdel(&line);
		free_viewer(viewer, fd);
		return (-1);
	}
	ft_strdel(&line);
	return (0);
}

t_viewer		*viewer_loop(t_viewer *viewer, char **line, int fd)
{
	int i;
	int j;

	i = -1;
	while (++i < viewer->h)
	{
		ft_strdel(line);
		if (get_next_line(0, line) != 1)
		{
			dprintf(fd, "viewer_loop, get_next_line failed\n");
			return (free_viewer(viewer, fd));
		}
		//dprintf(fd, "viewer_loop, get_next_line %d = %s\n", i, (*line));
		if (ft_char_only(*line, '.', '*') == 0)
		{
			j = 4;
			while (j - 4 < viewer->w)
			{
				viewer->visual[i][j - 4] = (*line)[j];
				j++;
			}
		}
	}
	i = -1;
	while (++i < viewer->h)
		dprintf(fd, "viewer_loop, viewer->visual %d	=	%s\n", i, viewer->visual[i]);
	ft_tabdel(viewer->visual);
	viewer->visual = NULL;
	return (viewer);
}

int			find_board(t_viewer *viewer, char **line, int fd)
{
	if (!*line)
	{
		dprintf(fd, "find_board, line == NULL\n");
		return (-1);
	}
	while (!ft_strstr(*line, "Plateau "))
	{
		ft_strdel(line);
		get_next_line(0, line);
		dprintf(fd, "line = %s\n", *line);
		if (ft_strstr(*line, "Plateau "))
		{
			//dprintf(fd, "get_visual, Found \"Plateau \"");
			break ;
		}
		if (ft_strstr(*line, "fin: "))
		{
			viewer->over = 1;
			ft_strdel(line);
			dprintf(fd, "GAME OVER\n");
			return (1);
		}
		//ft_strdel(line);
	}
	dprintf(fd, "\nGet_size, Board =");
	if (get_size_v(viewer, *line, fd) == -1)
	{
		ft_strdel(line);
		free_viewer(viewer, fd);
		dprintf(fd, "Get_size, fail = %s\n", *line);
		return (-1);
	}
	if (!get_next_line(0, line))
		return (-1);
	dprintf(fd, "get_visual line we jump = %s\n\n", (*line));
	ft_strdel(line);
	return (0);
}

t_viewer		*get_visual(t_viewer *viewer, char **line, int fd)
{
	int ret;

	ret = 0;
	ft_strdel(line);
	if (!get_next_line(0, line))
	{
		dprintf(fd, "get_visual, gnl failed\n");
		return (NULL);
	}
	if ((ret = find_board(viewer, line, fd)) == -1)
	{
		if (*line)
			ft_strdel(line);
		free_viewer(viewer, fd);
		return (NULL);
	}
	if (ret == 1)
	{
		ft_strdel(line);
		dprintf(fd, "get_visual, line = %s\n", *line);
		return (viewer);
	}
	ft_strdel(line);
	return (viewer_loop(viewer, line, fd));
}
