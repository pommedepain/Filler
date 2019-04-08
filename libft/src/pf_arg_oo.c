/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_oo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:19:30 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:19:32 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_toprint_oo(va_list list, t_flag *flag)
{
	if (flag->modif)
	{
		if (ft_strcmp(flag->modif, "ll") == 0)
			flag->to_print =
			ft_ulltoa_base(va_arg(list, unsigned long long), 8, _XMIN_);
		if (ft_strcmps(flag->modif, "h") == 0)
			flag->to_print =
			ft_ulltoa_base(
			(unsigned short)va_arg(list, unsigned int), 8, _XMIN_);
		if (ft_strcmps(flag->modif, "z") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list, ssize_t), 8, _XMIN_);
		if (ft_strcmps(flag->modif, "l") == 0)
			flag->to_print =
			ft_ulltoa_base(va_arg(list, unsigned long), 8, _XMIN_);
		if (ft_strcmps(flag->modif, "hh") == 0)
			flag->to_print =
			ft_ulltoa_base(
			(unsigned int)va_arg(list, unsigned long), 8, _XMIN_);
		if (ft_strcmps(flag->modif, "j") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list, intmax_t), 8, _XMIN_);
	}
	else
		flag->to_print =
		ft_ulltoa_base(va_arg(list, unsigned long long), 8, _XMIN_);
}

char		*ft_flag_oo(va_list list, t_flag flag)
{
	fill_toprint_oo(list, &flag);
	if (flag.precision < 0 && ft_chrstring(flag.to_print, "0"))
		flag.to_print = ft_strdups("");
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (ft_chrstring(flag.option, "#") == 1)
	{
		flag.field -= 1;
		flag.to_print = handle_field(flag);
	}
	else
		flag.to_print = handle_field(flag);
	if ((ft_chrstring(flag.option, "#") == 1))
	{
		if (flag.precision == -1)
			flag.to_print = ft_strjoin("0", flag.to_print);
		else if (ft_char_only(flag.to_print, '0', ' ') == 1)
			flag.to_print = ft_strdups(flag.to_print);
		else
			flag.to_print = ft_strdups(add_hashtag(flag.to_print, "0"));
	}
	return (flag.to_print);
}
