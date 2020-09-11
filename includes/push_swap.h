//
// Created by gyellowj on 12.08.2020.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"

typedef struct			s_stack_elem
{
	int 				number;
	struct s_stack_elem	*next;
}						t_stack_elem;

typedef	struct			s_stack
{
	t_stack_elem		*head;
}						t_stack;

void* 					push_swap(int ac, char **av);

#endif
