//
// Created by gyellowj on 09.09.2020.
//

#include "push_swap.h"

void				*push_swap(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	int 			i;

	i = 0;
	a.size = 0;
	if (!(av = ft_strsplit(av[1], ' ')))
		return (NULL);
	while (av[i++])
		a.size++;
	i = 0;
	if (!(a.arr = (int *)malloc(sizeof(int) * a.size)))
		return (NULL);
	if (!(b.arr = (int *)malloc(sizeof(int) * a.size)))
		return (NULL);
	while (*av)
	{
		a.arr[i] = ft_atoi(*av);
		av++;
		i++;
	}

	i = 0;
	while (a.arr[i])
		printf("%d ", a.arr[i++]);
	i = 0;
	printf("\n");
	while (b.arr[i])
		printf("%d ", b.arr[i++]);
	printf("\n");

	sort(&a, &b);

	i = 0;
	while (a.arr[i])
		printf("%d ", a.arr[i++]);
	printf("\n");
	i = 0;
	while (b.arr[i])
		printf("%d ", b.arr[i++]);
	return (0);
}
