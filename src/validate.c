/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:37:15 by sid-bell          #+#    #+#             */
/*   Updated: 2020/07/16 23:37:21 by sid-bell         ###   ########.fr       */
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
