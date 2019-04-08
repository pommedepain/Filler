/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:26:12 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:18 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long value, int base)
{
	char	*tmp;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	tmp[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		tmp[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? tmp[i] = '-' : 0;
	return (tmp);
}

char	*ft_ltoa_base_2(long value, int base)
{
	char	*tmp;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	tmp[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		tmp[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? tmp[i] = '-' : 0;
	return (tmp);
}

int		ft_size(long n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char	*ft_ltoa(long n)
{
	char	*tab;
	int		len;
	int		neg;

	neg = 0;
	len = ft_size(n);
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (n < 0)
		neg = -1;
	if (n < 0)
		n *= -1;
	tab[len] = '\0';
	while (len--)
	{
		tab[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg == -1)
		tab[0] = '-';
	return (tab);
}

char	*pf_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		str[len] = '\0';
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		free((char *)s1);
		return (str);
	}
	else
		return (0);
}
