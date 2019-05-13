/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:35:07 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/02 13:34:11 by psentilh         ###   ########.fr       */
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
	viewer->status = -1;
	viewer->ptr = NULL;
	return (viewer);
}

t_viewer	*begin_vm(t_viewer *viewer, char **line)
{
	if (!*line)
		return (NULL);
	while (!ft_strstr(*line, "$$$ exec p"))
	{
		ft_strdel(line);
		if (get_next_line(0, line) != 1)
			return (NULL);
		if ((*line)[10] == '1')
		{
			viewer->p1 = ((*line)[10] == '1' ? 'O' : 'X');
			viewer->p2 = ((*line)[10] == '1' ? 'X' : 'O');
			return (viewer);
		}
	}
	ft_strdel(line);
	return (NULL);
}

int			viewer_error(char *str, t_viewer *viewer)
{
	if (str)
	{
		ft_putendl_fd(str, 2);
		return (1);
	}
	if (viewer)
	{
		free_viewer(viewer);
		return (1);
	}
	return (0);
}

int			begin_viewer(t_viewer *viewer, char *line, int indice)
{
	if (indice == 1)
	{
		if (!get_next_line(0, &line) || !(viewer = begin_vm(viewer, &line)))
		{
			viewer_error("A problem occured with the players/board", viewer);
			return (-1);
		}
		ft_strdel(&line);
		return (1);
	}
	if (indice == 2)
	{
		if (end_viewer(viewer) == -1)
		{
			viewer_error("A problem occured while ending the viewer", viewer);
			return (-1);
		}
		ft_strdel(&line);
		free_viewer(viewer);
		return (1);
	}
	return (1);
}

int			main(void)
{
	t_viewer	*viewer;
	char		*line;

	viewer = NULL;
	line = NULL;
	if (!(viewer = init_viewer(viewer)))
		return (viewer_error("A problem occured", viewer) == 1 ? -1 : -1);
	if (begin_viewer(viewer, line, 1) == -1)
		return (-1);
	while (1)
	{
		if (!(viewer = get_visual(viewer, &line)))
		{
			viewer_error("A problem occured while parsing the board", viewer);
			return (-1);
		}
		if (viewer->status == 1)
			break ;
		ft_strdel(&line);
	}
	if (begin_viewer(viewer, line, 2) == -1)
		return (-1);
	return (0);
}
