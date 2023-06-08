/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:08:47 by caguerre          #+#    #+#             */
/*   Updated: 2023/06/08 20:07:21 by nmota-bu         ###   ########.fr       */
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

enum
{
	IN,
	OUT,
};

typedef struct s_cmd
{
	char			*command;
	char			**args;
	int				filefd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
	// char			*path;
}					t_cmd;

typedef struct s_data
{
	t_list			*env;
	t_list			*token;
	// t_cmd			*cmd;
	// int				flag[126];
	// bool interactive; // poner con flag
	int				exit;
	int				ret;
}					t_data;

void				handle_int(int sig);
void				handle_quit(int sig);

t_cmd				*cmd_new(t_cmd cmd);

void				cmd_add_back(t_cmd **cmd, t_cmd *new);
t_cmd				*cmd_last(t_cmd *cmd);
void				cmd_free(t_cmd *cmd);
void				cmd_iter(t_cmd *cmd, void (*funcion)(void *));

t_list				*parser_space_lst(char *line);
void				ctrl_line(int flag[], char *line);

void				add_export(t_list *env, t_cmd *cmd);
t_cmd				*token_to_pipe(t_list *token);

#endif
