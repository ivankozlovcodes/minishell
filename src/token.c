/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:44:46 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/28 13:50:39 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "chars.h"
#include "memory.h"
#include "ftstring.h"
#include "minishell.h"

void		get_token(t_list **alst, char *input, int s, int e)
{
	t_list		*new;
	char		*token;

	token = ft_strndup(input + s, e - s);
	new = ft_lstnew(token, ft_strlen(token) + 1);
	LST_ADDCREATE(*alst, new);
	ft_free(1, token);
}

t_list		*get_tokens_list(char *input)
{
	size_t	i;
	size_t	j;
	bool	inquote;
	t_list	*list;

	list = NULL;
	inquote = false;
	j = 0;
	i = -1;
	while (input[++i])
	{
		if (inquote && IS_QUOTE_SHELL(input[i]))
			inquote = false;
		else if (!inquote && IS_QUOTE_SHELL(input[i]))
			inquote = true;
		else if (!inquote && ISSPACE(input[i]))
		{
			if (i != j)
				get_token(&list, input, j, i);
			j = i + 1;
		}
	}
	i != j ? get_token(&list, input, j, i) : NOTHING;
	errno = inquote ? EQOUTE : errno;
	return (list);
}

char		**tokenize(char *input)
{
	t_list		*list;
	char		**tokens;

	errno = 0;
	tokens = NULL;
	list = get_tokens_list(input);
	if (!errno && list)
		tokens = (char **)lst_to_darr(list);
	ft_lstdel(&list, errno ? ft_free_content : ft_save_content);
	return (tokens);
}
