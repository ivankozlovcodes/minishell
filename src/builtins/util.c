/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 07:28:45 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/06/03 03:14:22 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"
#include "memory.h"
#include "ftstring.h"
#include "minishell.h"

char					*get_env_name(char *arg)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (arg[i] && ft_isalnum(arg[i]))
		i++;
	i += i == 0;
	ret = ft_strnew(i);
	ft_strncpy(ret, arg, i);
	return (ret);
}

char					*remove_quotes(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		if (IS_QUOTE_SHELL(s[i]))
			ft_memcpy(s + i, s + i + 1, len - i);
		else
			i++;
	}
	return (s);
}

size_t					token_len(const void *token)
{
	return (ft_strlen((const char *)token));
}
