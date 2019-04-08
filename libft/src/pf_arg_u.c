/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:24:36 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:24:38 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_u(va_list list, t_flag flag)
{
	if (flag.modif)
	{
		if (ft_strcmps(flag.modif, "ll") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list,
			unsigned long long), 10, _XMIN_);
		if (ft_strcmps(flag.modif, "j") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, intmax_t), 10, _XMIN_);
		if (ft_strcmps(flag.modif, "z") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, ssize_t), 10, _XMIN_);
		if (ft_strcmps(flag.modif, "h") == 0)
			flag.to_print = ft_itoa((unsigned short)va_arg(list, unsigned int));
		if (ft_strcmps(flag.modif, "l") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list,
			unsigned long), 10, _XMIN_);
		if (ft_strcmps(flag.modif, "hh") == 0)
			flag.to_print = ft_itoa((unsigned char)va_arg(list, unsigned int));
	}
	else
		flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 10, _XMIN_);
	if (flag.precision < 0)
		flag.to_print = ft_strdups("");
	else if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
