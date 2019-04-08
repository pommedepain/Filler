/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:25:53 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:28:57 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handle_field(t_flag flag)
{
	if (flag.field > (int)ft_strlen(flag.to_print)
		&& ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print)
		&& ft_chrstring(flag.option, "-") != 1
		&& ft_chrstring(flag.option, "0") == 1
		&& (flag.precision == 0 || flag.precision == -1))
		flag.to_print = zero_fill_l(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print)
		&& ft_chrstring(flag.option, "-") != 1
		&& ft_chrstring(flag.option, "0") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print)
		&& ft_chrstring(flag.option, "-") != 1
		&& ft_chrstring(flag.option, "0") == 1 && flag.precision != 0)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*add_sign(char *str, char *option)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 1;
	if (ft_chrstring(str, "-") == 1)
		return (str);
	if (!(res = (char *)malloc(sizeof(char) * len + 2)))
		return (0);
	res[len + 1] = '\0';
	if (ft_chrstring(option, "+") == 1)
		res[0] = '+';
	if (ft_chrstring(option, " ") == 1 && ft_chrstring(option, "+") != 1)
		res[0] = ' ';
	while (str[i])
		res[j++] = str[i++];
	free(str);
	return (res);
}

char	*bytes_to_str(unsigned char b[8])
{
	int		i;
	char	*hex;
	char	*str;

	hex = _XMIN_;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 19)))
		return (NULL);
	while (i < 8)
	{
		str[2 * i + 1] = hex[((int)b[i] % 16)];
		b[i] /= 16;
		str[2 * i] = hex[((int)b[i] % 16)];
		i++;
	}
	str[16] = '\0';
	return (str);
}

int		ft_char_only(char *str, char c, char d)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != d)
			return (0);
		i++;
	}
	return (1);
}

char	*add_hashtag(char *str, char *add)
{
	char	*mod;
	int		len;
	int		i;
	int		j;
	int		k;

	len = ft_strlen(str) + ft_strlen(add);
	if (!(mod = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	mod[len] = '\0';
	j = 0;
	k = 0;
	while (str[k] == ' ')
		mod[j++] = str[k++];
	i = 0;
	while (add[i])
		mod[j++] = add[i++];
	while (str[k])
		mod[j++] = str[k++];
	free(str);
	return (mod);
}
