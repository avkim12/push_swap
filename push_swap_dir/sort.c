/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:00:44 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 18:00:46 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elems(t_stack *a)
{
	if (a->arr[0] > a->arr[1] && a->arr[0] < a->arr[2] && a->arr[1] < a->arr[2])
		swap(a, 'a');
	if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] > a->arr[2])
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] < a->arr[2])
		rotate(a, 'a');
	if (a->arr[0] < a->arr[1] && a->arr[0] < a->arr[2] && a->arr[1] > a->arr[2])
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] > a->arr[2])
		reverse_rotate(a, 'a');
}

void	b_to_aa(t_stack *b, t_stack *a, int b_size, t_ps ps)
{
	while (ps.rotated-- && b_size != b->size)
		reverse_rotate(b, 'b');
	if (b_size == 2)
	{
		if (b->arr[0] < b->arr[1])
			swap(b, 'b');
		push(b, a, 'a');
		push(b, a, 'a');
	}
	if (b_size == 1)
		push(b, a, 'a');
	if (ps.a_size >= 2)
		a_to_b(a, b, ps.a_size, median(a, ps.a_size));
}

void	b_to_a(t_stack *b, t_stack *a, int b_size, int mid)
{
	t_ps ps;

	ps.i = 0;
	ps.rotated = 0;
	mid = median(b, b_size);
	ps.a_size = b_size % 2 == 0 ? b_size / 2 - 1 : b_size / 2;
	while (ps.i < ps.a_size)
	{
		if (b->arr[0] > mid)
		{
			push(b, a, 'a');
			b_size--;
			ps.i++;
		}
		else
		{
			rotate(b, 'b');
			ps.rotated++;
		}
	}
	b_to_aa(b, a, b_size, ps);
	if (b_size > 2)
		b_to_a(b, a, b_size, median(a, ps.a_size));
}

void	a_to_bb(t_stack *a, t_stack *b, int a_size, t_ps ps)
{
	while (ps.rotated-- && a_size != a->size)
		reverse_rotate(a, 'a');
	if (a_size > 2)
		a_to_b(a, b, a_size, median(a, a_size));
	if (a_size == 2 && a->arr[0] > a->arr[1])
		swap(a, 'a');
	b_to_a(b, a, ps.b_size, median(a, a_size));
}

void	a_to_b(t_stack *a, t_stack *b, int a_size, int mid)
{
	t_ps ps;

	ps.i = 0;
	ps.rotated = 0;
	a->size == 3 ? three_elems(a) : 0;
	if (is_a_sorted(a, a_size))
		return ;
	ps.b_size = a_size / 2;
	while (ps.i < ps.b_size)
	{
		if (a->arr[0] < mid)
		{
			push(a, b, 'b');
			a_size--;
			ps.i++;
		}
		else
		{
			rotate(a, 'a');
			ps.rotated++;
		}
	}
	a_to_bb(a, b, a_size, ps);
}
