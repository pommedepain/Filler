/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:54 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 16:14:20 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Main Function: initialise va_list, call reading_format and return
** result as the number of character print during the call
*/

int		ft_printf(const char *format, ...)
{
	va_list list;
	int		result;

	va_start(list, format);
	result = pf_manager(format, list);
	va_end(list);
	return (result);
}

int		pf_manager(const char *format, va_list ap)
{
	int pos;
	int printed;

	pos = 0;
	printed = 0;
	while (format[pos])
	{
		if ((format[pos] == '%') && (check_format(&format[pos]) == 1
		|| check_format2(&format[pos]) == 1))
			printed += ft_parsing(format, &pos, ap);
		if (format[pos] != '%')
			printed += pf_str_manager(format, &pos);
		else if ((format[pos] == '%') && (check_format(&format[pos]) != 1
		&& check_format2(&format[pos]) != 1))
		{
			ft_putstr("");
			pos += 1;
			while ((ft_chrchar(format[pos], "cspdiouxXfZzj") == 1
			|| (ft_chrchar(format[pos], OPTIONS) == 1)
			|| (ft_chrchar(format[pos], "lLh") == 1)))
				pos++;
		}
	}
	return (printed);
}

int		check_format(const char *str)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*tmp2;

	i = 1;
	tmp2 = "+-";
	tmp = FLAGS;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		j = -1;
		while (tmp[++j])
			if (str[i] == tmp[j])
				return (1);
		k = -1;
		while (tmp2[++k])
			if (str[i] == tmp2[k])
				return (1);
		i++;
	}
	return (0);
}

int		check_format2(const char *str)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*tmp2;

	i = 1;
	tmp2 = "+-";
	tmp = OTHER;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		j = -1;
		while (tmp[++j])
			if (str[i] == tmp[j])
				return (1);
		k = -1;
		while (tmp2[++k])
			if (str[i] == tmp2[k])
				return (1);
		i++;
	}
	return (0);
}

int		ft_strstringlen(const char *str, char *chr)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (str && chr)
	{
		while (str[i])
		{
			j = 0;
			while (chr[j])
			{
				if (chr[j] == str[i])
					return (i);
				j++;
			}
			i++;
		}
	}
	return (0);
}
