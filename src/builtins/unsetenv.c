/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:21:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/25 04:27:11 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"

int		unsetenv(char *name, char **args)
{
	if (!*args)
		ft_printf("unsetenv: Too few arguments.\n");
	else
		while (*args)
		{
			dict_remove(g_env, *args);
			args++;
		}
	return (0);
}
