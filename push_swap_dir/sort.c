#include "push_swap.h"

int		is_a_sorted(t_stack *chunk, int size)
{
	int i = 0;

	while (i < size - 1)
	{
		if (chunk->arr[i] > chunk->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void 	three_elems(t_stack *a_chunk)
{
	if (a_chunk->arr[0] > a_chunk->arr[1] && a_chunk->arr[0] < a_chunk->arr[2] && a_chunk->arr[1] < a_chunk->arr[2])
		swap(a_chunk, 'a');
	else if (a_chunk->arr[0] > a_chunk->arr[1] && a_chunk->arr[0] > a_chunk->arr[2] && a_chunk->arr[1] > a_chunk->arr[2])
	{
		swap(a_chunk, 'a');
		reverse_rotate(a_chunk, 'a');
	}
	else if (a_chunk->arr[0] > a_chunk->arr[1] && a_chunk->arr[0] > a_chunk->arr[2] && a_chunk->arr[1] < a_chunk->arr[2])
		rotate(a_chunk, 'a');
	else if (a_chunk->arr[0] < a_chunk->arr[1] && a_chunk->arr[0] < a_chunk->arr[2] && a_chunk->arr[1] > a_chunk->arr[2])
	{
		swap(a_chunk, 'a');
		rotate(a_chunk, 'a');
	}
	else if (a_chunk->arr[0] < a_chunk->arr[1] && a_chunk->arr[0] > a_chunk->arr[2] && a_chunk->arr[1] > a_chunk->arr[2])
		reverse_rotate(a_chunk, 'a');
}

void	b_to_a(t_stack *b_chunk, t_stack *a_chunk, int b_chunk_size, int mid)
{
	int	i;
	int	rotated;
	int a_chunk_size;

	i = 0;
	rotated = 0;
	mid = median(b_chunk, b_chunk_size);
	a_chunk_size = b_chunk_size % 2 == 0 ? b_chunk_size / 2 - 1 : b_chunk_size / 2;
	while (i < a_chunk_size)
	{
		if (b_chunk->arr[0] > mid)
		{
			push(b_chunk, a_chunk, 'a');
			b_chunk_size--;
			i++;
		}
		else
		{
			rotate(b_chunk, 'b');
			rotated++;
		}
	}
	while (rotated-- && b_chunk_size != b_chunk->size)
		reverse_rotate(b_chunk, 'b');
	if (b_chunk_size == 2)
	{
		if (b_chunk->arr[0] < b_chunk->arr[1])
			swap(b_chunk, 'b');
		push(b_chunk, a_chunk, 'a');
		push(b_chunk, a_chunk, 'a');
	}
	if (b_chunk_size == 1)
		push(b_chunk, a_chunk, 'a');
	if (a_chunk_size >= 2)
		a_to_b(a_chunk, b_chunk, a_chunk_size, median(a_chunk, a_chunk_size));
	if (b_chunk_size > 2)
		b_to_a(b_chunk, a_chunk, b_chunk_size, median(a_chunk, a_chunk_size));
}

int 	a_to_b(t_stack *a_chunk, t_stack *b_chunk, int a_chunk_size, int mid)
{
	int i;
	int rotated;
	int b_chunk_size;

	i = 0;
	rotated = 0;
	a_chunk->size == 3 ? three_elems(a_chunk) : 0;
	if (is_a_sorted(a_chunk, a_chunk_size))
		return (0);
	b_chunk_size = a_chunk_size / 2;
	while (i < b_chunk_size)
	{
		if (a_chunk->arr[0] < mid)
		{
			push(a_chunk, b_chunk, 'b');
			a_chunk_size--;
			i++;
		}
		else
		{
			rotate(a_chunk, 'a');
			rotated++;
		}
	}
	while (rotated-- && a_chunk_size != a_chunk->size)
		reverse_rotate(a_chunk, 'a');
	if (a_chunk_size > 2)
		a_to_b(a_chunk, b_chunk, a_chunk_size, median(a_chunk, a_chunk_size));
	if (a_chunk_size == 2 && a_chunk->arr[0] > a_chunk->arr[1])
		swap(a_chunk, 'a');
	b_to_a(b_chunk, a_chunk, b_chunk_size, median(a_chunk, a_chunk_size));
	return (0);
}