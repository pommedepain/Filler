/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:24:51 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:24:53 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_to_print_x(va_list list, t_flag *flag)
{
	if (flag->modif)
	{
		if (ft_strcmps(flag->modif, "ll") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list,
			unsigned long long), 16, _XMIN_);
		if (ft_strcmps(flag->modif, "j") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list,
			intmax_t), 16, _XMIN_);
		if (ft_strcmps(flag->modif, "z") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list,
			unsigned long long), 16, _XMIN_);
		if (ft_strcmps(flag->modif, "h") == 0)
			flag->to_print = ft_ulltoa_base((unsigned short)va_arg(list,
			unsigned int), 16, _XMIN_);
		if (ft_strcmps(flag->modif, "l") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list,
			unsigned long), 16, _XMIN_);
		if (ft_strcmps(flag->modif, "hh") == 0)
			flag->to_print = ft_ulltoa_base((unsigned char)va_arg(list,
			unsigned int), 16, _XMIN_);
	}
	else
		flag->to_print = ft_ulltoa_base(va_arg(list, unsigned int), 16, _XMIN_);
}

char		*ft_flag_x(va_list list, t_flag flag)
{
	fill_to_print_x(list, &flag);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	else if (flag.precision == -1)
		flag.to_print = ft_strdups("");
	if (ft_chrstring(flag.option, "#") == 1)
	{
		flag.field -= 2;
		flag.to_print = handle_field(flag);
	}
	else
		flag.to_print = handle_field(flag);
	if (((ft_chrstring(flag.option, "#") == 1) && (ft_strcmps(flag.to_print,
		"0") != 0)) && ft_strcmps(flag.to_print, "") != 0)
		flag.to_print = ft_strdups(add_hashtag(flag.to_print, "0x"));
	return (flag.to_print);
}
