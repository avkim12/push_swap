//
// Created by gyellowj on 09.09.2020.
//

#include "push_swap.h"


#include <stdio.h>


void 		push_swap(int ac, char **av)
{
	t_stack a;
	av = ft_strsplit(*av, ' ');
	while (*av)
	{
		a.head->number = ft_atoi(*av);
		a.head = a.head->next;
		*av++;
	}
	while (a.head->next)
	{

		printf("%i\n", a.head->number);

		a.head = a.head->next;
	}
}