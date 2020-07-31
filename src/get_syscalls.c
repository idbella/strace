/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_syscalls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:38:03 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/31 18:33:15 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void	ft_add(t_syslist **lst, t_syslist *node)
{
	t_syslist *list;

	list = *lst;
	if (!list) {
		*lst = node;
		return ;
	}
	while (list && list->next)
		list = list->next;
	list->next = node;
}

t_syslist *get(pid_t pid) {
	struct user_regs_struct	regs;
	int						in;
	int						status;;
	t_syslist				*node;
	t_syslist				*list;

	in = -1;
	list = NULL;
	node = NULL;
	while (pid == waitpid(pid, &status, 0)) {
		if (WIFSTOPPED(status)) {
			if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) < 0)
				ft_die("can't get process registers");
			if (in > 0 ){
				node = ft_memalloc(sizeof(t_syslist));
				node->next = NULL;
				memcpy(&node->regs, &regs, sizeof(regs));
				ft_add(&list, node);
				if (node) {
					node->id = regs.orig_rax;
				}
			} else {
				if (node){
					node->value = regs.rax;
				}
			}
			in *= -1;
			ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		}
	}
	return (list);
}

void printregs(struct user_regs_struct *ptr)
{
	//fprintf(stderr, "%d, char *, %d", (int)ptr->rdi, (int)ptr->rdx);

	/* sys(%rdi, ??, %rdx) */

	fprintf(stderr, "\trdi :%d\n", (int)ptr->rdi);
	fprintf(stderr, "\trsi :%d\n", (int)ptr->rsi);
	fprintf(stderr, "\trdx %d\n", (int)ptr->rdx);
	fprintf(stderr, "\trbx %d\n", (int)ptr->rbx);
	fprintf(stderr, "\tr8 %d\n", (int)ptr->r8);
	fprintf(stderr, "\tr9 %d\n", (int)ptr->r9);

	// fprintf(stderr, "\n\trax :%d\n", (int)ptr->rax);
	
	// fprintf(stderr, "\trcx :%d\n", (int)ptr->rcx);
	// fprintf(stderr, "\trbp :%d\n", (int)ptr->rbp);
	// fprintf(stderr, "\trip :%d\n", (int)ptr->rip);
	// fprintf(stderr, "\trsp %d\n", (int)ptr->rsp);

	
	
	// fprintf(stderr, "\tr10 %d\n", (int)ptr->r10);
	// fprintf(stderr, "\tr11 %d\n", (int)ptr->r11);
	// fprintf(stderr, "\tr12 %d\n", (int)ptr->r12);
	// fprintf(stderr, "\tr13 %d\n", (int)ptr->r13);
	// fprintf(stderr, "\tr14 %d\n", (int)ptr->r14);
	// fprintf(stderr, "\tr15 %d\n", (int)ptr->r15);



}

void	ft_get_syscalls(int pid)
{
	t_syslist		*head;

	// fprintf(stderr, "pid = %d\n", pid);
	if (ptrace(PTRACE_SEIZE, pid, NULL, NULL) < 0)
		ft_die("can't seize process");
	if (ptrace(PTRACE_INTERRUPT, pid, NULL, NULL) < 0)
		ft_die("can't interrupt proccess");
	head = get(pid);
	//int i = 1;
	while (head)
	{
		//fprintf(stderr, "%d ", i++);
		//ft_strequ("write", head->syscall_name) || ft_strequ("read", head->syscall_name))
		//printregs(&head->regs);
		//fprintf(stderr, ") = ");
		// if (head->id == SYS_mmap)
		// 	printregs(&head->regs);
		ft_format(head->id, &head->regs);
		if (ft_errno((int)head->value) == 0) {
			if ((int)head->value >= -ERANGE && (int) head->value < 1000)
				fprintf(stderr, "%d ", (int)head->value);
			else
				fprintf(stderr, "%p ", (void *)head->value);
		}
		
		fprintf(stderr, "\n");
		head = head->next;
	}
}
