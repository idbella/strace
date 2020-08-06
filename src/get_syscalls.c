/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_syscalls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:38:03 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/06 12:11:07 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void	get(pid_t pid) {
	t_registers	regs;
	int			in;
	int			status;

	in = 1;
	wait(NULL);
	ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
	while (pid == wait(&status)) {
		if (WIFSTOPPED(status)) {
			if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) < 0)
				ft_die("can't get process registers");
			if (in > 0){
				ft_format(pid, regs.orig_rax, &regs);
			} else {
				if (ft_errno((int)regs.rax) == 0) {
					if ((int)regs.rax >= -ERANGE && (int) regs.rax < 1000)
						fprintf(stderr, "%d ", (int)regs.rax);
					else
						fprintf(stderr, "%p ", (void *)regs.rax);
				}
				fprintf(stderr, "\n");
			}
			in *= -1;
			ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		}
	}
	if (in == -1)
		fprintf(stderr, "?\n");
}

void	ft_get_syscalls(int pid)
{
	if (ptrace(PTRACE_SEIZE, pid, NULL, NULL) < 0)
		ft_die("can't PTRACE_SEIZE process");
	if (ptrace(PTRACE_INTERRUPT, pid, NULL, NULL) < 0)
		ft_die("can't PTRACE_INTERRUPT proccess");
	get(pid);
}
