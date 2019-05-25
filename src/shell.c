/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:20:27 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/25 08:37:08 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_exec_func		func;

	func = get_func(args[0]);
	return (func(args[0], args + 1));
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
		// todo: split white space
		command = ft_strsplit(commands[i], ' ');
		ret = exec_command(command);
		if (ret == EXIT_SIGNAL)
			break ;
		darrfree((void **)command);
	}
	darrfree((void **)commands);
	return (ret);
}
