/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:20:27 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/27 07:29:54 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "memory.h"
#include "ftstring.h"
#include "minishell.h"

static t_exec_func		get_func(char *name)
{
	t_exec_func			ret;
	static t_dict_pair	funcs[] = {
		(t_dict_pair){ .key = "cd", .val = cd },
		(t_dict_pair){ .key = "env", .val = env },
		(t_dict_pair){ .key = "echo", .val = echo },
		(t_dict_pair){ .key = "exit", .val = exitt },
		(t_dict_pair){ .key = "setenv", .val = setenv },
		(t_dict_pair){ .key = "unsetenv", .val = unsetenv } };
	static t_dict		disp = { .count = 6, .capacity = 6, .values = funcs };

	ret = dict_find(&disp, name);
	return (ret == NULL ? run_cmd : ret);
}

static int				exec_command(char **args)
{
	int				ret;
	t_exec_func		func;
	char			**expanded_args;

	func = get_func(args[0]);
	expanded_args = expand_args(args);
	ret = func(*expanded_args, expanded_args + 1);
	darrfree((void **)expanded_args);
	return (ret);
}

static char				*get_token(char **input)
{
	int		e;
	char	*ret;
	bool	quote;

	quote = ft_strchr("\"'`", **input);
	if (quote)
	{
		e = ft_strchri(*input + 1, **input);
		if (e < 0)
		{
			errno = EQOUTE;
			return (NULL);
		}
	}
	else
	{
		e = ft_strchri(*input, ' ');
		e = e < 0 ? ft_strlen(*input) : e;
	}
	ret = ft_strnew(e + quote + quote);
	ft_memcpy(ret, *input, e + quote + quote);
	*input += e + 1 + quote;
	ft_printf("got token |%s|\n", ret);
	return (ret);
}

static char				**tokenize(char *input)
{
	t_list		*new;
	t_list		*list;
	char		*token;
	char		**ret;

	list = NULL;
	while (*input)
	{
		if (*input == ' ')
		{
			input++;
			continue ;
		}
		errno = 0;
		token = get_token(&input);
		if (errno)
			break ;
		new = ft_lstnew(token, ft_strlen(token));
		!list ? list = new : ft_lstaddback(&list, new);
		ft_free(1, token);
	}
	ret = (char **)lst_to_darr(list);
	ft_lstdel(&list, errno ? ft_free_content : ft_save_content);
	return (ret);
}

int						exec_input(char *input)
{
	size_t	i;
	int		ret;
	char	**tokens;
	char	**commands;

	i = -1;
	ret = 0;
	commands = ft_strsplit(input, ';');
	while (commands[++i])
	{
		tokens = tokenize(commands[i]);
		if (errno != EQOUTE)
			ret = exec_command(tokens);
		darrfree((void **)tokens);
		if (ret == EXIT_SIGNAL || errno)
			break ;
	}
	darrfree((void **)commands);
	return (ret);
}
