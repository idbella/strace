/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:36:36 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/07 18:54:41 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"

void	ft_freearray(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

char    *ft_getexec(char *name)
{
	char	*path;
	char	**dirs;
	int		index;
	char	*fullpath;

	if (ft_strchr(name, '/'))
		return (ft_strdup(name));
	fullpath = NULL;
	if ((path = getenv("PATH")))
	{
		dirs = ft_strsplit(path, ':');
		index = 0;
		while (dirs && dirs[index])
		{
			fullpath = ft_join("%s/%s", dirs[index], name);
			if (!access(fullpath, F_OK))
				break ;
			free(fullpath);
			index++;
		}
		ft_freearray(dirs);
	}
	return (fullpath);
}
