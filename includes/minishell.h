/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:58:51 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/27 03:34:32 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ftstring.h"
# include "dictionary.h"

# include <errno.h>

# define PATH "PATH"

# define HOME "HOME"
# define OLDPWD "OLDPWD"
# define CDHOME "~"
# define CDHOME2 "--"
# define CDOLDPWD "-"

# define ECHO_N_FLAG "-n"

# define W_QUOTE "\""
# define S_QUOTE "'"

# define CWD_BUFF_SIZE 2048

# define EXIT_SIGNAL -1

# define FILE_EXISTS(p, f) (lstat(p, &f) != -1)
# define IS_QUOTE_SHELL(c) (IS_QUOTE(c) || c == '`')

typedef int				(*t_exec_func) (char *, char **);

extern t_dict			*g_env;

enum					e_error
{
	EQOUTE = 1,
};

void					init_env(void);
char					*pair_to_str(t_dict_pair pair);
bool					valid_env_name(char *name);

void					signal_handler(int signo);
void					process_signal_handler(int signo);

void					display_prompt(void);

char					**tokenize(char *input);
int						exec_input(char *input);

char					**expand_args(char **args);

int						cd(char *name, char **args);
int						env(char *name, char **args);
int						echo(char *name, char **args);
int						exitt(char *name, char **args);
int						setenv(char *name, char **args);
int						run_cmd(char *name, char **args);
int						unsetenv(char *name, char **args);

char					*remove_quotes(char *s);
size_t					token_len(const void *token);

void					not_implemented(char *name);

void					print_minishell_message(char *fmt,
	char *msg1, char *msg2);

#endif
