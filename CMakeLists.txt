cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)
include_directories(libft/includes)

add_executable( push_swap
                main.c
                includes/push_swap.h
                src/push_swap.c
                src/swap.c
                src/push.c
                src/rotate.c
                src/reverse_rotate.c
                libft/src/ft_atoi.c)