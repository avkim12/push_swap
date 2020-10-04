//
// Created by gyellowj on 09.09.2020.
//

#include "push_swap.h"

#include <stdio.h>

void 				*push_swap(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	t_stack_elem	*tmp_a;
	t_stack_elem	*tmp_b;

	if (!(a.head = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
		return(NULL);
	if (!(b.head = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
		return(NULL);
	tmp_a = a.head;
	tmp_b = b.head;
	if (!(av = ft_strsplit(av[1], ' ')))
		return (NULL);
	while (*av)
	{
		tmp_a->number = ft_atoi(*av);
//		printf("%i\n", tmp_a->number);
		tmp_b->number = 111;
		av++;
		if (*av)
		{
			if (!(tmp_a->next = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
				return (NULL);
			if (!(tmp_b->next = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
				return (NULL);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
	}
//	push(a, b);
	while (a.head)
	{
		printf("%i\n", a.head->number);
		a.head = a.head->next;
	}
	while (b.head)
	{
		printf("%i\n", b.head->number);
		b.head = b.head->next;
	}
	return (0);
}