/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:00:15 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 18:00:17 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_all(t_stack *a, t_stack *b, char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	free(a->arr);
	free(b->arr);
}

int			str_arg(char **av)
{
	int		i;
	char	**str;
	t_stack	a;
	t_stack	b;

	i = -1;
	a.size = 0;
	b.size = 0;
	if (!(str = ft_strsplit(av[1], ' ')))
		return (0);
	while (str[a.size])
		a.size++;
	if (!(a.arr = (int *)malloc(sizeof(int) * a.size)))
		return (0);
	if (!(b.arr = (int *)malloc(sizeof(int) * a.size)))
		return (0);
	while (str[++i])
		a.arr[i] = ft_atoi(str[i]);
	if (a.arr)
		a_to_b(&a, &b, a.size, median(&a, a.size));
	free_all(&a, &b, str);
	return (0);
}

int			sev_arg(int ac, char **av)
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = -1;
	a.size = ac;
	b.size = 0;
	if (!(a.arr = (int *)malloc(sizeof(int) * ac)))
		return (0);
	if (!(b.arr = (int *)malloc(sizeof(int) * ac)))
		return (0);
	while (av[++i])
		a.arr[i] = ft_atoi(av[i]);
	if (a.arr)
		a_to_b(&a, &b, a.size, median(&a, a.size));
	free(a.arr);
	free(b.arr);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!(parse_string(av[1])))
			return (0);
		str_arg(av);
	}
	if (ac > 2)
	{
		if (!(parse_arguments(++av, --ac, -1)))
			return (0);
		sev_arg(ac, av);
	}
	return (0);
}
