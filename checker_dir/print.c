/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:07:16 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 19:47:19 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		free_all(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
}

static void	ft_putstr(char *str)
{
	if (*str != '-')
		write(1, " ", 1);
	while (*str != '\0')
		write(1, str++, 1);
}

void		print_pr(t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	system("clear");
	ft_putstr("\033[1;32m\t\t\tSTACK A\t\t\t\t|\t\t\tSTACK B\033[0m\n");
	while (++i < a->size || i < b->size)
	{
		ft_putstr("\t\t\t");
		if (i == a->size - 1)
			ft_putstr("\033[1;31m");
		if (i < a->size)
			ft_putstr(ft_itoa(a->arr[i]));
		ft_putstr("\033[0m");
		if (a->arr[i] <= 9999 && a->arr[i] >= -9999)
			ft_putstr("\t");
		ft_putstr("\t\t\t|\t\t\t");
		if (i == b->size - 1)
			ft_putstr("\033[1;31m");
		if (i < b->size)
			ft_putstr(ft_itoa(b->arr[i]));
		ft_putstr("\033[0m\n");
	}
	usleep(100000);
}
