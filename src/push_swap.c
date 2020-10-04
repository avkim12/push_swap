//
// Created by gyellowj on 09.09.2020.
//

#include "push_swap.h"

#include <stdio.h>

void 				*fill_stack(char **av, t_stack *a, t_stack *b)
{
	t_stack_elem	*tmp_a;
	t_stack_elem	*tmp_b;

	tmp_a = a->head;
	tmp_b = b->head;
	if (!(av = ft_strsplit(av[1], ' ')))
		return (NULL);
	while (*av)
	{
		tmp_a->number = ft_atoi(*av);
		tmp_b->number = 6;
		tmp_a->next = NULL;
		tmp_b->next = NULL;
		av++;
		if(*av)
		{
			if (!(tmp_a->next = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
				return (NULL);
			if (!(tmp_b->next = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
				return (NULL);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
	}
}

void 				*push_swap(int ac, char **av)
{
	t_stack			a;
	t_stack			b;

	if (!(a.head = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
		return(NULL);
	if (!(b.head = (t_stack_elem*)malloc(sizeof(t_stack_elem))))
		return(NULL);
	fill_stack(av, &a, &b);
	push(&a, &b);
	while (a.head)
	{
		printf("  %i\n", a.head->number);
		a.head = a.head->next;
	}
	printf("______\n");
	while (b.head)
	{
		printf("  %i\n", b.head->number);
		b.head = b.head->next;
	}
	return (0);
}