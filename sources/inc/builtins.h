/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:57:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/29 19:36:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft.h"
# include "minishell.h"

# define CMD_NOT_FOUND 127

typedef struct s_exec
{
	char *command;
	char **args;
	int in_fd;
	int out_fd;
	char **env;
	int to_close;
} t_exec;

void	print_env(t_list *env);
int		execute_builtin(t_data *data, t_cmd *cmd);
void	start_export(t_list *env);
void wait_pipe(pid_t *pid, int num_cmd);

// int		ft_isnumber(const char *str);

// WORKS

#endif
