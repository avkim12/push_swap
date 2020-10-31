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
	int 				size;
}						t_stack;

void 					*push_swap(int ac, char **av);
void					swap(t_stack *stack);
void					push(t_stack *from_stack, t_stack *to_stack);
void					rotate(t_stack *stack, int size);
void					reverse_rotate(t_stack *stack, int size);
void 					*a_to_b(t_stack *a_chunk, t_stack *b_chunk, int a_chunk_size);

#endif
