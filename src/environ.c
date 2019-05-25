/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 03:16:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/24 20:19:29 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

t_dict	*g_env;

void	init_env(void)
{
	extern char		**environ;
	char			*separator;
	size_t			i;
	size_t			len;

	i = -1;
	g_env = dict_init(0);
	// todo: parse path env
	while (environ[++i])
	{
		separator = ft_strchr((const char *)environ[i], '=');
		*separator = 0;
		dict_insert(g_env, environ[i], separator + 1);
	}
}
