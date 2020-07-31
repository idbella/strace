/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:55:52 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/31 18:49:02 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_STRUCTS_H
# define SYS_STRUCTS_H
# define MAX_ARGS 10
# define SYSCALLS_COUNT 436
typedef enum e_arg_type
{
	INTEGER = 1,
	STRING,
	STRUCT,
	DEFINE,
	POINTER,
	HEXA
}			t_arg_type;

typedef struct s_define
{
	int value;
	char *name;
}				t_define;

typedef struct s_arg
{
	t_arg_type type;
    int			defcount;
	t_define	defines[5];
}				t_arg;

typedef struct s_syscall
{
	char *name;
	int  args_count;
	t_arg args[MAX_ARGS];
}				t_syscall;

#endif