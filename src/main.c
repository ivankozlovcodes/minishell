/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:31:25 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/24 22:40:32 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "ft_printf.h"
#include "dstring.h"
#include "memory.h"

static char		*get_input(void)
{
	t_string	*s;
	char		buf[2];
	int			ret;

	buf[1] = 0;
	s = string_init(0);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
		string_append(s, buf);
	return (string_destroy(s, TRUE));
}

int				main(void)
{
	int		ret;
	char	*input;

	init_env();
	while (1)
	{
		display_prompt();
		input = get_input();
		ft_printf("input |%s|\n", input);
		ret = exec_input(input);
		ft_free(1, input);
		if (ret == EXIT_SIGNAL)
			break ;
	}
	dict_destroy(g_env);
	return (0);
}
