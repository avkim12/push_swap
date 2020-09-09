//
// Created by gyellowj on 13.08.2020.
//

#include <push_swap.h>

void				push(t_stack *to_stack, t_stack *from_stack)
{
	t_stack_elem	*tmp;

	if (from_stack->head) //возможно под head была выделена память хотя он пуст, поэтому стоит проверять есть ли в нем numbers
	{
		tmp = to_stack->head;
		to_stack->head = from_stack->head;
		to_stack->head->next = tmp;
		tmp = from_stack->head;
		from_stack->head = from_stack->head->next;
		free(tmp);
	}
}