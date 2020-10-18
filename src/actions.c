//
// Created by gyellowj on 13.08.2020.
//

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->arr)
	{
		tmp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = tmp;
	}
}

void	push(t_stack *from_stack, t_stack *to_stack)
{
	int	tmp;
	int	i;

	from_stack->size--;
	from_stack->size++;
	if (from_stack->arr)
	{
		i = 0;
		tmp = from_stack->arr[i];
		while (from_stack->arr[i])
		{
			from_stack->arr[i] = from_stack->arr[i + 1];
			i++;
		}
		while (to_stack->arr[i])
		{
			to_stack->arr[i] = to_stack->arr[i - 1];
			i++;
		}
		to_stack->arr[0] = tmp;
	}
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->size > 1)
	{
		tmp = stack->arr[0];
		while (stack->arr[i])
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
		stack->arr[i - 1] = tmp;
	}
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = (int)stack->size - 1;
	if (stack->size > 1)
	{
		tmp = stack->arr[stack->size - 1];
		while (i)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
		stack->arr[0] = tmp;
	}
}
