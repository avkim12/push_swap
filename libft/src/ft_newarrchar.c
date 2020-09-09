/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newarrchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:34:07 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_newarrchar(char const *s, char c, char **arr)
{
	int		i;
	int		g;
	int		len;

	g = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		len = ft_lenarrtochar(&s[i], c);
		arr[g] = ft_strsub(s, i, len);
		if (!arr[g])
		{
			while (g-- > 0)
				free(arr[g]);
			return (0);
		}
		g++;
		i = i + len;
	}
	return (1);
}
