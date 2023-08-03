/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:39:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/03 09:50:50 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"

// int	ctrl_builtin(char *command)
// {
// 	if (!ft_strncmp(command, "echo", 5))
// 		return (ECHO);
// 	if (!ft_strncmp(command, "cd", 3))
// 		return (CD);
// 	else if (!ft_strncmp(command, "pwd", 4))
// 		return (PWD);
// 	else if (!ft_strncmp(command, "export", 7))
// 		return (EXPORT);
// 	else if (!ft_strncmp(command, "unset", 7))
// 		return (UNSET);
// 	else if (!ft_strncmp(command, "env", 4))
// 		return (ENV);
// 	else if (!ft_strncmp(command, "exit", 7))
// 		return (EXIT);
// 	return (0);
// }

// void	filter_builtin(int builtin, t_cmd *cmd, int out_fd)
// {
// 	// TODO
// 	// aqui la ejecucion de los builtin
// 	if (builtin == ECHO)
// 		printf("ECHO\n");
// 	else if (builtin == CD)
// 		printf("CD\n");
// 	else if (builtin == PWD)
// 		printf("PWD\n");
// 	else if (builtin == EXPORT)
// 		ft_putstr_fd("EXPORT\n", out_fd);
// 	else if (builtin == UNSET)
// 		printf("UNSET\n");
// 	else if (builtin == ENV)
// 		env_btin(cmd->env, out_fd);
// 	else if (builtin == EXIT)
// 		printf("EXIT\n");
// }

void exec_btin(char *command, char **env, int out_fd)
{
	// TODO
	// aqui la ejecucion de los builtin
	if (!ft_strncmp(command, "echo", 5))
		ft_putstr_fd("ECHO\n", out_fd);
	if (!ft_strncmp(command, "cd", 3))
		ft_putstr_fd("CD\n", out_fd);
	else if (!ft_strncmp(command, "pwd", 4))
		ft_putstr_fd("PWD\n", out_fd);
	else if (!ft_strncmp(command, "export", 7))
		ft_putstr_fd("export\n", out_fd);
	else if (!ft_strncmp(command, "unset", 7))
		ft_putstr_fd("unset\n", out_fd);
	else if (!ft_strncmp(command, "env", 4))
		env_btin(env, out_fd);
	else if (!ft_strncmp(command, "exit", 7))
		ft_putstr_fd("exit\n", out_fd);
}
