/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sysargs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 12:07:56 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/06 13:55:33 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strace.h"
#define STRMAX 20

char	*getargstring(int pid, u_int64_t reg, u_int8_t max)
{
	long	ret;
	char	s[9];
	int		i;
	char	text[UCHAR_MAX];

	i = 0;
	s[8] = 0;
	memset(text, 0, 100);
	while (1)
	{
		ret = ptrace(PTRACE_PEEKDATA, pid, reg + i * sizeof(long), NULL);
		if (ret < 0){
			perror("ptrace:");
			break;
		} else {
			memcpy(s, &ret, 8);
			strcat(text, s);
			if (ft_strlen(s) != sizeof(long))
				break;
		}
		if (i * sizeof(long) >= max)
			break;
		i++;
	}
	return (ft_strsub(text, 0, max));
}

void	ft_getstring(int id, int pid, u_int64_t reg)
{
	char *str;

	if (id != SYS_write && id != SYS_read)
	{
		str = getargstring(pid, reg, STRMAX);
		if (strlen(str) == STRMAX){
			memset(str + STRMAX - 4, '.', 3);
			str[STRMAX - 1] = 0;
		}
		fprintf(stderr, "\"%s\"", str);
	}
	else
		fprintf(stderr, "char *");
}

void	ft_getdef(t_arg *arg, u_int64_t reg)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
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

void	ft_getliteral(t_arg *arg, u_int64_t reg)
{
	int		i;

	i = 0;
	while (i < arg->defcount)
	{
		t_define *def = &arg->defines[i];
		if ((int)reg == def->value)
		{
			fprintf(stderr, "%s", def->name);
			break ;
		}
		i++;
	}
}
