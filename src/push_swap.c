//
// Created by gyellowj on 09.09.2020.
//

#include "push_swap.h"

#include <stdio.h>

void 				*push_swap(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	t_stack_elem	*tmp;

	tmp = a->head;
	if (!(av = ft_strsplit(av[1], ' ')))
		return (NULL);
	while (*av)
	{
		if (!(tmp = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
			return(NULL);
		if (!(b->head = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
			return(NULL);
		tmp->number = ft_atoi(*av);

		b->head->number = 0;
		printf("%i\n", b->head->number);

		tmp = tmp->next;

		b->head = b->head->next;
		av++;
	}

	push(a, b);
	while (a->head)
	{
		printf("%i\n", a->head->number);
		a->head = a->head->next;
	}
	return (0);
}