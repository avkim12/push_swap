/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:58:22 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*newscr;

	i = 0;
	while (s[i])
		i++;
	if (!(newscr = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	newscr[i] = '\0';
	while (--i >= 0)
		newscr[i] = s[i];
	return (newscr);
}
