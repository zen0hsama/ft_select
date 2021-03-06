# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezonda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/15 15:57:32 by ezonda            #+#    #+#              #
#    Updated: 2019/07/03 00:16:36 by ezonda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = srcs/main.c \
	  srcs/display.c \
	  srcs/tools.c \
	  srcs/select.c \
	  srcs/move.c \
	  srcs/signal.c \
	  srcs/key.c \
	  srcs/term.c \

OBJ = srcs/main.o \
	  srcs/display.o \
	  srcs/tools.o \
	  srcs/select.o \
	  srcs/move.o \
	  srcs/signal.o \
	  srcs/key.o \
	  srcs/term.o \

LIB = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -l termcap

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(LIB) -I./libft $(OBJ) -I./includes -o $(NAME)

$(LIB):
	make -C libft/ fclean
	make -C libft/

%.o: %.c
	$(CC) -o $@ -c $< -I./includes

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
