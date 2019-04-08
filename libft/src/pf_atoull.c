/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:15:24 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:15:25 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_decimal_zeros(int zero)
{
	char	*nul;

	if (!(nul = (char *)malloc(sizeof(char) * zero + 1)))
		return (NULL);
	nul = ft_memset(nul, 48, zero);
	nul[zero] = '\0';
	return (nul);
}

unsigned long long	ft_decimal_process(unsigned long long pows[56],
char *str, int i, int tmp)
{
	unsigned long long nbr;

	nbr = pows[0];
	while (str[i] && i < 56)
	{
		if (str[i] == '1')
			nbr += pows[tmp];
		i++;
		tmp++;
	}
	return (nbr);
}

char				*ft_add_neg_pows(int zero, unsigned long long pows[56],
char *str)
{
	int					tmp;
	char				*nul;
	int					i;
	unsigned long long	nbr;
	char				*to_print;

	tmp = ft_search_c(str, '1');
	i = 0;
	while (++i < 56)
		pows[i] = pows[i - 1] >> 1;
	i = tmp + 1;
	tmp = 1;
	nbr = ft_decimal_process(pows, str, i, tmp);
	free(str);
	(ft_numlen(nbr, 10) > ft_numlen(pows[0], 10)) && zero != 0 ? zero-- : 0;
	to_print = ft_ulltoa_base(nbr, 10, _XMIN_);
	free(to_print);
	nul = ft_decimal_zeros(zero);
	to_print = ft_strjoinfs2(nul, ft_ulltoa_base(nbr, 10, _XMIN_));
	free(nul);
	return (to_print);
}

char				*ft_rightatoulltoa(char *str)
{
	int					i;
	unsigned long long	nbr;
	unsigned long long	pows[56];
	int					zero;
	int					tmp;

	nbr = 5;
	zero = 0;
	tmp = 0;
	pows[0] = (unsigned long long)500000000000000000;
	i = -1;
	while (i < 56 && str[++i] != '1')
	{
		nbr = nbr * 5;
		pows[0] = pows[0] >> 1;
		if (ft_numlen(nbr, 10) == tmp)
		{
			zero++;
			pows[0] *= 10;
		}
		tmp = ft_numlen(nbr, 10);
	}
	return (ft_add_neg_pows(zero, pows, str));
}

char				*ft_leftatoulltoa(char *str)
{
	int					i;
	unsigned long long	nbr;

	i = -1;
	nbr = 0;
	if (str == NULL)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '1')
		{
			nbr++;
			str[i + 1] ? nbr = nbr << 1 : 0;
		}
		else if (str[i + 1])
			nbr = nbr << 1;
	}
	free(str);
	return (ft_ulltoa_base(nbr, 10, _XMIN_));
}
