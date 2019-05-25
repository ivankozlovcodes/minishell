/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:57 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/24 22:37:48 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exitt(char *name, char **args)
{
	(void)name;
	(void)args;
	return (EXIT_SIGNAL);
}
