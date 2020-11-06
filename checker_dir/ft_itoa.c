/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:27:01 by bdebbie           #+#    #+#             */
/*   Updated: 2019/09/15 19:08:15 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		swap_itoa(char *ret, int i, int isneg)
{
	char buff;

	buff = ret[i];
	ret[i] = ret[isneg];
	ret[isneg] = buff;
}

static int		str_len(int n)
{
	int ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		ret++;
	}
	while (n > 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		isneg;

	isneg = 1;
	if (n < 0)
		isneg = -1;
	i = 0;
	ret = malloc(sizeof(char) * str_len(n) + 1);
	if (ret == NULL)
		return (NULL);
	while (n > 9 || n < -9)
	{
		ret[i++] = isneg * (n % 10) + '0';
		n = n / 10;
	}
	ret[i++] = isneg * (n % 10) + '0';
	if (isneg == -1)
		ret[i++] = '-';
	ret[i] = '\0';
	isneg = 0;
	while (--i > isneg)
		swap_itoa(ret, i, isneg++);
	return (ret);
}
