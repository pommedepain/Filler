/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:15:34 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:15:35 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_double	*ft_decomp(void *d)
{
	t_double		*n;
	unsigned char	*ptr;
	int				i;

	i = 0;
	if (!(n = (t_double *)malloc(sizeof(t_double))))
		return (NULL);
	ptr = (unsigned char *)d;
	n->s = ptr[7] >> 7;
	n->e = ((((int)(ptr[7] << 1) >> 1) << 4) + (ptr[6] >> 4)) & EXPONENT;
	n->f = 0;
	while (i < 6)
	{
		n->f += (unsigned long long)ptr[i] << (8 * i);
		i++;
	}
	n->f += (unsigned long long)((ptr[6] & CUT)) << 48;
	n->pow = n->e - 1023;
	return (n);
}

char		*ft_put_zeros_neg(int pow, char *fraction)
{
	int		size;
	char	*tmp;
	int		i;
	char	*frac;

	size = pow - 1;
	frac = ft_strjoinfs2("1", fraction);
	i = -1;
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i < size)
		tmp[i] = '0';
	tmp[i] = '\0';
	frac = ft_strjoinfs2(tmp, frac);
	free(tmp);
	frac = ft_strjoinfs2("0.", frac);
	return (frac);
}

char		*ft_put_zeros_pos(int pow, char *fraction)
{
	int		size;
	char	*tmp;
	int		i;
	char	*frac;
	char	*tmp2;

	size = 1;
	i = -1;
	if (pow >= 52)
		return (ft_strjoinfs1(ft_large_number(pow, fraction), "."));
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tmp[0] = '1';
	tmp[1] = '\0';
	frac = ft_strjoinfs1s2(tmp, fraction);
	if (!(tmp = malloc(sizeof(char) * pow + 3)))
		return (NULL);
	while (++i < pow + 1 && i < 64)
		tmp[i] = frac[i];
	tmp[i] = '.';
	tmp[i + 1] = '\0';
	tmp2 = ft_strsub(frac, pow + 1, 56);
	free(frac);
	frac = ft_strjoinfs1s2(tmp, tmp2);
	return (frac);
}

char		*ft_zeros(int pow, char *fraction)
{
	char	*tmp;

	if (pow < 0)
		tmp = ft_put_zeros_neg(pow * -1, fraction);
	else
		tmp = ft_put_zeros_pos(pow, fraction);
	return (tmp);
}

char		*ft_double(double d)
{
	t_double	*n;
	char		*fraction;
	int			size;
	int			i;
	char		*tmp;

	if (!(n = ft_decomp(&d)))
		return (NULL);
	if (!(fraction = (char *)malloc(sizeof(char) * 53)))
		return (NULL);
	tmp = ft_ulltoa_base(n->f, 2, "01");
	size = ft_strlens(tmp);
	i = -1;
	while (++i < (52 - size))
		fraction[i] = '0';
	i--;
	while (++i < 52)
		fraction[i] = tmp[i - (52 - size)];
	fraction[52] = '\0';
	free(tmp);
	tmp = ft_zeros(n->pow, fraction);
	tmp = final_process(tmp);
	n->s == 1 ? tmp = ft_strjoinfs2("-", tmp) : 0;
	free(n);
	return (tmp);
}
