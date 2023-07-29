/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/07/29 20:00:51 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// void	exe_cmd(char *command, char **args, int in_fd, int out_fd, char **env,
// 		pid_t *pid, int to_close)
// {
// 	*pid = fork();
// 	if (*pid == -1)
// 	{
// 		perror("Error al crear el proceso hijo");
// 		exit(1);
// 	}
// 	if (*pid == 0)
// 	{
// 		if (in_fd != STDIN_FILENO)
// 		{
// 			dup2(in_fd, STDIN_FILENO);
// 			close(in_fd);
// 		}
// 		if (out_fd != STDOUT_FILENO)
// 		{
// 			dup2(out_fd, STDOUT_FILENO);
// 			close(out_fd);
// 		}
// 		close(to_close);
// 		if (execve(command, args, env) == -1)
// 			perror("Error al ejecutar el comando");
// 		exit(1);
// 	}
// }
// void	exe_cmd(char *command, char **args, int in_fd, int out_fd, char **env,
// 		pid_t *pid, int to_close)
void	exe_cmd(t_exec data, pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}
	if (*pid == 0)
	{
		if (data.in_fd != STDIN_FILENO)
		{
			dup2(data.in_fd, STDIN_FILENO);
			close(data.in_fd);
		}
		if (data.out_fd != STDOUT_FILENO)
		{
			dup2(data.out_fd, STDOUT_FILENO);
			close(data.out_fd);
		}
		close(data.to_close);
		if (execve(data.command, data.args, data.env) == -1)
			perror("Error al ejecutar el comando");
		exit(1);
	}
}

int static	ctrl_builtin(char *command)
{
	if (!ft_strncmp(command, "echo", 5))
		return (1);
	if (!ft_strncmp(command, "cd", 3))
		return (1);
	else if (!ft_strncmp(command, "pwd", 4))
		return (1);
	else if (!ft_strncmp(command, "export", 7))
		return (1);
	else if (!ft_strncmp(command, "unset", 7))
		return (1);
	else if (!ft_strncmp(command, "env", 4))
		return (1);
	else if (!ft_strncmp(command, "exit", 7))
		return (1);
	return (0);
}

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int		res;
	int		i;
	pid_t	*pid;

	pid = calloc(cmd->num_cmd, sizeof(pid_t));
	i = 0;
	res = CMD_NOT_FOUND;
	(void)data;
	if (cmd->num_cmd == 1)
	{
		if (ctrl_builtin(cmd->command[0]))
			// TODO
			// aqui ejecucion de bultings
			printf("tomate\n");
		else
			// exe_cmd(exec_data, &pid[0]);
			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
					STDOUT_FILENO, cmd->env, -1},
					&pid[0]);
	}
	else if (cmd->num_cmd == 2)
	{
		if (cmd->out[cmd->num_cmd - 2][0] == '>')
		{
			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][OUT], cmd->env, -1},
					&pid[0]);
			close(cmd->filefd[0][OUT]);
		}
		else
		{
			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
					&pid[0]);
			close(cmd->filefd[0][OUT]);
			exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
					STDOUT_FILENO, cmd->env, cmd->filefd[0][OUT]},
					&pid[1]);
			close(cmd->filefd[0][IN]);
		}
	}
	else
	{
		printf(MAGENTA "\tPRIMERO %d\n", i);
		// Execute the first command in the pipeline
		exe_cmd((t_exec){cmd->command[i], cmd->args[i], STDIN_FILENO,
				cmd->filefd[i][OUT], cmd->env, cmd->filefd[i][IN]},
				&pid[i]);
		close(cmd->filefd[i][OUT]);
		i++;
		// Execute commands in the middle of the pipeline
		while (i < (cmd->num_cmd - 1))
		{
			printf(MAGENTA "\tLOS DE EN MEDIO %d, %s\n", i, cmd->out[i]);
			exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i
					- 1][IN], cmd->filefd[i][OUT], cmd->env,
					cmd->filefd[i][IN]},
					&pid[i]);
			close(cmd->filefd[i][OUT]);
			close(cmd->filefd[i - 1][IN]);
			i++;
		}
		// Execute the last command in the pipeline
		printf(MAGENTA "\tULTIMO %d\n", i);
		if (cmd->out[i - 1][0] != '>')
		{
			exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i
					- 1][IN], STDOUT_FILENO, cmd->env, -1},
					&pid[i]);
			close(cmd->filefd[i - 1][IN]);
		}
	}
	wait_pipe(pid, cmd->num_cmd);
	free(pid);
	return (res);
}

