/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:55:26 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/01 01:11:54 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include <fcntl.h>
#include <sys/ioctl.h>

#define NO_ARG 0, {}
#define INT_ARG {INTEGER, 0, {}}
#define STR_ARG {STRING, 0, {}}
#define PTR_ARG {POINTER, 0, {}}

t_syscall syscalls[SYSCALLS_COUNT] = {
	{"read", 3, {INT_ARG, STR_ARG, INT_ARG}},
	{"write", 3, {INT_ARG, STR_ARG, INT_ARG}},
	{"open", 3, {STR_ARG, INT_ARG, INT_ARG}},
	{"close", 1, {INT_ARG}},
	{"stat", 3, {STR_ARG, PTR_ARG}},
	{"fstat", 2, {INT_ARG, PTR_ARG}},
	{"lstat", NO_ARG},
	{"poll", NO_ARG},
	{"lseek", NO_ARG},
	{"mmap", 6,{
		PTR_ARG,
		INT_ARG,
		{DEFINE, 3, {{PROT_READ, "PROT_READ"}, {PROT_WRITE, "PROT_WRITE"}, {PROT_EXEC, "PROT_EXEC"}}},
		{DEFINE, 5, {{MAP_PRIVATE, "MAP_PRIVATE"}, {MAP_SHARED, "MAP_SHARED"},
					{MAP_DENYWRITE, "MAP_DENYWRITE"}, {MAP_FIXED, "MAP_FIXED"},
					{MAP_ANONYMOUS, "MAP_ANONYMOUS"}}},
		INT_ARG,
		{HEXA, NO_ARG}
	}},
	{"mprotect", 3, {PTR_ARG, INT_ARG,
		{DEFINE, 4, {{PROT_NONE, "PROT_NONE"}, {PROT_READ, "PROT_READ"}, {PROT_WRITE, "PROT_WRITE"}, {PROT_EXEC, "PROT_EXEC"}}}}},
	{"munmap", 2, {PTR_ARG, INT_ARG}},
	{"brk", 1, {PTR_ARG}},
	{"rt_sigaction", 4, {INT_ARG, PTR_ARG, PTR_ARG, INT_ARG}},
	{"rt_sigprocmask", 4, {INT_ARG, PTR_ARG, PTR_ARG, INT_ARG}},
	{"rt_sigreturn", NO_ARG},
	{"ioctl", 3, {INT_ARG, INT_ARG, PTR_ARG}},
	{"pread64", 4, {INT_ARG, STR_ARG, INT_ARG, INT_ARG}},
	{"pwrite64", NO_ARG},
	{"readv", NO_ARG},
	{"writev", NO_ARG},
	{"access", 2, {STR_ARG, {DEFINE, 3, {{F_OK, "F_OK"}, {R_OK, "R_OK"}, {X_OK, "X_OK"}}}}},
	{"pipe", NO_ARG},
	{"select", NO_ARG},
	{"sched_yield", NO_ARG},
	{"mremap", NO_ARG},
	{"msync", NO_ARG},
	{"mincore", NO_ARG},
	{"madvise", NO_ARG},
	{"shmget", NO_ARG},
	{"shmat", NO_ARG},
	{"shmctl", NO_ARG},
	{"dup", NO_ARG},
	{"dup2", NO_ARG},
	{"pause", NO_ARG},
	{"nanosleep", NO_ARG},
	{"getitimer", NO_ARG},
	{"alarm", NO_ARG},
	{"setitimer", NO_ARG},
	{"getpid", NO_ARG},
	{"sendfile", NO_ARG},
	{"socket", NO_ARG},
	{"connect", NO_ARG},
	{"accept", NO_ARG},
	{"sendto", NO_ARG},
	{"recvfrom", NO_ARG},
	{"sendmsg", NO_ARG},
	{"recvmsg", NO_ARG},
	{"shutdown", NO_ARG},
	{"bind", NO_ARG},
	{"listen", NO_ARG},
	{"getsockname", NO_ARG},
	{"getpeername", NO_ARG},
	{"socketpair", NO_ARG},
	{"setsockopt", NO_ARG},
	{"getsockopt", NO_ARG},
	{"clone", NO_ARG},
	{"fork", NO_ARG},
	{"vfork", NO_ARG},
	{"execve", 3, {STR_ARG, PTR_ARG, PTR_ARG}},
	{"exit", NO_ARG},
	{"wait4", NO_ARG},
	{"kill", NO_ARG},
	{"uname", NO_ARG},
	{"semget", NO_ARG},
	{"semop", NO_ARG},
	{"semctl", NO_ARG},
	{"shmdt", NO_ARG},
	{"msgget", NO_ARG},
	{"msgsnd", NO_ARG},
	{"msgrcv", NO_ARG},
	{"msgctl", NO_ARG},
	{"fcntl", NO_ARG},
	{"flock", NO_ARG},
	{"fsync", NO_ARG},
	{"fdatasync", NO_ARG},
	{"truncate", NO_ARG},
	{"ftruncate", NO_ARG},
	{"getdents", NO_ARG},
	{"getcwd", NO_ARG},
	{"chdir", NO_ARG},
	{"fchdir", NO_ARG},
	{"rename", NO_ARG},
	{"mkdir", NO_ARG},
	{"rmdir", NO_ARG},
	{"creat", NO_ARG},
	{"link", NO_ARG},
	{"unlink", NO_ARG},
	{"symlink", NO_ARG},
	{"readlink", NO_ARG},
	{"chmod", NO_ARG},
	{"fchmod", NO_ARG},
	{"chown", NO_ARG},
	{"fchown", NO_ARG},
	{"lchown", NO_ARG},
	{"umask", NO_ARG},
	{"gettimeofday", NO_ARG},
	{"getrlimit", NO_ARG},
	{"getrusage", NO_ARG},
	{"sysinfo", NO_ARG},
	{"times", NO_ARG},
	{"ptrace", NO_ARG},
	{"getuid", NO_ARG},
	{"syslog", NO_ARG},
	{"getgid", NO_ARG},
	{"setuid", NO_ARG},
	{"setgid", NO_ARG},
	{"geteuid", NO_ARG},
	{"getegid", NO_ARG},
	{"setpgid", NO_ARG},
	{"getppid", NO_ARG},
	{"getpgrp", NO_ARG},
	{"setsid", NO_ARG},
	{"setreuid", NO_ARG},
	{"setregid", NO_ARG},
	{"getgroups", NO_ARG},
	{"setgroups", NO_ARG},
	{"setresuid", NO_ARG},
	{"getresuid", NO_ARG},
	{"setresgid", NO_ARG},
	{"getresgid", NO_ARG},
	{"getpgid", NO_ARG},
	{"setfsuid", NO_ARG},
	{"setfsgid", NO_ARG},
	{"getsid", NO_ARG},
	{"capget", NO_ARG},
	{"capset", NO_ARG},
	{"rt_sigpending", NO_ARG},
	{"rt_sigtimedwait", NO_ARG},
	{"rt_sigqueueinfo", NO_ARG},
	{"rt_sigsuspend", NO_ARG},
	{"sigaltstack", NO_ARG},
	{"utime", NO_ARG},
	{"mknod", NO_ARG},
	{"uselib", NO_ARG},
	{"personality", NO_ARG},
	{"ustat", NO_ARG},
	{"statfs", NO_ARG},
	{"fstatfs", NO_ARG},
	{"sysfs", NO_ARG},
	{"getpriority", NO_ARG},
	{"setpriority", NO_ARG},
	{"sched_setparam", NO_ARG},
	{"sched_getparam", NO_ARG},
	{"sched_setscheduler", NO_ARG},
	{"sched_getscheduler", NO_ARG},
	{"sched_get_priority_max", NO_ARG},
	{"sched_get_priority_min", NO_ARG},
	{"sched_rr_get_interval", NO_ARG},
	{"mlock", NO_ARG},
	{"munlock", NO_ARG},
	{"mlockall", NO_ARG},
	{"munlockall", NO_ARG},
	{"vhangup", NO_ARG},
	{"modify_ldt", NO_ARG},
	{"pivot_root", NO_ARG},
	{"_sysctl", NO_ARG},
	{"prctl", NO_ARG},
	{"arch_prctl", 2, {PTR_ARG, PTR_ARG}},
	{"adjtimex", NO_ARG},
	{"setrlimit", NO_ARG},
	{"chroot", NO_ARG},
	{"sync", NO_ARG},
	{"acct", NO_ARG},
	{"settimeofday", NO_ARG},
	{"mount", NO_ARG},
	{"umount2", NO_ARG},
	{"swapon", NO_ARG},
	{"swapoff", NO_ARG},
	{"reboot", NO_ARG},
	{"sethostname", NO_ARG},
	{"setdomainname", NO_ARG},
	{"iopl", NO_ARG},
	{"ioperm", NO_ARG},
	{"create_module", NO_ARG},
	{"init_module", NO_ARG},
	{"delete_module", NO_ARG},
	{"get_kernel_syms", NO_ARG},
	{"query_module", NO_ARG},
	{"quotactl", NO_ARG},
	{"nfsservctl", NO_ARG},
	{"getpmsg", NO_ARG},
	{"putpmsg", NO_ARG},
	{"afs_syscall", NO_ARG},
	{"tuxcall", NO_ARG},
	{"security", NO_ARG},
	{"gettid", NO_ARG},
	{"readahead", NO_ARG},
	{"setxattr", NO_ARG},
	{"lsetxattr", NO_ARG},
	{"fsetxattr", NO_ARG},
	{"getxattr", NO_ARG},
	{"lgetxattr", NO_ARG},
	{"fgetxattr", NO_ARG},
	{"listxattr", NO_ARG},
	{"llistxattr", NO_ARG},
	{"flistxattr", NO_ARG},
	{"removexattr", NO_ARG},
	{"lremovexattr", NO_ARG},
	{"fremovexattr", NO_ARG},
	{"tkill", NO_ARG},
	{"time", NO_ARG},
	{"futex", NO_ARG},
	{"sched_setaffinity", NO_ARG},
	{"sched_getaffinity", NO_ARG},
	{"set_thread_area", NO_ARG},
	{"io_setup", NO_ARG},
	{"io_destroy", NO_ARG},
	{"io_getevents", NO_ARG},
	{"io_submit", NO_ARG},
	{"io_cancel", NO_ARG},
	{"get_thread_area", NO_ARG},
	{"lookup_dcookie", NO_ARG},
	{"epoll_create", NO_ARG},
	{"epoll_ctl_old", NO_ARG},
	{"epoll_wait_old", NO_ARG},
	{"remap_file_pages", NO_ARG},
	{"getdents64", 3, {INT_ARG, PTR_ARG, INT_ARG}},
	{"set_tid_address", 1, {PTR_ARG}},
	{"restart_syscall", NO_ARG},
	{"semtimedop", NO_ARG},
	{"fadvise64", NO_ARG},
	{"timer_create", NO_ARG},
	{"timer_settime", NO_ARG},
	{"timer_gettime", NO_ARG},
	{"timer_getoverrun", NO_ARG},
	{"timer_delete", NO_ARG},
	{"clock_settime", NO_ARG},
	{"clock_gettime", NO_ARG},
	{"clock_getres", NO_ARG},
	{"clock_nanosleep", NO_ARG},
	{"exit_group", 1, {INT_ARG}},
	{"epoll_wait", NO_ARG},
	{"epoll_ctl", NO_ARG},
	{"tgkill", NO_ARG},
	{"utimes", NO_ARG},
	{"vserver", NO_ARG},
	{"mbind", NO_ARG},
	{"set_mempolicy", NO_ARG},
	{"get_mempolicy", NO_ARG},
	{"mq_open", NO_ARG},
	{"mq_unlink", NO_ARG},
	{"mq_timedsend", NO_ARG},
	{"mq_timedreceive", NO_ARG},
	{"mq_notify", NO_ARG},
	{"mq_getsetattr", NO_ARG},
	{"kexec_load", NO_ARG},
	{"waitid", NO_ARG},
	{"add_key", NO_ARG},
	{"request_key", NO_ARG},
	{"keyctl", NO_ARG},
	{"ioprio_set", NO_ARG},
	{"ioprio_get", NO_ARG},
	{"inotify_init", NO_ARG},
	{"inotify_add_watch", NO_ARG},
	{"inotify_rm_watch", NO_ARG},
	{"migrate_pages", NO_ARG},
	{"openat", 3, {
		{DEFINE, 1, {{AT_FDCWD, "AT_FDCWD"}}},
		STR_ARG, 
		{
			DEFINE, 4, {
				{O_NONBLOCK, "O_NONBLOCK"}, {O_RDONLY, "O_RDONLY"},
				{__O_CLOEXEC, "O_CLOEXEC"},{__O_DIRECTORY, "O_DIRECTORY"}
			}
		}
	}},
	{"mkdirat", NO_ARG},
	{"mknodat", NO_ARG},
	{"fchownat", NO_ARG},
	{"futimesat", NO_ARG},
	{"newfstatat", NO_ARG},
	{"unlinkat", NO_ARG},
	{"renameat", NO_ARG},
	{"linkat", NO_ARG},
	{"symlinkat", NO_ARG},
	{"readlinkat", NO_ARG},
	{"fchmodat", NO_ARG},
	{"faccessat", NO_ARG},
	{"pselect6", NO_ARG},
	{"ppoll", NO_ARG},
	{"unshare", NO_ARG},
	{"set_robust_list", 2, {PTR_ARG, INT_ARG}},
	{"get_robust_list", NO_ARG},
	{"splice", NO_ARG},
	{"tee", NO_ARG},
	{"sync_file_range", NO_ARG},
	{"vmsplice", NO_ARG},
	{"move_pages", NO_ARG},
	{"utimensat", NO_ARG},
	{"epoll_pwait", NO_ARG},
	{"signalfd", NO_ARG},
	{"timerfd_create", NO_ARG},
	{"eventfd", NO_ARG},
	{"fallocate", NO_ARG},
	{"timerfd_settime", NO_ARG},
	{"timerfd_gettime", NO_ARG},
	{"accept4", NO_ARG},
	{"signalfd4", NO_ARG},
	{"eventfd2", NO_ARG},
	{"epoll_create1", NO_ARG},
	{"dup3", NO_ARG},
	{"pipe2", NO_ARG},
	{"inotify_init1", NO_ARG},
	{"preadv", NO_ARG},
	{"pwritev", NO_ARG},
	{"rt_tgsigqueueinfo", NO_ARG},
	{"perf_event_open", NO_ARG},
	{"recvmmsg", NO_ARG},
	{"fanotify_init", NO_ARG},
	{"fanotify_mark", NO_ARG},
	{"prlimit64", NO_ARG},
	{"name_to_handle_at", NO_ARG},
	{"open_by_handle_at", NO_ARG},
	{"clock_adjtime", NO_ARG},
	{"syncfs", NO_ARG},
	{"sendmmsg", NO_ARG},
	{"setns", NO_ARG},
	{"getcpu", NO_ARG},
	{"process_vm_readv", NO_ARG},
	{"process_vm_writev", NO_ARG},
	{"kcmp", NO_ARG},
	{"finit_module", NO_ARG},
	{"sched_setattr", NO_ARG},
	{"sched_getattr", NO_ARG},
	{"renameat2", NO_ARG},
	{"seccomp", NO_ARG},
	{"getrandom", NO_ARG},
	{"memfd_create", NO_ARG},
	{"kexec_file_load", NO_ARG},
	{"bpf", NO_ARG},
	{"execveat", NO_ARG},
	{"userfaultfd", NO_ARG},
	{"membarrier", NO_ARG},
	{"mlock2", NO_ARG},
	{"copy_file_range", NO_ARG},
	{"preadv2", NO_ARG},
	{"pwritev2", NO_ARG},
	{"pkey_mprotect", NO_ARG},
	{"pkey_alloc", NO_ARG},
	{"pkey_free", NO_ARG},
	{"statx", NO_ARG},
	{"io_pgetevents", NO_ARG},
	{"rseq", NO_ARG},
	{"pidfd_send_signal", NO_ARG},
	{"io_uring_setup", NO_ARG},
	{"io_uring_enter", NO_ARG},
	{"io_uring_register", NO_ARG},
	{"open_tree", NO_ARG},
	{"move_mount", NO_ARG},
	{"fsopen", NO_ARG},
	{"fsconfig", NO_ARG},
	{"fsmount", NO_ARG},
	{"fspick", NO_ARG},
	{"pidfd_open", NO_ARG},
	{"clone3", NO_ARG}
};

