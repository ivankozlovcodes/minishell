/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:37 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/28 13:27:46 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "memory.h"
#include "dstring.h"
#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

int				echo(char *name, char **args)
{
	bool	printnl;

	(void)name;
	printnl = !ft_strequ(*args, ECHO_N_FLAG);
	args += !printnl;
	while (*args)
	{
		ft_printf("%s%s", *args, *(args + 1) ? " " : "");
		args++;
	}
	if (printnl)
		ft_printf("\n");
	return (0);
}
