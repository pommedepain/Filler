/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:19:08 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:45 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Duplicate the "%   " part of format in a separate string (with the call of
** ft_fillparsing)
** Fill the structure flag, with all the informations organized in order to help
** for the conversion (with the call of fill_flag)
*/

static	char	*fill_flag_toprint(va_list list, t_flag flag)
{
	(flag.flag == 'c' || flag.flag == 'C') ?
	flag.to_print = ft_flag_c(list, flag) : 0;
	(flag.flag == 's' || flag.flag == 'S') ?
	flag.to_print = ft_flag_s(list, flag) : 0;
	flag.flag == 'p' ? flag.to_print = ft_flag_p(list, flag) : 0;
	(flag.flag == 'd' || flag.flag == 'i') ?
	flag.to_print = ft_flag_d(list, flag) : 0;
	flag.flag == 'D' ? flag.to_print = ft_flag_dd(list, flag) : 0;
	flag.flag == 'o' ? flag.to_print = ft_flag_o(list, flag) : 0;
	flag.flag == 'O' ? flag.to_print = ft_flag_oo(list, flag) : 0;
	flag.flag == 'u' ? flag.to_print = ft_flag_u(list, flag) : 0;
	flag.flag == 'U' ? flag.to_print = ft_flag_uu(list, flag) : 0;
	flag.flag == 'x' ? flag.to_print = ft_flag_x(list, flag) : 0;
	flag.flag == 'b' ? flag.to_print = ft_flag_b(list, flag) : 0;
	flag.flag == 'X' ? flag.to_print = ft_flag_xx(list, flag) : 0;
	(flag.flag == 'f' || flag.flag == 'F') ?
	flag.to_print = ft_flag_f(list, flag) : 0;
	flag.flag == '%' ? flag.to_print = ft_flag_per(flag) : 0;
	if (ft_chrchar(flag.flag, OTHER2) == 1)
		flag.to_print = ft_flag_other(flag);
	return (flag.to_print);
}

int				ft_parsing(const char *format, int *i, va_list list)
{
	t_flag	flag;
	int		res;

	res = 0;
	pf_init_struct(&flag);
	*i += 1;
	flag.parsing = ft_fillparsing(format, *i, FLAGS);
	if (flag.parsing == NULL)
		return (0);
	flag = fill_flag(flag, list);
	flag.to_print = fill_flag_toprint(list, flag);
	*i += ft_strlen(flag.parsing);
	if (flag.flag == 'c' && ((ft_strlen(flag.to_print) == 0)
	|| (flag.field != 0 && (ft_char_only(flag.to_print, ' ', '0') == 1))))
	{
		ft_putstrbk0(flag.to_print, (ft_strlen(flag.to_print) + 1));
		res = ft_strlen(flag.to_print) + 1;
	}
	else
	{
		ft_putstr(flag.to_print);
		res = ft_strlen(flag.to_print);
	}
	pf_free_struct(&flag);
	return (res);
}

void			ft_putstrbk0(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}
