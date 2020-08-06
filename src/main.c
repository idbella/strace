/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:37:41 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/06 11:42:43 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

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
