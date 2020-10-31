#include "push_swap.h"

int 	is_max(t_stack *chunk, int size)
{
	while (chunk->arr[0] > chunk->arr[size])
		size--;
	return (size == 0 ? 1 : 0);
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

int 	median(t_stack *chunk, int size)
{
	int *arr;
	int i;

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

void 	*b_to_a(t_stack *b_chunk, t_stack *a_chunk, int b_chunk_size)
{
    int i;
	int mid;
	int a_chunk_size;

    i = 0;
	a_chunk_size = (b_chunk_size > 2) ? b_chunk_size / 2 : 0;
	mid = median(b_chunk, b_chunk_size);
	while (i < a_chunk_size)
	{
		if (b_chunk->arr[0] > mid || b_chunk->arr[b_chunk_size - 1] > mid || is_max(b_chunk, b_chunk_size - 1))
		{
			if (b_chunk->arr[b_chunk_size - 1] > mid)
				reverse_rotate(b_chunk, b_chunk_size);
			push(b_chunk, a_chunk);
			b_chunk_size--;
			i++;
		}
		else
		    rotate(b_chunk, b_chunk_size);
	}
    if (a_chunk_size > 2)
        a_to_b(a_chunk, b_chunk, a_chunk_size);
    if (b_chunk_size > 2)
	    b_to_a(b_chunk, a_chunk, b_chunk_size);
	if (b_chunk_size == 2)
    {
        if (b_chunk->arr[0] < b_chunk->arr[1])
			swap(b_chunk);
		push(b_chunk, a_chunk);
		push(b_chunk, a_chunk);
    }
	if (b_chunk_size == 1)
        push(b_chunk, a_chunk);
	return (0);
}

void 	*a_to_b(t_stack *a_chunk, t_stack *b_chunk, int a_chunk_size)
{
    int i;
	int mid;
	int b_chunk_size;

	i = 0;
    b_chunk_size = (a_chunk_size > 2) ? a_chunk_size / 2 : 0;
	mid = median(a_chunk, a_chunk_size);
	while (i < b_chunk_size)
	{
		if (a_chunk->arr[0] < mid || a_chunk->arr[a_chunk_size - 1] < mid)
		{
			if (a_chunk->arr[a_chunk_size - 1] < mid)
				reverse_rotate(a_chunk, a_chunk_size);
			push(a_chunk, b_chunk);
			a_chunk_size--;
			i++;
		}
		else
		    rotate(a_chunk, a_chunk_size);
	}
	if (a_chunk_size == 2 && a_chunk->arr[0] > a_chunk->arr[1])
	    swap(a_chunk);
    if (b_chunk->size > 0)
        b_to_a(b_chunk, a_chunk, b_chunk_size);
    return (0);
}
