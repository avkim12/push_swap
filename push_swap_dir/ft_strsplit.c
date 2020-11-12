/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:59:45 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 17:59:50 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_lenarr(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_newarr(char const *s, char c, char **arr)
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
		len = ft_lenarr(&s[i], c);
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

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	if (!(arr = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	if ((ft_newarr(s, c, arr) == 0))
	{
		free(arr);
		arr = NULL;
		return (NULL);
	}
	arr[ft_count(s, c)] = NULL;
	return (arr);
}
