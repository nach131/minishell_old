/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:08:47 by caguerre          #+#    #+#             */
/*   Updated: 2023/08/08 15:54:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "colorsft.h"
# include "error.h"
// # include "ft_printf.h"
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

enum		token
{
	// 	NEW_LINE = '\n',
	WHITE_SPACE = ' ',
	DOUBLE_QUOTE = '\"',
	// 	DOLLAR = '$',
	QOUTE = '\'',
	// 	_NULL = '0',
	// 	REDIR_IN = '<',
	// 	REDIR_OUT = '>',
	// 	ESCAPE = '\\',
};

enum
{
	PIPE = '|',
	REDIR_IN = '<',
	D_REDIR_IN = 1060,
	REDIR_OUT = '>',
	D_REDIR_OUT = 1062,
};

enum
{
	IN,
	OUT,
};

typedef struct s_cmd
{
	int		num_cmd;
	char	**command;
	char	***args;
	char	**env;
	int		**filefd;
	int		**out;
	int		*builtin;
	// int		**redir;
}			t_cmd;

typedef struct s_data
{
	t_list	*env;
	t_list	*token;
	int		power;
	int		exit;
	int		ret;
	// char pwd -->  getcwd(NULL, 0);
}			t_data;

void		handle_int(int sig);
void		handle_quit(int sig);

t_cmd		*cmd_new(t_cmd cmd);

void		cmd_add_back(t_cmd **cmd, t_cmd *new);
// t_cmd		*cmd_last(t_cmd *cmd);
// void		cmd_free(t_cmd *cmd);
// void		cmd_iter(t_cmd *cmd, void (*funcion)(void *));

t_list		*parser_space_lst(char *line);

t_cmd		*token_to_pipe(t_list *token, t_list *env);
char		*access_file(char *file, char **paths);
char		**env_to_array(t_list *env);
void		remove_quotes(void *content);
// int			count_cmd(t_list *token);
// int			count_to_token_cmd(t_list *token);

char		*find_node_value(t_list *head, const char *target_value);
int			find_env(char *s1, char *s2);

#endif
