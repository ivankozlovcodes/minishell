/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:20:27 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/21 07:29:39 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ftstring.h"
#include "memory.h"

static int				run_cmd(char *name, char **args)
{
	not_implemented("run cmd");
	return (0);
}

static t_exec_func		get_func(char *name)
{
	int						idx;
	static t_exec_func		table[] = {
		cd, env, echo, exitt, setenv, unsetenv
	};
	static char				*names[] = {
		"cd", "env", "echo", "exit", "setenv", "unsetenv"
	};

	idx = ft_straridx(name, names);
	if (idx >= 0)
		return (table[idx]);
	return (run_cmd);
}

static int				exec_command(char **args)
{
	t_exec_func		func;

	func = get_func(args[0]);
	func(args[0], args + 1);
	return (0);
}

int						exec_input(char *input)
{
	size_t	i;
	char	**command;
	char	**commands;

	commands = ft_strsplit(input, ';');
	i = -1;
	while (commands[++i])
	{
		// todo: split white space
		command = ft_strsplit(commands[i], ' ');
		exec_command(command);
		darrfree((void **)command);
	}
	darrfree((void **)commands);
	return (0);
}
