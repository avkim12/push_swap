/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:27:04 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_strdupreverse(const char *s)
{
	int		i;
	int		j;
	char	*newscr;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	if (!(newscr = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	newscr[i] = '\0';
	while (--i >= 0)
		newscr[j++] = s[i];
	return (newscr);
}

static char		*ft_minint(int n)
{
	int		i;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	i = 9;
	str[0] = '-';
	str[10] = '8';
	str[11] = '\0';
	n = (n / 10) * -1;
	while (i > 0)
	{
		str[i] = n % 10 + 48;
		i--;
		n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		flag;
	char	*str;

	i = 0;\
	if (n == -2147483648)
		return (ft_minint(n));
	if (!(str = ft_strnew(11)))
		return (NULL);
	if ((flag = n) < 0)
		n = -n;
	while (n - 10 >= 0)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	str[i] = n % 10 + '0';
	if (flag < 0)
		str[++i] = '-';
	if (!(str = ft_strdupreverse(str)))
		return (NULL);
	return (str);
}