// ====================

// // Función para ejecutar un solo comando sin redirección de entrada/salida
// void execute_single_cmd(t_cmd *cmd, int index, pid_t *pid)
// {
// 	exe_cmd(cmd->command[index], cmd->args[index], STDIN_FILENO,
// 			STDOUT_FILENO, cmd->env, &exec.pid[index], -1);
// }

// // Función para ejecutar dos comandos en pipeline
// void execute_pipeline(t_cmd *cmd, pid_t *pid)
// {
// 	exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO,
// 			cmd->filefd[0][OUT], cmd->env, &exec.pid[0], -1);
// 	close(cmd->filefd[0][OUT]);

// 	exe_cmd(cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
// 			STDOUT_FILENO, cmd->env, &exec.pid[1], cmd->filefd[0][OUT]);
// 	close(cmd->filefd[0][IN]);
// }

// // Función para ejecutar los comandos en el medio de un pipeline
// void execute_middle_cmds(t_cmd *cmd, int index, pid_t *pid)
// {
// 	exe_cmd(cmd->command[index], cmd->args[index], cmd->filefd[index - 1][IN],
// 			cmd->filefd[index][OUT], cmd->env, &exec.pid[index],
// cmd->filefd[index][IN]);
// 	close(cmd->filefd[index][OUT]);
// 	close(cmd->filefd[index - 1][IN]);
// }

// int execute_builtin(t_data *data, t_cmd *cmd)
// {
// 	int res;
// 	pid_t *pid;
// 	int i;

// 	(void)data;
// 	pid = calloc(cmd->num_cmd, sizeof(pid_t));
// 	i = 0;
// 	res = CMD_NOT_FOUND;

// 	if (cmd->num_cmd == 1)
// 	{
// 		if (ctrl_builtin(cmd->command[0]))
// 			printf("tomate\n");
// 		else
// 			execute_single_cmd(cmd, i, pid);
// 	}
// 	else if (cmd->num_cmd == 2)
// 	{
// 		if (cmd->out[cmd->num_cmd - 2][0] == '>')
// 		{
// 			execute_single_cmd(cmd, 0, pid);
// 			close(cmd->filefd[0][OUT]);
// 		}
// 		else
// 		{
// 			execute_pipeline(cmd, pid);
// 		}
// 	}
// 	else
// 	{
// 		// Execute the first command in the pipeline
// 		execute_single_cmd(cmd, i, pid);
// 		close(cmd->filefd[i][OUT]);
// 		i++;

// 		// Execute commands in the middle of the pipeline
// 		while (i < (cmd->num_cmd - 1))
// 		{
// 			execute_middle_cmds(cmd, i, pid);
// 			i++;
// 		}

// 		// Execute the last command in the pipeline
// 		if (cmd->out[i - 1][0] != '>')
// 		{
// 			exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i
// - 1][IN],
// 					STDOUT_FILENO, cmd->env, &exec.pid[i], -1);
// 			close(cmd->filefd[i - 1][IN]);
// 		}
// 	}

// 	wait_pipe(pid, cmd->num_cmd);
// 	free(pid);
// 	return (res);
// }

// CMD_NOT_FOUND ES 127 NO -1 POR...?

// TODO
// ls -la | grep i | grep b | grep lib
// CUIDADO AVECES "end" de wait_pipe antes que el ultimo comando..?
// y despues se queda a falta de INTRO

// echo uno | echo dos
// se queda a la espera hay que pulsar INTRO
