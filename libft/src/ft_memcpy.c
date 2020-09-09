/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:32:26 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*newsrc;
	unsigned char	*newdst;

	newsrc = (unsigned char *)src;
	newdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		if (dst < src)
		{
			newdst[i] = newsrc[i];
		}
		i++;
	}
	i--;
	if (dst > src)
	{
		while (i < n)
		{
			newdst[i] = newsrc[i];
			i--;
		}
	}
	return (dst);
}
