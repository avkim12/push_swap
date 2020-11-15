//
// Created by Gaylord Yellowjacket on 11/12/20.
//

#include "push_swap.h"

void		error_case(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

int			counter(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && (i == 0 || str[i - 1] == ' '))
			i++;
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			error_case();
		if ((str[i] >= '0' && str[i] <= '9') &&
			(str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	if (count == 1)
		exit(0);
	return (count);
}

void		check_repeat(t_stack *ret, int index, char ch)
{
	int		i;
	int		j;

	i = ret->arr[index];
	if (ch == 's')
	{
		while (++index < ret->size)
			if (ret->arr[index] == i)
			{
				free(ret->arr);
				free(ret);
				error_case();
			}
	}
	else if (ch == 'a')
	{
		j = 0;
		while (j < index)
			if (ret->arr[j++] == i)
			{
				free(ret->arr);
				free(ret);
				error_case();
			}
	}
}

int		parse_string(char *str)
{
	t_stack	*ret;
	int		i;
	int		count;

	i = 0;
	count = counter(str);
	ret = (t_stack*)malloc(sizeof(t_stack));
	ret->size = count;
	ret->arr = (int*)malloc(sizeof(int) * count);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			if (ft_atoi(&str[i]) > 2147483647 || ft_atoi(&str[i]) < -2147483648)
				error_case();
			ret->arr[--count] = ft_atoi(&str[i]);
			check_repeat(ret, count, 's');
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
		if (str[i] == ' ')
			i++;
	}
	return (1);
}

int			parse_arguments(char **argv, int argc)
{
	t_stack	*ret;
	int		i;
	int		k;

	i = 0;
	while (i < argc)
	{
		k = -1;
		if (argv[i][k + 1] == '-')
			k++;
		while (argv[i][++k] != '\0')
			if (argv[i][k] < '0' || argv[i][k] > '9')
				error_case();
		i++;
	}
	i = 0;
	ret = (t_stack*)malloc(sizeof(t_stack));
	ret->size = argc;
	ret->arr = (int*)malloc(sizeof(int) * argc);
	while (--argc >= 0)
	{
		ret->arr[i++] = ft_atoi(argv[argc]);
		check_repeat(ret, i - 1, 'a');
	}
	return (1);
}