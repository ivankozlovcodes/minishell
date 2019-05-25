/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 03:16:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/25 10:17:13 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

t_dict	*g_env;

char			*pair_to_str(t_dict_pair pair)
{
	char		*ret;
	size_t		key_len;
	size_t		val_len;

	key_len = ft_strlen(pair.key);
	val_len = ft_strlen(pair.val);
	ret = ft_strnew(key_len + val_len + 1);
	ft_strcat(ret, pair.key);
	ft_strcat(ret, "=");
	ft_strcat(ret, pair.val);
	return (ret);
}

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
