/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:46:18 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/05 20:19:33 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

int		ft_validatefile(char *file)
{
	struct stat st;

	if (access(file, F_OK))
	{
		ft_printf("no such file or directory\n");
		return (1);
	}
	if (access(file, X_OK))
	{
		ft_printf("permission denied\n", file);
		return (1);
	}
	if (!stat(file, &st) && !S_ISREG(st.st_mode))
	{
		ft_printf("invalid file format\n");
		return (1);
	}
	return (0);
}

void	ft_run(char **argv)
{
	pid_t pid;
	int status;

	if (!(pid = fork()))
	{
		execv(argv[0], argv);
		perror("execv :");
	}
	wait(&status);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_validatefile(argv[1]))
		{
			ft_run(argv + 1);
			return (0);
		}
	}
	else
		ft_printf_fd(2, "usage : strace /path/to/file\n");
	return (1);
}