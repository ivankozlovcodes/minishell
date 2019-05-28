/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:22 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/28 13:28:08 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"

int		env(char *name, char **args)
{
	(void)name;
	(void)args;
	dict_print(g_env, "%s=%s\n");
	return (0);
}
