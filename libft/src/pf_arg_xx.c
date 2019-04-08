/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:24:58 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:25:00 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_to_print_xx(va_list list, t_flag *flag)
{
	if (flag->modif)
	{
		if (ft_strcmps(flag->modif, "ll") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list,
			unsigned long long), 16, _X_);
		if (ft_strcmps(flag->modif, "j") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list, intmax_t), 16, _X_);
		if (ft_strcmps(flag->modif, "h") == 0)
			flag->to_print = ft_ulltoa_base((unsigned short)va_arg(list,
			unsigned int), 16, _X_);
		if (ft_strcmps(flag->modif, "z") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list, ssize_t), 16, _X_);
		if (ft_strcmps(flag->modif, "l") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list,
			unsigned long), 16, _X_);
		if (ft_strcmps(flag->modif, "hh") == 0)
			flag->to_print = ft_ulltoa_base((unsigned char)va_arg(list,
			unsigned int), 16, _X_);
	}
	else
		flag->to_print = ft_ltoa_base(va_arg(list, unsigned int), 16);
}

char		*ft_flag_xx(va_list list, t_flag flag)
{
	fill_to_print_xx(list, &flag);
	if (flag.precision < 0)
		flag.to_print = ft_strdups("");
	else if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (ft_chrstring(flag.option, "#") == 1)
	{
		flag.field -= 2;
		flag.to_print = handle_field(flag);
	}
	else
		flag.to_print = handle_field(flag);
	if (((ft_chrstring(flag.option, "#") == 1) && (ft_strcmps(flag.to_print,
		"0") != 0)) && ft_strcmps(flag.to_print, "") != 0)
		flag.to_print = add_hashtag(flag.to_print, "0X");
	return (flag.to_print);
}
