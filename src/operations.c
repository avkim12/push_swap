//
// Created by gyellowj on 13.08.2020.
//

#include <push_swap.h>

void				swap(t_stack_elem *elem)
{
	int 			tmp;

	if (elem && elem->next)
	{
		tmp = elem->number;
		elem->number = elem->next->number;
		elem->next->number = tmp;
	}
}

void				push(t_stack from_stack, t_stack to_stack)
{
	t_stack_elem	*tmp;

	if (from_stack.head)
	{
		tmp = from_stack.head->next;
		from_stack.head->next = to_stack.head;
		from_stack.head = tmp;
	}
}

void				rotate(t_stack *stack)
{
	t_stack_elem	*tmp;

	tmp = stack->head;
	stack->head = stack->head->next;
	while (stack->head->next)
		stack->head = stack->head->next;
	stack->head->next = tmp;
	stack->head->next->next = NULL;
	stack->head = tmp->next;
	free(tmp);
}

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
