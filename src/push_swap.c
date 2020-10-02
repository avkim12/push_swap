//
// Created by gyellowj on 09.09.2020.
//

#include "push_swap.h"

#include <stdio.h>

void 		*push_swap(int ac, char **av)
{
	t_stack a;
	t_stack_elem *tmp;

	if (!(a.head = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
		return(NULL);
	tmp = a.head;
	av = ft_strsplit(av[1], ' ');
	while (*av)
	{
		tmp->number = ft_atoi(*av);
		printf("%i\n", tmp->number);
		tmp->next = (t_stack_elem*)malloc(sizeof(t_stack_elem));
		tmp = tmp->next;
		av++;
	}
	while (a.head)
	{
		printf("%i\n", a.head->number);
		a.head = a.head->next;
	}
	return (0);
}