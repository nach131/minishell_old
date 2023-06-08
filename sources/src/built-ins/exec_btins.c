/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_btins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/06/08 15:33:02 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// Chequea qué comando estamos introduciendo, si no es un builtin devuelve -1.
//	Si es un builtin ejecuta la función correspondiente.

void	executeCommand(char *command, char **args, int input_fd, int output_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		execve(command, args, NULL);
		perror("Error al ejecutar el comando");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int	res;

	res = CMD_NOT_FOUND;
	(void)data;
	// if (!ft_strncmp(cmd->command, "/usr/bin/env", 13))
	// 	print_env(data->env);
	// else if (!ft_strncmp(cmd->command, "export", 8))
	// 	add_export(data->env, cmd);
	// else if (ft_strncmp(cmd->command, "exit", 5) == 0)
	// 	printf(MAGENTA "esto es EXIT MOTHERF*CKER\n" WHITE);
	// else if (ft_strncmp(cmd->command, "/bin/echo", 10) == 0)
	// 	printf(MAGENTA "esto es ECHO MOTHERF*CKER\n" WHITE);
	// else if (ft_strncmp(cmd->command, "/usr/bin/cd", 12) == 0)
	// 	printf(MAGENTA "esto es CD MOTHERF*CKER\n" WHITE);
	// else if (ft_strncmp(cmd->command, "/bin/pwd", 9) == 0)
	// 	printf(MAGENTA "esto es PWD MOTHERF*CKER\n" WHITE);
	// else if (ft_strncmp(cmd->command, "unset", 6) == 0)
	// 	printf(MAGENTA "esto es UNSET MOTHERF*CKER\n" WHITE);
	// else
	executeCommand(cmd->command, cmd->args, cmd->filefd[0], cmd->filefd[1]);
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?