void	ft_format(int id, struct user_regs_struct *ptr)
{
	t_syscall	*sys;
	t_arg		*arg;
	int			index;
	u_int64_t	reg;
	
	if (id < SYSCALLS_COUNT) {
		sys = &syscalls[id];
		fprintf(stderr, "%s(", sys->name);
		index = 0;
		while (index < sys->args_count)
		{
			arg = &sys->args[index];
			reg = ptr->rdi;
			if (index == 1)
				reg = ptr->rsi;
			else if (index == 2)
				reg = ptr->rdx;
			else if (index == 3)
				reg = ptr->r10;
			else if (index == 4)
				reg = ptr->r8;
			else if (index == 5)
				reg = ptr->r9;
			if (arg->type == INTEGER)
				fprintf(stderr, "%d", (int)reg);
			else if (arg->type == STRING){
				fprintf(stderr, "char *s");
			}
			else if (arg->type == POINTER){
				if (reg == 0)
					fprintf(stderr, "NULL");
				else
					fprintf(stderr, "%p", (void *)reg);
			}
			else if (arg->type == HEXA)
				fprintf(stderr, "%lx", reg);
			else if (arg->type == DEFINE)
			{
				int i = 0;
				char *str = NULL;
				// if (id == SYS_access)
				// 	fprintf(stderr, "%ld\n", reg);
				while (i < arg->defcount)
				{
					
					t_define *def = &arg->defines[i];
					if (reg & def->value || (!def->value && !reg))
					{
						if (str){
							str = ft_join("%s|%s", str, def->name);
						}
						else
							str = strdup(def->name);
					}
					i++;
				}
				if (str)
					fprintf(stderr, "%s", str);
			}
			index++;
			if (index < sys->args_count)
				fprintf(stderr, ", ");
		}
		fprintf(stderr, ") = ");
    }
	else
    	fprintf(stderr, "not yet !\n");
}
