/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:27:44 by psentilh          #+#    #+#             */
/*   Updated: 2019/05/02 13:35:31 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				viewer_malloc(t_viewer *viewer)
{
	int i;

	if (!(viewer->visual =
	(char **)ft_memalloc(sizeof(char *) * (viewer->h + 1))))
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

int				get_size_v(t_viewer *viewer, char *line)
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
	if (viewer_malloc(viewer) == -1)
	{
		free_viewer(viewer);
		return (-1);
	}
	ft_strdel(&line);
	return (0);
}

t_viewer		*viewer_loop(t_viewer *viewer, char **line)
{
	int i;
	int j;

	i = -1;
	while (++i < viewer->h)
	{
		ft_strdel(line);
		if (get_next_line(0, line) != 1)
			return (free_viewer(viewer));
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
	return (viewer);
}

int				find_board(t_viewer *viewer, char **line)
{
	if (!*line)
		return (-1);
	while (!ft_strstr(*line, "Plateau "))
	{
		ft_strdel(line);
		if (!get_next_line(0, line))
			return (-1);
		if (ft_strstr(*line, "Plateau "))
			break ;
		if (ft_strstr(*line, "fin: "))
		{
			ft_strdel(line);
			viewer->status = 1;
			return (1);
		}
	}
	if (get_size_v(viewer, *line) == -1)
		return (-1);
	if (!get_next_line(0, line))
		return (-1);
	ft_strdel(line);
	return (0);
}

t_viewer		*get_visual(t_viewer *viewer, char **line)
{
	int		ret;

	ret = 0;
	if (!get_next_line(0, line))
		return (NULL);
	if (viewer->visual != NULL)
	{
		print_viewer(viewer);
		ft_tabdel(viewer->visual);
		viewer->visual = NULL;
	}
	if ((ret = find_board(viewer, line)) == -1)
	{
		if (*line)
			ft_strdel(line);
		return (NULL);
	}
	if (viewer->status == -1)
	{
		start_viewer(viewer);
		viewer->status = 2;
	}
	if (ret == 1)
		return (viewer);
	return (viewer_loop(viewer, line));
}
