/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:58:51 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/26 19:26:57 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "dictionary.h"

# define USAGE "usage"

# define ECHO_N_FLAG "-n"

# define W_QUOTE "\""
# define S_QUOTE "'"

# define CWD_BUFF_SIZE 2048

typedef int				(*t_exec_func) (char *, char **);

extern t_dict			*g_env;

void					init_env(void);

void					display_prompt(void);

int						exec_input(char *input);

int						cd(char *name, char **args);
int						env(char *name, char **args);
int						echo(char *name, char **args);
int						exitt(char *name, char **args);
int						setenv(char *name, char **args);
int						unsetenv(char *name, char **args);

void					not_implemented(char *name);

#endif
