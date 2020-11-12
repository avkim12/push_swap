/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:59:20 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 17:59:26 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long			ft_atoi(const char *str)
{
	long	flag;
	long	atoi;

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
