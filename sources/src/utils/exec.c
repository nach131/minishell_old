/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/07/25 10:57:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// void	executeCommand(char *command, char **args, int input_fd, int output_fd,
// 		char **env)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("Error al crear el proceso hijo");
// 		exit(1);
// 	}
// 	if (pid == 0)
// 	{
// 		dup2(input_fd, STDIN_FILENO);
// 		dup2(output_fd, STDOUT_FILENO);
// 		execve(command, args, env);
// 		perror("Error al ejecutar el comando");
// 		exit(1);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 	}
// }

void	executeCommand(char *command, char **args, int input_fd, int output_fd,
		char **env)
{
	pid_t pid;

	int waitstat;

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}

	if (pid == 0)
	{
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}

		if (output_fd != STDOUT_FILENO)
		{
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}

		execve(command, args, env);
		perror("Error al ejecutar el comando");
		exit(1);
	}
	else
	{

		waitstat = WIFEXITED(pid);
		wait(&waitstat);
		printf("Finished Executing!\n");
	}
}

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int	res;
	int	i;

	i = 0;
	res = CMD_NOT_FOUND;

	(void)data;
	(void)cmd;
	printf("nuevo exec\n");
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?
