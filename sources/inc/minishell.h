/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:08:47 by caguerre          #+#    #+#             */
/*   Updated: 2023/05/10 17:28:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # include "../lib/libft/inc/colors.h"
// # include "../lib/libft/inc/colors.h"
// # include "../lib/libft/inc/error.h"
// # include "../lib/libft/inc/ft_printf.h"
// # include "libft.h"
// # include "../lib/libft/inc/libft.h"
# include "functions.h"
# include "libft.h"
// # include "history.h"
// # include "readline.h"
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

extern int		gbl_exit_code;

// MACROS

// enum
// {
// 	SUCCESS,
// 	FAILURE,
// 	// PATH_MAX = 1024
// };

// STRUCTS

typedef struct s_fds
{
	char		*in_file;
	char		*out_file;
}				t_fds;

typedef struct s_command
{
	char		*command;
	char		**args;
	char		*path;
	t_fds		*fds;
}				t_command;

typedef struct s_data
{
	bool		interactive;
	t_command	*cmd;
	pid_t		pid;
}				t_data;

#endif
