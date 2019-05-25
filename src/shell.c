/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:20:27 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/24 22:37:57 by ivankozlov       ###   ########.fr       */
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
