//
// Created by gyellowj on 12.08.2020.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"

#include <stdio.h>

typedef	struct			s_stack
{
	int 				*arr;
	size_t 				size;
}						t_stack;

void* 					push_swap(int ac, char **av);
void					swap(t_stack *stack);
void					push(t_stack *from_stack, t_stack *to_stack);
void					rotate(t_stack *stack);
void					reverse_rotate(t_stack *stack);
void					sort(t_stack *a, t_stack *b);

#endif
