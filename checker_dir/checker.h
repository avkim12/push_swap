

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define PA "pa"
# define PB "pb"
# define SA "sa"
# define SB "sb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define SS "ss"
# define VISUAL "-v"

typedef struct	s_stack
{
	int			*arr;
	int			size;
	int			vis;
}				t_stack;

int				ft_strcmp(const char *str1, const char *str2);
int				ft_atoi(const char *str);
void			error_case(void);
t_stack			*parse_arguments(char **argv, int argc);
t_stack			*parse_string(char *str);
void			reverse(t_stack **elem);
void			rotate(t_stack **elem);
void			swap(t_stack **elem);
void			push(t_stack **from, t_stack **to);
char			*ft_itoa(int n);
void			print_pr(t_stack *a, t_stack *b);
void			free_all(t_stack *a, t_stack *b);

#endif
