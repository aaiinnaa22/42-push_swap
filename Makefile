# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 14:31:38 by aalbrech          #+#    #+#              #
#    Updated: 2024/09/04 18:15:33 by aalbrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c errorcheck.c make_stack_a.c \
lst_utils.c swap.c push.c \
rotate.c reverse_rotate.c \
issorted.c sort_two.c sort_three.c \
sort_big.c node_info.c sort.c \
basic_utils.c error_return.c sort_utils.c \
sort_five.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

NAME = push_swap

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

