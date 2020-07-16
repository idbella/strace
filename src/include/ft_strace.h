/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:47:32 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/17 00:20:18 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRACE_H
# define FT_STRACE_H
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
# define SYSCALLS_COUNT 436

int		ft_validatefile(char *file);
void	ft_run(char **argv);
void	ft_get_syscalls(int pid);
void    ft_die(char *str);
char    *ft_get_syscall_name(int id);
#endif
