/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:20:26 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:20 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert a decimal digit string (into a bigger string) into a int
** (With another
** charactere before the digits and with the seucrity if there is no digit after
** this charactere)
*/

int		pf_catch_precision(char *str, int i, va_list list)
{
	int		j;
	char	*numbers;
	int		len;

	j = 0;
	i += 1;
	len = 1;
	if ((str[i] <= '0' || str[i] > '9') && str[i] != '*')
		return (-1);
	if (str[i] == '*')
	{
		j = va_arg(list, int);
		return (j);
	}
	while (str[i++] >= '0' && str[i] <= '9')
		len++;
	i -= len;
	if (!(numbers = malloc(sizeof(char) * len + 1)))
		return (-2);
	numbers[len] = '\0';
	while (str[i] >= '0' && str[i] <= '9')
		numbers[j++] = str[i++];
	j = ft_atoi(numbers);
	free(numbers);
	return (j);
}

/*
** Convert a decimal digit string (into a bigger string) into a int
*/

int		pf_catch_field(char *str, int i, va_list list)
{
	int		j;
	char	*numbers;
	int		len;
	int		ibis;

	j = 0;
	len = 1;
	ibis = i;
	if (str[i] == '*')
	{
		j = va_arg(list, int);
		return (j);
	}
	while (str[ibis++] >= '0' && str[ibis] <= '9')
		len++;
	if (!(numbers = malloc(sizeof(char) * len + 1)))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		numbers[j++] = str[i++];
	numbers[j] = '\0';
	j = ft_atoi(numbers);
	free(numbers);
	return (j);
}

char	*pf_catch_option(char *str, int i, char *res)
{
	int j;
	int len;
	int ibis;

	j = 0;
	len = 0;
	ibis = i;
	while (ft_chrchar(str[ibis++], OPTIONS) == 1)
		len++;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (ft_chrchar(str[i], OPTIONS) == 1)
		res[j++] = str[i++];
	if (char_counter(res, '#') >= 1 && char_counter(res, '0') > 1
	&& ft_chrstring(res, "+-") != 1)
		res = NULL;
	return (res);
}

char	*pf_catch_modifier(char *str, int i, char *res)
{
	int j;
	int len;
	int ibis;

	j = 0;
	len = 0;
	ibis = i;
	while (ft_chrchar(str[ibis++], "lLhjz") == 1)
		len++;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (ft_chrchar(str[i], "lLhjz") == 1)
		res[j++] = str[i++];
	if (ft_chrstring(res, "l") == 1 && ft_chrstring(res, "h") == 1)
		res = NULL;
	return (res);
}
