/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:57:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/03 11:02:36 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft.h"
# include "minishell.h"

# define CMD_NOT_FOUND 127

// enum
// {
// 	FAILED,
// 	ECHO,
// 	CD,
// 	PWD,
// 	EXPORT,
// 	UNSET,
// 	ENV,
// 	EXIT
// };

typedef struct s_exec
{
	char	*command;
	char	**args;
	char	**env;
	int		in_fd;
	int		out_fd;
	int		builting;
	int		to_close;
}			t_exec;

// TODO
// NO USO ESTO ERA PARA EXEC_BTIN
// typedef struct s_btin
// {
// 	int		builtin;
// 	t_cmd	*cmd;
// 	int		in_fd;
// 	int		out_fd;
// 	int		to_close;

// }			t_btin;

// void		print_env(t_list *env);
int			execute_command(t_data *data, t_cmd *cmd);
void		start_export(t_list *env);
void		wait_pipe(pid_t *pid, int num_cmd);

// int			ctrl_builtin(char *command);
void		filter_builtin(int builtin, t_cmd *cmd, int fd);
// int		ft_isnumber(const char *str);
// void exec_btin(char *command, char **env, int out_fd);

//BUILTINGS
void		env_btin(char **env, int fd);

// WORKS
#endif

//
