/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:37:30 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/17 00:18:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void	ft_run(char **argv)
{
	pid_t pid;

	if (!(pid = fork()))
	{
		execv(argv[0], argv);
		perror("execv :");
		exit(EXIT_FAILURE);
	}
	ft_get_syscalls(pid);
}
