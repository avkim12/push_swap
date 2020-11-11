#include "push_swap.h"

#include <stdio.h>

int				main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	int 			i;

	i = 0;
	a.size = 0;
	b.size = 0;
	if (ac < 2)
		return (0);
	if (!(av = ft_strsplit(av[1], ' ')))
		return (0);
	while (av[a.size])
		a.size++;
	if (!(a.arr = (int *)malloc(sizeof(int) * a.size)))
		return (0);
	if (!(b.arr = (int *)malloc(sizeof(int) * a.size)))
		return (0);
	while (*av)
		a.arr[i++] = ft_atoi(*av++);
	if (*a.arr)
		a_to_b(&a, &b, a.size, median(&a, a.size));

//	i = 0;
//	printf("\n\nA STACK: ");
//	while (i < a.size)
//		printf("%d ", a.arr[i++]);

//	free(a->arr);
//	free(a);
//	free(b->arr);
//	free(b);
	return (0);
}