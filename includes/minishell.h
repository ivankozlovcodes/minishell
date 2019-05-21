/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:58:51 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/21 06:21:57 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define USAGE "usage"

# define CWD_BUFF_SIZE 2048

struct					s_env
{
	char	*name;
	char	*value;
};
typedef struct s_env	t_env;

extern t_env			*g_env;

void					init_env(void);

void					display_prompt(void);

#endif
