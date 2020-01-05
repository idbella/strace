# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2020/01/05 19:51:39 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_strace

FLAGS= -Wall -Wextra -Werror

LIBFT= src/libft/libft.a

HINC = src/include/ft_strace.h src/include/libft.h

INC= -Isrc/include

SRC=src/main.c

CFLAGS = $(INC) $(FLAGS)

CC=gcc

OBJ=$(SRC:.c=.o)

all: $(LIBFT)  $(NAME) 

$(NAME): $(HINC) $(OBJ)
	gcc $(LIBFT) $(INC) $(FLAGS) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C src/libft

clean:
	make -C src/libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft fclean
	rm -rf $(NAME)

re: fclean all
