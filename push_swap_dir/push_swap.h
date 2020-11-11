

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_stack
{
	int 				*arr;
	int 				size;
}						t_stack;

typedef	struct			s_ps
{
	int 				i;
	int 				mid;
	int 				rotated;
	int 				a_size;
	int					b_size;
}						t_ps;

void					swap(t_stack *stack, char c);
void					push(t_stack *from_stack, t_stack *to_stack, char c);
void					rotate(t_stack *stack, char c);
void					reverse_rotate(t_stack *stack, char c);
void 					a_to_b(t_stack *a, t_stack *b, int a_size, int mid);
char					**ft_strsplit(char const *s, char c);
char					*ft_strsub(char const *s, unsigned int start, size_t len);
int						is_a_sorted(t_stack *chunk, int size);
int						median(t_stack *chunk, int size);
int						ft_atoi(const char *str);

#endif