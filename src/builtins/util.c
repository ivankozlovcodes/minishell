/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 07:28:45 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/27 16:41:52 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"
#include "minishell.h"

char					*remove_quotes(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		if (IS_QUOTE_SHELL(s[i]))
			ft_memmove(s + i, s + i + 1, len - i);
		else
			i++;
	}
	return (s);
}

size_t					token_len(const void *token)
{
	return (ft_strlen((const char *)token));
}
