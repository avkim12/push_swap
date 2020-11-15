/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:01:45 by gyellowj          #+#    #+#             */
/*   Updated: 2020/11/12 18:01:46 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_stack
{
	int					*arr;
	int					size;
}						t_stack;

typedef	struct			s_ps
{
	int					i;
	int					mid;
	int					rotated;
	int					a_size;
	int					b_size;
}						t_ps;

void					swap(t_stack *stack, char c);
void					push(t_stack *from_stack, t_stack *to_stack, char c);
void					rotate(t_stack *stack, char c);
void					reverse_rotate(t_stack *stack, char c);
void					a_to_b(t_stack *a, t_stack *b, int a_size, int mid);
char					**ft_strsplit(char const *s, char c);
char					*ft_strsub(char const *s, unsigned int st, size_t len);
long					ft_atoi(const char *str);
int						parse_string(char *str);
int						is_a_sorted(t_stack *chunk, int size);
int						median(t_stack *chunk, int size);
int						parse_arguments(char **argv, int argc, int i);

#endif
