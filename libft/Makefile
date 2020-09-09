# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kplums <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:30:33 by kplums            #+#    #+#              #
#    Updated: 2019/12/18 17:30:35 by kplums           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = ./src
INCL_DIR = ./includes
OBJS_DIR = ./obj

FT_MEMORY_SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c

FT_CHAR_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_tolower.c ft_toupper.c

FT_STRING_SRCS = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c

FT_XTOY_SRCS = ft_atoi.c ft_itoa.c

FT_OUTPUT_SRCS = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

FT_LIST_SRCS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c

FT_MY_SRCS = ft_lenarrtochar.c ft_countarrtochar.c ft_newarrchar.c ft_lstlen.c \
             ft_lstdelcont.c

FT_GNL_SRCS = get_next_line.c

ALL_SRCS = $(FT_MEMORY_SRCS) $(FT_CHAR_SRCS) $(FT_STRING_SRCS) \
	$(FT_XTOY_SRCS) $(FT_OUTPUT_SRCS) $(FT_LIST_SRCS) \
	$(FT_GNL_SRCS) $(FT_MY_SRCS)

SRCS = $(addprefix $(SRCS_DIR)/, $(ALL_SRCS))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)
INCL = $(INCL_DIR)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(INCL_DIR)

.PHONY: all clean fclean re so

all: $(NAME)

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $< $(IFLAGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS_DIR);

fclean: clean
	@rm -rf $(NAME);

re: fclean all
