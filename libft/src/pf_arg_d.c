/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:18:44 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 16:14:27 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_toprint_d(va_list list, t_flag *flag)
{
	if (flag->modif)
	{
		if (ft_strcmps(flag->modif, "ll") == 0)
			flag->to_print = ft_lltoa_base(va_arg(list, long long), 10, _XMIN_);
		if (ft_strcmps(flag->modif, "zh") == 0)
			flag->to_print = ft_lltoa_base(va_arg(list, long long), 10, _XMIN_);
		if (ft_strcmps(flag->modif, "jh") == 0)
			flag->to_print = ft_lltoa_base(va_arg(list, long long), 10, _XMIN_);
		if (ft_strcmps(flag->modif, "jz") == 0)
			flag->to_print = ft_lltoa_base(va_arg(list, long long), 10, _XMIN_);
		if (ft_strcmps(flag->modif, "j") == 0)
			flag->to_print = ft_lltoa_base(va_arg(list, intmax_t), 10, _XMIN_);
		if (ft_strcmps(flag->modif, "z") == 0)
			flag->to_print = ft_lltoa_base(va_arg(list, ssize_t), 10, _XMIN_);
		if (ft_strcmps(flag->modif, "h") == 0)
			flag->to_print = ft_itoa((short int)va_arg(list, int));
		if (ft_strcmps(flag->modif, "l") == 0)
			flag->to_print = ft_lltoa_base(va_arg(list, long), 10, _XMIN_);
		if (ft_strcmps(flag->modif, "hh") == 0)
			flag->to_print = ft_itoa((char)va_arg(list, int));
	}
	else
		flag->to_print = ft_itoa(va_arg(list, int));
}

char		*ft_flag_d(va_list list, t_flag flag)
{
	fill_toprint_d(list, &flag);
	if (ft_chrstring(flag.option, "+ ") == 1)
		flag.to_print = add_sign(flag.to_print, flag.option);
	if ((flag.precision >= 0 || flag.precision == -1) && flag.modif == NULL)
	{
		if (flag.precision < 0 && ft_strequ(flag.to_print, "0"))
		{
			free(flag.to_print);
			flag.to_print = ft_strdups("\0");
		}
		else if (flag.precision >= 0)
			flag.to_print = zero_fill(flag.to_print, flag.precision);
	}
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
