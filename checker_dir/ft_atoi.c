

#include "checker.h"

int		ft_atoi(const char *str)
{
	long long	res;
	int			i;
	int			isneg;

	i = 0;
	res = 0;
	isneg = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			isneg = 1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (isneg == 1)
		res *= -1;
	if (res > INT_MAX || res < INT_MIN)
		error_case();
	return (res);
}
