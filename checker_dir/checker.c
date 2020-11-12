/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:05:29 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 18:05:31 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		act_case_2(t_stack *a, t_stack *b, char *buf)
{
	char c;

	c = 1;
	if (ft_strcmp(buf, RR) == 0)
	{
		rotate(&a);
		rotate(&b);
	}
	else if (ft_strcmp(buf, RRR) == 0)
	{
		reverse(&a);
		reverse(&b);
	}
	else
	{
		free_all(a, b);
		write(2, "ERROR\n", 6);
		if (buf[0] != '\0' && buf[1] != '\0'
			&& buf[2] != '\0' && buf[3] != '\0')
			while (c != '\n')
				read(0, &c, 1);
		exit(0);
	}
}

void		act_case(t_stack *a, t_stack *b, char *buf)
{
	if (ft_strcmp(buf, PA) == 0)
		push(&b, &a);
	else if (ft_strcmp(buf, PB) == 0)
		push(&a, &b);
	else if (ft_strcmp(buf, SA) == 0)
		swap(&a);
	else if (ft_strcmp(buf, SB) == 0)
		swap(&b);
	else if (ft_strcmp(buf, RA) == 0)
		rotate(&a);
	else if (ft_strcmp(buf, RB) == 0)
		rotate(&b);
	else if (ft_strcmp(buf, RRA) == 0)
		reverse(&a);
	else if (ft_strcmp(buf, RRB) == 0)
		reverse(&b);
	else if (ft_strcmp(buf, SS) == 0)
	{
		swap(&a);
		swap(&b);
	}
	else
		act_case_2(a, b, buf);
	if (a->vis == 1)
		print_pr(a, b);
}

void		check(t_stack *a, t_stack *b)
{
	int		ans;
	char	ch;
	char	buf[4];
	int		i;

	ans = 0;
	ch = 0;
	i = 0;
	buf[3] = '\0';
	while ((ans = read(0, &ch, 1)))
	{
		buf[i++] = ch == '\n' ? '\0' : ch;
		if (ch == '\n' || i == 4)
		{
			act_case(a, b, buf);
			i = 0;
		}
	}
}

int			is_sorted(t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	if (b->size > 0)
		return (0);
	while (++i < a->size - 1)
		if (a->arr[i] < a->arr[i + 1])
			return (0);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	if (argc < 2 || (argc == 2 && ft_strcmp(argv[1], VISUAL) == 0))
		return (0);
	i = ft_strcmp(argv[1], VISUAL) == 0 ? 2 : 1;
	if (argc == 2 || (argc == 3 && ft_strcmp(argv[1], VISUAL) == 0))
		a = parse_string(argv[i]);
	else
		a = parse_arguments(&argv[i], argc - i);
	a->vis = ft_strcmp(argv[1], VISUAL) == 0 ? 1 : 0;
	b = (t_stack*)malloc(sizeof(t_stack));
	b->size = 0;
	b->arr = (int*)malloc(sizeof(int) * a->size);
	if (a->vis == 1)
		print_pr(a, b);
	check(a, b);
	if (is_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(a, b);
	exit(0);
}
