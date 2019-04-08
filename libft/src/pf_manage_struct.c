/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:25:07 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:22 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_init_struct(t_flag *flag)
{
	flag->parsing = NULL;
	flag->to_print = NULL;
	flag->flag = '\0';
	flag->option = NULL;
	flag->precision = 0;
	flag->field = 0;
	flag->modif = NULL;
}

char	*ft_fillparsing(const char *str, int i, char *chr)
{
	int		j;
	char	*dest;
	int		k;

	k = 0;
	if (ft_chrstring(&str[i], FLAGS) != 1)
		return (particular_case(str, i));
	dest = init_pars(str, i);
	while (str[i])
	{
		j = 0;
		while (chr[j])
		{
			if (chr[j] == str[i])
			{
				dest[k] = str[i];
				dest[k + 1] = '\0';
				return (dest);
			}
			j++;
		}
		dest[k++] = str[i++];
	}
	free(dest);
	return (NULL);
}

t_flag	fill_flag(t_flag flag, va_list list)
{
	int i;

	i = 0;
	while (flag.parsing[i])
	{
		if (ft_chrchar(flag.parsing[i], OPTIONS) == 1)
			i = get_option(&flag, i);
		if ((flag.parsing[i] > '0' && flag.parsing[i] <= '9')
			|| flag.parsing[i] == '*')
			i = get_field(&flag, i, list);
		if (flag.parsing[i] == '.')
			i = get_precision(&flag, i, list);
		if (ft_chrchar(flag.parsing[i], "lLhzj") == 1)
		{
			flag.modif = pf_catch_modifier(flag.parsing, i, flag.modif);
			while (ft_chrchar(flag.parsing[i + 1], "lLhzj") == 1)
				i++;
		}
		i++;
	}
	if (ft_chrchar(flag.parsing[i - 1], FLAGS) == 1
	|| ft_chrchar(flag.parsing[i - 1], OTHER2) == 1)
		flag.flag = flag.parsing[i - 1];
	return (flag);
}

void	pf_free_struct(t_flag *flag)
{
	free(flag->parsing);
	free(flag->to_print);
	free(flag->option);
	free(flag->modif);
}
