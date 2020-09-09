/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:55:05 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		flag;
	size_t	atoi;

	atoi = 0;
	flag = 1;
	while ((*str > 8 && *str < 14 && *str) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str && atoi <= 9223372036854775807)
	{
		atoi = atoi * 10 + (*str - '0');
		str++;
	}
	if (atoi >= 9223372036854775807 && flag == -1)
		return (0);
	else if (atoi >= 9223372036854775807 && flag == 1)
		return (-1);
	return (atoi * flag);
}
