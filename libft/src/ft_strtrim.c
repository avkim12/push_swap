/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:44:00 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	st;
	size_t	fi;
	char	*new;

	if (!s)
		return (NULL);
	st = 0;
	fi = ft_strlen(s) - 1;
	if (s[0] != ' ' && s[0] != '\t' && s[0] != '\n' && \
	s[fi] != ' ' && s[fi] != '\t' && s[fi] != '\n')
	{
		if (!(new = (char *)malloc((fi + 2) * sizeof(char *))))
			return (NULL);
		return (ft_strcpy(new, s));
	}
	while ((s[st] == ' ' || s[st] == '\t' || s[st] == '\n') && s[st])
		st++;
	if (st == fi + 1)
		return (ft_strnew(1));
	while (s[fi] == ' ' || s[fi] == '\t' || s[fi] == '\n')
		fi--;
	if (!(new = ft_strnew(fi - st + 1)))
		return (NULL);
	new = ft_strncpy(new, s + st, fi - st + 1);
	return (new);
}
