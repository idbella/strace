/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_syscalls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:38:03 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/16 23:43:53 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void	ft_get_syscalls(int pid)
{
	struct user_regs_struct	regs;
	int						in;
	int						status;

	if (ptrace(PTRACE_SEIZE, pid, NULL, NULL) < 0)
		ft_die("can't seize process");
	if (ptrace(PTRACE_INTERRUPT, pid, NULL, NULL) < 0)
		ft_die("can't interrupt proccess");
	
	in = -1;
	while (pid == waitpid(pid, &status, WUNTRACED))
	{
		if (WIFSTOPPED(status)){
			if (in < 0)
			{
                if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) < 0)
					ft_die("can't get process registers");
				ft_printf("call to %d\n", regs.orig_rax);
			}
			in *= -1;
			ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		}
	}
}
