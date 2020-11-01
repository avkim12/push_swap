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
	b.size = 0;
	if (!(av = ft_strsplit(av[1], ' ')))
		return (NULL);
	while (av[a.size])
		a.size++;
	if (!(a.arr = (int *)malloc(sizeof(int) * a.size)))
		return (NULL);
	if (!(b.arr = (int *)malloc(sizeof(int) * a.size)))
		return (NULL);
	while (*av)
		a.arr[i++] = ft_atoi(*av++);

//	i = 0;
//	printf("A STACK: ");
//	while (i < a.size)
//		printf("%d ", a.arr[i++]);
//	i = 0;
//	printf("\nB STACK: ");
//	while (i < b.size)
//		printf("%d ", b.arr[i++]);
//	printf("\n\nA STACK: ");
	if (*a.arr)
		a_to_b(&a, &b, a.size, median(&a, a.size));

	i = 0;
	while (i < a.size)
		printf("%d ", a.arr[i++]);
//	printf("\nB STACK: ");
//	i = 0;
//	while (i < b.size)
//		printf("%d ", b.arr[i++]);
	return (0);
}
