/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:36:10 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/25 12:46:16 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/wait.h>

#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

static char		*find_cmd_path(char *cmd_name, struct stat *f)
{
	int				i;
	char			**paths;
	char			*tmp;
	char			*path_var;

	path_var = dict_find(g_env, PATH);
	if (!path_var)
		return (NULL);
	paths = ft_strsplit(path_var, ':');
	i = -1;
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path_var = ft_strjoin(tmp, cmd_name);
		ft_free(1, tmp);
		if (lstat(path_var, f) != -1)
			break ;
		ft_strdel(&path_var);
	}
	darrfree((void **)paths);
	return (path_var);
}

static int	exec_cmd(char *path, char **args)
{
	int		pid;
	int		status;
	char	**envv;

	envv = dict_to_darr(g_env, pair_to_str);
	pid = fork();
	signal(SIGINT, process_signal_handler);
	if (pid < 0)
	{
		ft_printf("minishell: fork failed\n");
		return (1);
	}
	else if (pid == 0)
		execve(path, args - 1, envv);
	else
	{
		wait(&status);
		darrfree((void **)envv);
	}
	return (0);
}

int			run_cmd(char *name, char **args)
{
	struct stat		f;
	int				ret;
	char			*path;

	ret = 0;
	path = find_cmd_path(name, &f);
	if (path)
	{
		if (S_ISREG(f.st_mode))
		{
			if (f.st_mode & S_IXUSR)
				ret = exec_cmd(path, args);
			else
				ft_printf("minishell: Permission denied\n");
		}
		ft_free(1, path);
	}
	else
		ft_printf("minishell: command not found: %s\n", name);
	return (ret);
}
