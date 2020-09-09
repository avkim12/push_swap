/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:50:11 by kplums            #+#    #+#             */
/*   Updated: 2019/11/20 19:55:28 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*sym;

	i = 0;
	sym = (unsigned char*)b;
	while (i < len)
	{
		sym[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
