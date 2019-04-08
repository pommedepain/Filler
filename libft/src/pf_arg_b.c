/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:22:59 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:23:01 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_toprint_b(va_list list, t_flag *flag)
{
	if (flag->modif)
	{
		if (ft_strcmps(flag->modif, "ll") == 0)
			flag->to_print =
			ft_ulltoa_base(va_arg(list, unsigned long long), 2, "01");
		if (ft_strcmps(flag->modif, "j") == 0)
			flag->to_print = ft_ulltoa_base(va_arg(list, intmax_t), 2, "01");
		if (ft_strcmps(flag->modif, "z") == 0)
			flag->to_print =
			ft_ulltoa_base(va_arg(list, unsigned long long), 2, "01");
		if (ft_strcmps(flag->modif, "h") == 0)
			flag->to_print =
			ft_ulltoa_base(va_arg(list, unsigned int), 2, "01");
		if (ft_strcmps(flag->modif, "l") == 0)
			flag->to_print =
			ft_ulltoa_base(va_arg(list, unsigned long), 2, "01");
		if (ft_strcmps(flag->modif, "hh") == 0)
			flag->to_print =
			ft_ulltoa_base(va_arg(list, unsigned int), 2, "01");
	}
	else
		flag->to_print = ft_ulltoa_base(va_arg(list, unsigned int), 2, "01");
}

char		*ft_flag_b(va_list list, t_flag flag)
{
	fill_toprint_b(list, &flag);
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
	if (((ft_chrstring(flag.option, "#") == 1) &&
		(ft_strcmps(flag.to_print, "0"))) && ft_strcmps(flag.to_print, ""))
		flag.to_print = ft_strdups(add_hashtag(flag.to_print, "0x"));
	return (flag.to_print);
}
