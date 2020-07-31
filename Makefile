# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2020/07/31 18:47:41 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=strace

FLAGS= -Wall -Wextra -Werror

LIBFT= src/libft/libft.a

HINC = src/include/ft_strace.h src/include/sys_structs.h src/include/libft.h

INC= -Isrc/include

OBJ=src/main.o src/validate.o src/run.o\
	src/get_syscalls.o src/error.o\
	src/syscall_name.o #src/model.o

CFLAGS = $(INC) $(FLAGS)

CC=gcc

all: $(LIBFT)  $(NAME) 

$(NAME): $(HINC) $(OBJ)
	gcc $(INC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	make clean
	make test

$(LIBFT):
	make -C src/libft

clean:
	make -C src/libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft fclean
	rm -rf $(NAME)

re: fclean all

ARG=/bin/ls /home/superuser
test:
	mkdir -p test
	strace ${ARG} 2>test/strace_data
	./strace ${ARG}  2>test/ft_strace_data

.PHONY : test
