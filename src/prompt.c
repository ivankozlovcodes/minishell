/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 06:00:59 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/21 06:18:09 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "colors.h"
#include "ft_printf.h"

void	display_prompt(void)
{
	char	cwd[CWD_BUFF_SIZE + 1];

	getcwd(cwd, CWD_BUFF_SIZE);
	ft_printf("%s%s%s > ", BLU, cwd, RESET);
}
