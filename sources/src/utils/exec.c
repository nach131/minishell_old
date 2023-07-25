/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/07/25 22:54:57 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// int exec_cmd(char *cmd, char **args, char **env);

void exe_cmd(char *command, char **args, int in_fd, int out_fd, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}

	if (pid == 0)
	{
		if (in_fd != STDIN_FILENO)
		{
			dup2(in_fd, STDIN_FILENO);
			close(in_fd);
		}

		if (out_fd != STDOUT_FILENO)
		{
			dup2(out_fd, STDOUT_FILENO);
			close(out_fd);
		}

		if (execve(command, args, env) == -1)
			perror("Error al ejecutar el comando");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}

// void execute(t_cmd *cmd)
// {
// 	pid_t pid;

// 	int waitstat;

// 	pid = fork();

// 	if (pid == -1)
// 	{
// 		perror("Error al crear el proceso hijo");
// 		exit(1);
// 	}
// 	if (pid == 0)
// 	{
// 		if (execve(cmd->command[0], cmd->args[0], cmd->env) == -1)
// 			printf("Error, no se pudo ejecutar ls!\n");
// 	}
// 	else
// 	{

// 		// close(cmd->filefd[0][1]);
// 		wait(&waitstat);
// 		// close(cmd->filefd[0][0]);
// 	}
// }

int execute_builtin(t_data *data, t_cmd *cmd)
{
	int res;
	int i = 0;
	res = CMD_NOT_FOUND;

	(void)data;

	// while (i < cmd->num_cmd)
	// {
	if (cmd->num_cmd == 1)
		exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO, STDOUT_FILENO, cmd->env);
	else if (cmd->num_cmd == 2)
	{
		if (cmd->out[cmd->num_cmd - 2][0] == '>')
		{
			exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO, cmd->filefd[0][OUT], cmd->env);
			close(cmd->filefd[0][OUT]);
		}
		else
		{
			exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO, cmd->filefd[0][OUT], cmd->env);
			close(cmd->filefd[0][OUT]);
			exe_cmd(cmd->command[1], cmd->args[1], cmd->filefd[0][IN], STDOUT_FILENO, cmd->env);
			close(cmd->filefd[0][IN]);
		}
	}
	else
	{
		printf(MAGENTA "\tPRIMERO %d\n", i);
	}

	// i++;
	// }

	// execute(cmd);
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?
