/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:05:06 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 18:05:12 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse(t_stack **elem)
{
	int	buff;
	int i;

	i = 0;
	buff = (*elem)->arr[0];
	while (i++ < (*elem)->size - 1)
		(*elem)->arr[i - 1] = (*elem)->arr[i];
	(*elem)->arr[(*elem)->size - 1] = buff;
}

void	rotate(t_stack **elem)
{
	int	buff;
	int i;

	i = (*elem)->size - 1;
	buff = (*elem)->arr[(*elem)->size - 1];
	while (i > 0)
	{
		(*elem)->arr[i] = (*elem)->arr[i - 1];
		i--;
	}
	(*elem)->arr[0] = buff;
}

void	swap(t_stack **elem)
{
	int buff;

	if ((*elem)->size < 2)
		return ;
	buff = (*elem)->arr[(*elem)->size - 1];
	(*elem)->arr[(*elem)->size - 1] = (*elem)->arr[(*elem)->size - 2];
	(*elem)->arr[(*elem)->size - 2] = buff;
}

void	push(t_stack **from, t_stack **to)
{
	if ((*from)->size == 0)
		return ;
	(*to)->arr[(*to)->size] = (*from)->arr[(*from)->size - 1];
	(*from)->arr[(*from)->size - 1] = 0;
	(*to)->size++;
	(*from)->size--;
}
