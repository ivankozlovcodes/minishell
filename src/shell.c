/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:20:27 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/27 03:27:28 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
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

int						exec_input(char *input)
{
	size_t	i;
	int		ret;
	char	**command;
	char	**commands;

	i = -1;
	ret = 0;
	commands = ft_strsplit(input, ';');
	while (commands[++i])
	{
		command = ft_strsplit(commands[i], ' ');
		ret = exec_command(command);
		if (ret == EXIT_SIGNAL)
			break ;
		darrfree((void **)command);
	}
	darrfree((void **)commands);
	return (ret);
}
