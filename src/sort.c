#include "push_swap.h"

int		*quick_sort(int *arr, int first, int last, int pivot)
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
	return (arr);
}

int 	median(t_stack stack)
{
	int median;
	int *arr;
	int i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * stack.size);
	while (stack.arr[i])
	{
		arr[i] = stack.arr[i];
		i++;
	}
	arr = quick_sort(arr, 0, (int) stack.size - 1, 0);
	median = arr[stack.size / 2];
	return (median);
}

void 	sort(t_stack *a, t_stack *b)
{
	int mid;
	int i;

	i = 0;
	mid = median(*a);
	while (a->arr[0] < mid)
		push(a, b);
	while (a->arr[a->size - 1] < mid)
	{
		reverse_rotate(a);
		push(a, b);
	}
//	while (i < a->size)
//	{
//		while (a->arr[0] >= mid)
//		{
//			rotate(a);
//		}
//		push(a, b);
//		i++;
//	}
}
