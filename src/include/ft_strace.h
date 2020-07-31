/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:47:32 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/31 18:15:06 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRACE_H
# define FT_STRACE_H
#define MAP_DENYWRITE 2048
#define MAP_ANONYMOUS 32
#include <sys/mman.h>
#include <errno.h>
#include <limits.h>
# include "libft.h"
# include <sys/ptrace.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdio.h>
# include <sys/user.h>
# include <sys/reg.h>
# include <syscall.h>
# include "sys_structs.h"
# define ERRORS 34

typedef struct s_syslist
{
	struct s_syslist		*next;
	struct user_regs_struct	regs;
	int						id;
	u_int64_t				value;
}               t_syslist;

typedef struct s_error
{
	char	*name;
	int		number;
	char	*description;
}				t_error;

int		ft_validatefile(char *file);
void	ft_run(char **argv);
void	ft_get_syscalls(int pid);
void    ft_die(char *str);
char    ft_errno(int err);
void	ft_format(int id, struct user_regs_struct *ptr);
#endif
