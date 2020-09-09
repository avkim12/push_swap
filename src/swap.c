//
// Created by gyellowj on 13.08.2020.
//FORBID printf

#include <push_swap.h>

void		swap(t_stack_elem *elem)
{
	int 	tmp;

	if (elem && elem->next)
	{
		tmp = elem->number;
		elem->number = elem->next->number;
		elem->next->number = tmp;
	}
}