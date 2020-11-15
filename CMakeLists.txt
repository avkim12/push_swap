cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(checker_dir)
include_directories(push_swap_dir)

add_executable(push_swap
#        checker_dir/actions.c
#        checker_dir/checker.c
#        checker_dir/checker.h
#        checker_dir/ft_atoi.c
#        checker_dir/ft_itoa.c
#        checker_dir/ft_strcmp.c
#        checker_dir/parse.c
#        checker_dir/print.c
        push_swap_dir/actions.c
        push_swap_dir/ft_atoi.c
        push_swap_dir/ft_strsplit.c
        push_swap_dir/ft_strsub.c
        push_swap_dir/median.c
        push_swap_dir/parse.c
        push_swap_dir/push_swap.c
        push_swap_dir/push_swap.h
        push_swap_dir/sort.c)
