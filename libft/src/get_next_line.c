/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:34:40 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/15 17:05:16 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_lf(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		check_input(int fd, char **line, char *lst[_FD_MAX_])
{
	if (fd < 0 || fd >= _FD_MAX_)
		return (0);
	if (!line)
		return (0);
	if (read(fd, *line, 0) < 0)
		return (0);
	if (!lst[fd])
	{
		if (!(lst[fd] = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (0);
	}
	return (1);
}

int		checkend(int ret, int fd, char *lst[_FD_MAX_], char **line)
{
	if (ret == -1)
	{
		ft_strdel(line);
		ft_strdel(&lst[fd]);
		return (-1);
	}
	if (lst[fd][0])
	{
		ft_strclr(lst[fd]);
		return (1);
	}
	ft_strdel(line);
	ft_strdel(&lst[fd]);
	return (0);
}

int		process(int fd, int ret, char **line, char *lst[_FD_MAX_])
{
	lst[fd][ret] = '\0';
	*line = ft_strjoinfs1(*line, lst[fd]);
	lst[fd] = ft_strcpy(lst[fd], &lst[fd][ret + 1]);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*lst[_FD_MAX_];
	int				ret;

	if (!check_input(fd, line, lst))
		return (-1);
	*line = NULL;
	if ((ret = find_lf(lst[fd])) >= 0)
		return (process(fd, ret, line, lst));
	*line = ft_strjoinfs1(*line, lst[fd]);
	while ((ret = read(fd, lst[fd], BUFF_SIZE)) > 0)
	{
		lst[fd][ret] = '\0';
		if ((ret = find_lf(lst[fd])) >= 0)
			return (process(fd, ret, line, lst));
		*line = ft_strjoinfs1(*line, lst[fd]);
	}
	return (checkend(ret, fd, lst, line));
}
