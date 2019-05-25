/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:37 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/24 22:31:27 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "memory.h"
#include "dstring.h"
#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

static char		*transform_arg(char *arg)
{
	int			i;
	char		*var_name;
	char		*var_value;
	t_string	*s;

	s = string_init(0);
	while ((i = ft_strchri(arg, '$')) >= 0)
	{
		arg[i] = 0;
		string_append(s, arg);
		arg += i + 1;
		i = ft_strchri(arg, '$');
		i = i < 0 ? ft_strlen(arg) : i;
		var_name = ft_strnew(i);
		ft_strncpy(var_name, arg, i);
		var_value = dict_find(g_env, var_name);
		var_value = var_value ? var_value : "";
		string_append(s, var_value);
		ft_free(1, var_name);
		arg += i;
	}
	string_append(s, arg);
	var_value = s->content;
	string_destroy(s, TRUE);
	return (var_value);
}

int				echo(char *name, char **args)
{
	bool	printnl;
	char	*to_print;

	printnl = !ft_strequ(*args, ECHO_N_FLAG);
	args += !printnl;
	while (*args)
	{
		to_print = transform_arg(*args);
		ft_printf("%s%s", to_print, *(args + 1) ? " " : "");
		args++;
	}
	if (printnl)
		ft_printf("\n");
	return (0);
}
