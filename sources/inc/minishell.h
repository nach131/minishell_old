/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:08:47 by caguerre          #+#    #+#             */
/*   Updated: 2023/06/01 19:45:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "colorsft.h"
# include "error.h"
# include "ft_printf.h"
// # include "functions.h"
# include "libft.h"
# include "readline/history.h"
# include "readline/readline.h"
// # include <errno.h>
// # include <fcntl.h>
// # include <limits.h>
# include <signal.h>
# include <stdbool.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <sys/stat.h>
// # include <sys/types.h>
// # include <sys/wait.h>
// # include <unistd.h>

// VARIABLE GLOBAL

extern int			gbl_exit_code;

// MACROS

// enum
// {
// 	SUCCESS,
// 	FAILURE,
// 	// PATH_MAX = 1024
// };

// STRUCTS

enum				token
{
	NEW_LINE = '\n',
	WHITE_SPACE = ' ',
	DOUBLE_QUOTE = '\"',
	ENV = '$',
	QOUTE = '\'',
	_NULL = '0',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	ESCAPE = '\\',
	PIPE = '|',
};

// typedef struct s_env_prop
// {
// 	char			content;
// 	char			*name;
// }					t_env_prop;

// typedef struct s_env
// {
// 	int				count;
// 	t_env_prop		*var;
// }					t_env;

typedef struct s_fds
{
	char			*in_file;
	char			*out_file;
}					t_fds;

typedef struct s_cmd
{
	char			*command;
	char			**args;
	char			*path;
	t_fds			*fds;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_data
{
	t_list			*env;
	t_cmd			*cmd;
	int				flag[126];
	bool interactive; // poner con flag
	char			*line;
	int				exit;
	int				ret;
	// char			*act_dir;
	// pid_t			pid;
	// char			**path;
	// int				status;
}					t_data;

void				handle_int(int sig);
void				handle_quit(int sig);

t_cmd				*cmd_new(char *str);
void				cmd_add_back(t_cmd **cmd, t_cmd *new);
t_cmd				*cmd_last(t_cmd *cmd);
// void				cmd_clear(t_cmd *cmd);
void				cmd_free(t_cmd *cmd);
void				cmd_iter(t_cmd *cmd, void (*funcion)(void *));

void				parser_space(int flag[], char *line, t_cmd **cmd);
void				ctrl_line(int flag[], char *line);

void				add_export(t_list *env, t_cmd *cmd);

#endif
