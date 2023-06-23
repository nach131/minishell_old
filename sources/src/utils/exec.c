/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/06/23 13:38:34 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

void	executeCommand(char *command, char **args, int input_fd, int output_fd,
		char **env)
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
		execve(command, args, env);
		perror("Error al ejecutar el comando");
		exit(1);
	}
	else
		wait(NULL);
}

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int	res;

	res = CMD_NOT_FOUND;
	(void)data;
	(void)cmd;
	// if (!ft_strncmp(cmd->command, "env", 4))
	// 	print_env(data->env);
	// else if (!ft_strncmp(cmd->command, "echo", 5))
	// 	printf(MAGENTA "esto es ECHO MOTHERF*CKER\n" WHITE);
	// else if (ft_strncmp(cmd->command, "cd", 3) == 0)
	// 	printf(MAGENTA "esto es CD MOTHERF*CKER\n" WHITE);
	// else if (ft_strncmp(cmd->command, "pwd", 4) == 0)
	// 	printf(MAGENTA "esto es PWD MOTHERF*CKER\n" WHITE);
	// else if (!ft_strncmp(cmd->command, "export", 8))
	// 	add_export(data->env, cmd);
	// else if (ft_strncmp(cmd->command, "unset", 6) == 0)
	// 	printf(MAGENTA "esto es UNSET MOTHERF*CKER\n" WHITE);
	// else if (ft_strncmp(cmd->command, "exit", 5) == 0)
	// 	printf(MAGENTA "esto es EXIT MOTHERF*CKER\n" WHITE);
	// else
	executeCommand(cmd->command[0], cmd->args[0], cmd->filefd[0][0],
			cmd->filefd[0][1], cmd->env);
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?
