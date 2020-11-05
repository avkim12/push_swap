#include "push_swap.h"

int		is_sorted(t_stack *chunk, int size)
{
	int i = 0;

	while (i < size - 2)
	{
		if (chunk->arr[i] < chunk->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	quick_sort(int *arr, int first, int last, int pivot)
{
	int tmp;
	int left;
	int right;

	left = first;
	right = last;
	pivot = arr[(left + right) / 2];
	if (first < last)
	{
		while (left <= right)
		{
			while (arr[left] < pivot)
				left++;
			while (arr[right] > pivot)
				right--;
			if (left <= right)
			{
				tmp = arr[left];
				arr[left++] = arr[right];
				arr[right--] = tmp;
			}
		}
		quick_sort(arr, first, right, 0);
		quick_sort(arr, left, last, 0);
	}
}

int		median(t_stack *chunk, int size)
{
	int i;
	int *arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = chunk->arr[i];
		i++;
	}
	quick_sort(arr, 0, size - 1, 0);
	return (arr[size / 2]);
}

void	*b_to_a(t_stack *b_chunk, t_stack *a_chunk, int b_chunk_size, int mid)
{
	int	i;
	int	rotated = 0;
	int a_chunk_size;

	i = 0;
	a_chunk_size = b_chunk_size % 2 == 0 ? b_chunk_size / 2 - 1 : b_chunk_size / 2;
	while (i < a_chunk_size)
	{
		if (b_chunk->arr[0] > mid)
		{
			push(b_chunk, a_chunk, 'a');
			print(a_chunk, b_chunk);
			b_chunk_size--;
			i++;
		}
		else
		{
			rotate(b_chunk, 'b');
			print(a_chunk, b_chunk);
			rotated++;
		}
	}
	while (rotated-- && b_chunk_size != b_chunk->size)
	{
		reverse_rotate(b_chunk, 'b');
		print(a_chunk, b_chunk);
	}
	if (b_chunk_size == 1)
		push(b_chunk, a_chunk, 'a');
	if (b_chunk_size == 2)
	{
		if (b_chunk->arr[0] < b_chunk->arr[1])
			swap(b_chunk, 'b');
		push(b_chunk, a_chunk, 'a');
		push(b_chunk, a_chunk, 'a');
	}
	if (a_chunk_size >= 2)
		a_to_b(a_chunk, b_chunk, a_chunk_size, median(a_chunk, a_chunk_size));
	if (b_chunk_size > 2)
		b_to_a(b_chunk, a_chunk, b_chunk_size, median(b_chunk, b_chunk_size));
}

void	*a_to_b(t_stack *a_chunk, t_stack *b_chunk, int a_chunk_size, int mid)
{
	int i;
	int rotated = 0;
	int b_chunk_size;

	i = 0;
	b_chunk_size = a_chunk_size / 2;
	if (is_sorted(a_chunk, a_chunk_size))
		return (0);
	while (i < b_chunk_size)
	{
		if (a_chunk->arr[0] < mid || a_chunk->arr[a_chunk->size - 1] < mid)
		{
			if (a_chunk->arr[a_chunk->size - 1] < mid)
				reverse_rotate(a_chunk, 'a');
			push(a_chunk, b_chunk, 'b');
			print(a_chunk, b_chunk);
			a_chunk_size--;
			i++;
		}
		else
		{
			rotate(a_chunk, 'a');
			print(a_chunk, b_chunk);
			rotated++;
		}
	}
	while (rotated-- && a_chunk_size != a_chunk->size)
	{
		reverse_rotate(a_chunk, 'a');
		print(a_chunk, b_chunk);
	}
	if (a_chunk_size > 2)
		a_to_b(a_chunk, b_chunk, a_chunk_size, median(a_chunk, a_chunk_size));
	if (a_chunk_size == 2 && a_chunk->arr[0] > a_chunk->arr[1])
	{
		swap(a_chunk, 'a');
		print(a_chunk, b_chunk);
	}
	if (b_chunk->size > 0)
		b_to_a(b_chunk, a_chunk, b_chunk_size, median(b_chunk, b_chunk_size));
}