//
// Created by gyellowj on 12.08.2020.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"

#include <stdio.h>

typedef struct			s_stack_elem
{
	int 				number;
	struct s_stack_elem	*next;
}						t_stack_elem;

typedef	struct			s_stack
{
	t_stack_elem		*head;
	size_t 				size;
}						t_stack;

void* 					push_swap(int ac, char **av);
void					swap(t_stack_elem *elem);
void					push(t_stack *from_stack, t_stack *to_stack);
void					rotate(t_stack *stack);
void					reverse_rotate(t_stack *stack);
void					*median(t_stack a);

#endif
