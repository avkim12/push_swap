//
// Created by gyellowj on 13.08.2020.
//
#include <push_swap.h>

void				rotate(t_stack *stack)
{
	t_stack_elem 	*tmp;

	tmp = stack->head;
	stack->head = stack->head->next;
	while (stack->head->next)
		stack->head = stack->head->next;
	stack->head->next = tmp;
	stack->head->next->next = NULL;
	stack->head = tmp->next;
	free(tmp);
}