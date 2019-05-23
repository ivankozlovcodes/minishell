/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:22 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/23 13:25:32 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"

int		env(char *name, char **args)
{
	size_t		i;

	i = -1;
	while (g_env[++i].name)
		ft_printf("%s=%s\n", g_env[i].name, g_env[i].value);
	return (0);
}
