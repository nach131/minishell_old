/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:08:47 by caguerre          #+#    #+#             */
/*   Updated: 2023/05/19 08:42:02 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "colorsft.h"
# include "error.h"
# include "ft_printf.h"
# include "functions.h"
# include "libft.h"
# include "readline/history.h"
# include "readline/readline.h"
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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

enum				parsec
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
	bool			interactive;
	t_cmd			*cmd;
	char			*line;
	pid_t			pid;
}					t_data;

#endif
