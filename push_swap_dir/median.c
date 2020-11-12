/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:00:31 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 18:00:35 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_a_sorted(t_stack *chunk, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (chunk->arr[i] > chunk->arr[i + 1])
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
	i = arr[size / 2];
	free(arr);
	return (i);
}
