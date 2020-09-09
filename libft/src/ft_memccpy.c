/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:53:43 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*newsrc;
	unsigned char	*newdst;

	newsrc = (unsigned char *)src;
	newdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		if (newsrc[i] == (unsigned char)c)
		{
			newdst[i] = newsrc[i];
			return (dst + i + 1);
		}
		newdst[i] = newsrc[i];
		i++;
	}
	return (NULL);
}
