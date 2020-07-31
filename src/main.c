/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:37:41 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/28 23:06:01 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	// t_syscall s[1] = {
	// 	{"read", 3, {{INTEGER, 0, 0, {}}, {STRING, 0, 0, {}}, {INTEGER, 0, 0, {}}}},
	// };
	// printf("%d", s[0].args[0].defines[0].value);
	// fflush(stdout);
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