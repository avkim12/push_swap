/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:49:00 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	j;
	size_t	i;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)s;
	while (new[i])
	{
		if (new[i] == (char)c)
			j = i;
		i++;
	}
	if (c == 0)
		return (new + i);
	if (new[j] != (char)c)
		return (NULL);
	return (new + j);
}
