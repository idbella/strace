# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2020/08/06 13:57:13 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=strace

FLAGS= -Wall -Wextra -Werror -g

LIBFT= src/libft/libft.a

HINC = src/include/ft_strace.h src/include/sys_structs.h src/include/libft.h

INC= -Isrc/include

OBJ=src/main.o src/validate.o src/run.o\
	src/get_syscalls.o src/error.o\
	src/syscall_name.o src/sysargs.o

CFLAGS = $(INC) $(FLAGS)

CC=gcc

all: $(LIBFT)  $(NAME) 

$(NAME): $(HINC) $(OBJ)
	gcc $(INC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	make clean

$(LIBFT):
	make -C src/libft

clean:
	make -C src/libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft fclean
	rm -rf $(NAME)

re: fclean all

ARG=/bin/ls -R /home/superuser/Downloads 1>/dev/null
test:
	mkdir -p test
	strace ${ARG} 2>test/strace_data
	./strace ${ARG}  2>test/ft_strace_data
	vimdiff test/strace_data test/ft_strace_data

.PHONY : test
