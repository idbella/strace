# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2020/07/16 23:47:54 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_strace

FLAGS= -Wall -Wextra -Werror

LIBFT= src/libft/libft.a

HINC = src/include/ft_strace.h src/include/libft.h

INC= -Isrc/include

OBJ=src/main.o src/validate.o src/run.o src/get_syscalls.o src/error.o

CFLAGS = $(INC) $(FLAGS)

CC=gcc

all: $(LIBFT)  $(NAME) 

$(NAME): $(HINC) $(OBJ)
	gcc $(INC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C src/libft

clean:
	make -C src/libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft fclean
	rm -rf $(NAME)

re: fclean all
