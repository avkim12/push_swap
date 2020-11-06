//
// Created by gyellowj on 12.08.2020.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_stack
{
	int 				*arr;
	int 				size;
}						t_stack;

void					swap(t_stack *stack, char c);
void					push(t_stack *from_stack, t_stack *to_stack, char c);
void					rotate(t_stack *stack, char c);
void					reverse_rotate(t_stack *stack, char c);
int 					a_to_b(t_stack *a_chunk, t_stack *b_chunk, int a_chunk_size, int mid);
int						median(t_stack *chunk, int size);
void					print(t_stack *a, t_stack *b);
char					**ft_strsplit(char const *s, char c);
int						ft_atoi(const char *str);
char					*ft_strsub(char const *s, unsigned int start, size_t len);

#endif