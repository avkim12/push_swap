

SRC = actions.c \
	  median.c \
	  push_swap.c \
	  sort.c \
	  ft_atoi.c \
	  ft_strsplit.c \
	  ft_strsub.c
OBJ = $(patsubst %.c,%.o, $(SRC))
NAME = push_swap
INC = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I $(INC)
	@echo "\033[92m***PUSH_SWAP SUCCESSFULLY COMPILED***\033[39m"

$(OBJ): %.o:%.c
	@gcc -Wall -Wextra -Werror -c $< $(INC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
