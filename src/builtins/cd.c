/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:41:02 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/26 18:50:08 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/param.h>

#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

static void		cd_error(char *path)
{
	char	*msg;

	if (access(path, F_OK) == -1)
		msg = "no such file or directory";
	else if (access(path, R_OK) == -1)
		msg = "permission denied";
	else
		msg = "not a directory";
	ft_printf("cd: %s: %s\n", msg, path);
}

static char		*get_path(char **args)
{
	char	*ret;
	char	*home;
	char	*oldpwd;

	ret = *args;
	home = dict_find(g_env, HOME);
	oldpwd = dict_find(g_env, OLDPWD);
	if (!ret || ft_strequ(ret, CDHOME) || ft_strequ(ret, CDHOME2))
		ret = home;
	else if (ft_strequ(ret, CDOLDPWD))
		ret = oldpwd;
	return (ret);
}

int				cd(char *name, char **args)
{
	int		ret;
	char	*path;
	char	cwd[MAXPATHLEN];

	(void)name;
	ft_bzero(cwd, MAXPATHLEN);
	path = get_path(args);
	getcwd(cwd, MAXPATHLEN);
	ret = chdir(path);
	if (ret == 0)
		dict_insert(g_env, OLDPWD, cwd);
	else
		cd_error(path);
	return (0);
}
