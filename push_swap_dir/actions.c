/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:00:54 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 18:00:55 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c)
{
	int	tmp;

	if (stack->arr)
	{
		tmp = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = tmp;
	}
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push(t_stack *from_stack, t_stack *to_stack, char c)
{
	int	i;

	if (from_stack->arr)
	{
		from_stack->size--;
		to_stack->size++;
		i = to_stack->size;
		while (i-- > 0)
			to_stack->arr[i] = to_stack->arr[i - 1];
		to_stack->arr[0] = from_stack->arr[0];
		while (i++ < from_stack->size)
			from_stack->arr[i] = from_stack->arr[i + 1];
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, char c)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->size > 1)
	{
		tmp = stack->arr[0];
		while (i < stack->size - 1)
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
		stack->arr[i] = tmp;
	}
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *stack, char c)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
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
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
