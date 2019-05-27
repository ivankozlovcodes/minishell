/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:03 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/26 19:43:10 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

int		setenv(char *name, char **args)
{
	char	*env_name;
	char	*env_value;

	(void)name;
	env_name = *args;
	env_value = *(args + 1) ? *(args + 1) : "";
	if (!env_name)
		return (env(name, args));
	else if (valid_env_name(env_name))
		dict_insert(g_env, env_name, env_value);
	else
		ft_printf("setenv: Variable name must begin with a letter\
and contain only alphanumeric characters.\n");
	return (0);
}
