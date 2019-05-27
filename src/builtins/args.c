/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:40:16 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/27 03:26:47 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"
#include "memory.h"
#include "ft_math.h"
#include "dstring.h"
#include "ftstring.h"
#include "minishell.h"

static char		*get_env_name(char *arg)
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

static char		*transform_env(char **arg)
{
	char	*ret;
	char	*name;

	name = get_env_name(*arg + 1);
	*arg += ft_strlen(name) + 1;
	ret = strisalnum(name) ? dict_find(g_env, name) : ft_strjoin("$", name);
	ret = ret == NULL ? "" : ret;
	ft_free(1, name);
	return (ret);
}

static char		*transform_special(char **arg)
{
	if ('~' == **arg)
	{
		*arg += 1;
		return (dict_find(g_env, HOME));
	}
	return (NULL);
}

static char		*transform_arg(char *arg)
{
	int			i;
	char		*tmp;
	char		*value;
	t_string	*s;

	s = string_init(0);
	i = -1;
	while ((i = ft_strchrstri(arg, "$~")) >= 0)
	{
		string_appendn(s, arg, i);
		tmp = arg + i;
		if (arg[i] == '$')
			value = transform_env(&tmp);
		else if (arg[i] == '~')
			value = transform_special(&tmp);
		string_append(s, value);
		arg = tmp;
	}
	string_append(s, arg);
	value = s->content;
	string_destroy(s, TRUE);
	return (value);
}

static char		*expand_arg(char *arg)
{
	size_t		i;
	bool		strong;

	i = -1;
	strong = arg[0] == '\'';
	if (!strong)
		return (transform_arg(arg));
	return (ft_strdup(arg));
}

char			**expand_args(char **args)
{
	size_t		i;
	size_t		len;
	char		**ret;

	i = -1;
	len = darrlen((void **)args);
	ret = ft_memalloc(sizeof(char *) * (len + 1));
	while (args[++i])
		ret[i] = expand_arg(args[i]);
	return (ret);
}
