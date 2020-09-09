/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:39:19 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ds;
	size_t	j;
	size_t	sr;

	ds = ft_strlen(dst);
	sr = ft_strlen(src);
	if (ds + 1 > size)
		return (size + sr);
	j = 0;
	while (j < size - ds - 1 && src[j] != '\0')
	{
		dst[ds + j] = src[j];
		j++;
	}
	dst[ds + j] = '\0';
	return (ds + sr);
}
