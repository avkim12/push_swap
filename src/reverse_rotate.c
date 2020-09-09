//
// Created by gyellowj on 13.08.2020.
//

#include <push_swap.h>

void				reverse_rotate(t_stack *stack)
{
	t_stack_elem 	*tmp;

	tmp = stack->head;
	while (stack->head->next->next)
		stack->head = stack->head->next;
	stack->head->next->next = tmp;
	tmp = stack->head->next;
	stack->head->next = NULL;
	free(tmp);
}