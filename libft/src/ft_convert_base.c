/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:07:08 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:07:10 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_4(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int				ft_3(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32)
			return (0);
		j = 0;
		while (base[i + j + 1])
		{
			if (base[i] == base[i + j + 1] && base[i] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static	int				ft_2(char *nbr, char *base)
{
	int		i;
	int		j;
	int		sign;
	int		count;

	sign = 1;
	i = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
		if (nbr[i++] == '-')
			sign = -1;
	while (nbr[i])
	{
		j = 0;
		count = 0;
		while (base[j])
			if (nbr[i] == base[j++])
				count++;
		if (count == 0)
			return (0);
		i++;
	}
	return (sign);
}

static	char			*ft_1(int nbr, int sign, char *base, unsigned int size)
{
	int				i;
	int				count;
	char			*tab;
	unsigned int	n;

	i = 0;
	n = nbr;
	while (n >= size && (i += 1))
		n = n / size;
	count = i;
	(sign < 0) ? count++ : (0);
	if (!(tab = (char *)malloc(sizeof(char) * (count + 1))))
		return (0);
	i = 0;
	n = nbr;
	while (n >= size && (tab[count - i++] = base[n % size]))
		n = n / size;
	if (sign < 0 && (tab[0] = '-'))
		tab[1] = base[n % size];
	else
		tab[0] = base[n % size];
	tab[count + 1] = 0;
	return (tab);
}

char					*ft_convert_base(
							char *nbr, char *base_from, char *base_to)
{
	int		i[3];
	int		lbf;

	if (!(ft_3(base_from) && ft_3(base_to)))
		return (0);
	if (!(ft_2(nbr, base_from)))
		return (0);
	lbf = ft_4(base_from);
	i[2] = 0;
	i[0] = 0;
	while (nbr[i[0]] == 32 || (nbr[i[0]] >= 9 && nbr[i[0]] <= 13)
		|| nbr[i[0]] == 43 || nbr[i[0]] == 45)
		i[0]++;
	while (nbr[i[0]])
	{
		i[1] = 0;
		while (base_from[i[1]])
		{
			if (nbr[i[0]] == base_from[i[1]])
				i[2] = i[2] * lbf + i[1];
			i[1]++;
		}
		i[0]++;
	}
	return (ft_1(i[2], ft_2(nbr, base_from), base_to, ft_4(base_to)));
}
