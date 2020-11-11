

SRC = actions.c \
	  print.c \
	  ft_itoa.c \
	  checker.c \
	  ft_atoi.c \
	  ft_strcmp.c \
	  parse.c
OBJ = $(patsubst %.c,%.o, $(SRC))
NAME = checker
INC = checker.h

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(INC)
	@echo "\033[92m***CHECKER SUCCESSFULLY COMPILED***\033[39m"

$(OBJ): %.o:%.c
	@gcc -Wall -Wextra -Werror -c $< $(INC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
