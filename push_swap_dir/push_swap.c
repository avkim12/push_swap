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

void				free_all(t_stack *a, t_stack *b, char **av)
{
	int i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	free(a->arr);
	free(b->arr);
}


int					main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	int				i;

	if (ac < 2)
		return (0);
	if (ac != 2 || !(parse_string(av[1])))
		return (0);


	i = -1;
	a.size = 0;
	b.size = 0;
	if (!(av = ft_strsplit(av[1], ' ')))
		return (0);
	while (av[a.size])
		a.size++;
	if (!(a.arr = (int *)malloc(sizeof(int) * a.size)))
		return (0);
	if (!(b.arr = (int *)malloc(sizeof(int) * a.size)))
		return (0);
	while (av[++i])
		a.arr[i] = ft_atoi(av[i]);
	if (*a.arr)
		a_to_b(&a, &b, a.size, median(&a, a.size));
	free_all(&a, &b, av);
	return (0);
}

//int					main(int ac, char **av)
//{
//	t_stack			a;
//	t_stack			b;
//	int				i;
//
//	i = -1;
//	a.size = 0;
//	b.size = 0;
//	if (ac != 2)
//		return (0);
//	if (!(av = ft_strsplit(av[1], ' ')))
//		return (0);
//	while (av[a.size])
//		a.size++;
//	if (!(a.arr = (int *)malloc(sizeof(int) * a.size)))
//		return (0);
//	if (!(b.arr = (int *)malloc(sizeof(int) * a.size)))
//		return (0);
//	while (av[++i])
//		a.arr[i] = ft_atoi(av[i]);
//	if (*a.arr)
//		a_to_b(&a, &b, a.size, median(&a, a.size));
//	free_all(&a, &b, av);
//	return (0);
//}
