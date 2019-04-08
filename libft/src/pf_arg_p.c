/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:24:17 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:24:18 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_field_p1(t_flag flag)
{
	if (flag.field > (int)ft_strlen(flag.to_print) &&
	ft_chrstring(flag.option, "-") != 1 && ft_chrstring(flag.option, "0") == 1
	&& (flag.precision == 0 || flag.precision == -1))
		flag.to_print = zero_fill_l(flag.to_print, flag.field - 2);
	return (flag.to_print);
}

static char	*handle_field_p2(t_flag flag)
{
	if (flag.field > (int)ft_strlen(flag.to_print)
		&& ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) &&
	ft_chrstring(flag.option, "-") != 1 && ft_chrstring(flag.option, "0") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) &&
	ft_chrstring(flag.option, "-") != 1 && ft_chrstring(flag.option, "0") == 1
	&& flag.precision != 0)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char		*print_address(void *address)
{
	unsigned char	b[8];
	int				i;
	char			*to_print;
	char			*to_free;

	if ((unsigned long long)address == 0)
	{
		to_print = ft_strdups("0");
		return (to_print);
	}
	i = 0;
	while (i < 8)
	{
		b[i] = ((unsigned long)address >> (56 - 8 * i)) & B1;
		i++;
	}
	to_print = bytes_to_str(b);
	i = 0;
	while (to_print[i] == 48)
		i++;
	to_free = to_print;
	to_print = ft_strsub(to_print, i, 20);
	free(to_free);
	return (to_print);
}

char		*ft_flag_p(va_list list, t_flag flag)
{
	flag.to_print = print_address(va_arg(list, void *));
	if (flag.precision > 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (flag.precision == -1 && ft_strcmp(flag.to_print, "0") == 0)
		flag.to_print = ft_strdups("");
	flag.to_print = handle_field_p1(flag);
	flag.to_print = ft_strjoinfs2("0x", flag.to_print);
	flag.to_print = handle_field_p2(flag);
	return (flag.to_print);
}
