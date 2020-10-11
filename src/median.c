#include "push_swap.h"

void	sort_array(int *arr, int first, int last, int middle)
{
	int tmp;
	int left;
	int right;

	left = first;
	right = last;
	middle = arr[(left + right) / 2];
	if (first < last)
	{
		while (left <= right)
		{
			while (arr[left] < middle)
				left++;
			while (arr[right] > middle)
				right--;
			if (left <= right)
			{
				tmp = arr[left];
				arr[left++] = arr[right];
				arr[right--] = tmp;
			}
		}
		sort_array(arr, first, right, 0);
		sort_array(arr, left, last, 0);
	}
}

void	*median(t_stack a)
{
	int *arr;
	int i;

	i = 0;
	if (!(arr = (int *)malloc(sizeof(int) * a.size)))
		return (NULL);
	while (i < a.size)
	{
		arr[i] = a.head->number;
		a.head = a.head->next;
		i++;
	}
	sort_array(arr, 0, i - 1, 0);
	i = 0;
	while (arr[i])
	{
		printf("%i ", arr[i]);
		i++;
	}
	return (0);
}
