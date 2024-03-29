/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/08/01 23:36:26 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

void exe_cmd(char *command, char **args, int in_fd, int out_fd, char **env,
			 pid_t *pid, int to_close)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}
	if (*pid == 0)
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
		close(to_close);
		if (execve(command, args, env) == -1)
			perror("Error al ejecutar el comando");
		exit(1);
	}
}

int execute_builtin(t_data *data, t_cmd *cmd)
{
	int res;
	int i;
	int status;
	pid_t *pid;
	int finished;
	int result;

	printf(RED "\t%d\n", cmd->num_cmd);
	pid = calloc(cmd->num_cmd, sizeof(pid_t));
	i = 0;
	res = CMD_NOT_FOUND;
	(void)data;
	// while (i < cmd->num_cmd)
	// {
	if (cmd->num_cmd == 1)
	{
		if (ctrl_builtin(cmd->command[0]))
			// TODO
			// aqui ejecucion de bultings
			printf("tomate\n");
		else
			exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO, STDOUT_FILENO,
					cmd->env, &pid[0], -1);
	}
	else if (cmd->num_cmd == 2)
	{
		if (cmd->out[cmd->num_cmd - 2][0] == '>')
		{
			exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][1], cmd->env, &pid[0], -1);
			close(cmd->filefd[0][1]);
		}
		else
		{
			printf("IN: %d\tOUT: %d\n", cmd->filefd[0][0], cmd->filefd[0][1]);
			exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][1], cmd->env, &pid[0], cmd->filefd[0][0]);
			close(cmd->filefd[0][OUT]);
			exe_cmd(cmd->command[1], cmd->args[1], cmd->filefd[0][0],
					STDOUT_FILENO, cmd->env, &pid[1], cmd->filefd[0][1]);
			close(cmd->filefd[0][IN]);
		}
	}
	else
	{
		printf(MAGENTA "\tPRIMERO %d\n", i);
		while (++i < (cmd->num_cmd - 1))
		{
			printf(MAGENTA "\tLOS DE EN MEDIO %d\n", i);
		}
	}
	// close(cmd->filefd[0][IN]);
	// close(cmd->filefd[0][OUT]);
	i = -1;
	status = 0;
	finished = 0;
	// printf("PID 0: %i\t1: %d\n", pid[0], pid[1]);
	while (finished < cmd->num_cmd)
	{
		i = -1;
		while (++i < cmd->num_cmd)
		{
			result = waitpid(pid[i], &status, WNOHANG);
			if (result > 0)
				finished++;
		}
	}
	printf("End\n");
	// wait(NULL);
	// i++;
	// }
	// execute(cmd);
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?
