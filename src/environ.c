/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 03:16:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/21 04:46:06 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

t_env	*g_env;

void	init_env(void)
{
	extern char		**environ;
	char			*separator;
	size_t			i;
	size_t			len;

	i = 0;
	len = darrlen((void **)environ);
	g_env = ft_memalloc(sizeof(t_env) * (len + 1));
	// todo: parse path env
	while (environ[++i])
	{
		separator = ft_strchr((const char *)environ[i], '=');
		g_env[i].name = ft_strnew(separator - environ[i]);
		ft_memcpy(g_env[i].name, environ[i], separator - environ[i]);
		g_env[i].value = ft_strdup(separator + 1);
	}
}
