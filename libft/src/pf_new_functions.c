/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_new_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:18:25 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:21 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_pars(const char *str, int i)
{
	int		len;
	char	*dest;

	len = ft_strstringlen(&str[i], FLAGS);
	if (!(dest = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	return (dest);
}

int		get_option(t_flag *flag, int i)
{
	if (flag->option != NULL)
		flag->option = ft_strjoin(flag->option,\
			pf_catch_option(flag->parsing, i, flag->option));
	else
		flag->option = pf_catch_option(flag->parsing, i, flag->option);
	while (ft_chrchar(flag->parsing[i + 1], OPTIONS) == 1)
		i++;
	return (i);
}

int		get_field(t_flag *flag, int i, va_list list)
{
	flag->field = pf_catch_field(flag->parsing, i, list);
	while ((flag->parsing[i + 1] >= '0' && flag->parsing[i + 1] <= '9')
	|| flag->parsing[i + 1] == '*')
		i++;
	return (i);
}

int		get_precision(t_flag *flag, int i, va_list list)
{
	flag->precision = pf_catch_precision(flag->parsing, i, list);
	i += 1;
	while ((flag->parsing[i + 1] >= '0' && flag->parsing[i + 1] <= '9')
	|| flag->parsing[i + 1] == '*')
		i++;
	return (i);
}

char	*particular_case(const char *str, int i)
{
	char	*res;
	int		j;
	int		len;

	j = 0;
	len = ft_strstringlen(&str[i], OTHER2) + 1;
	if (len == 1)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (j < len)
		res[j++] = str[i++];
	return (res);
}
