/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/08/09 14:36:04 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

int static exec_btin(char *command, char **args, char **env)
{
	if (!ft_strncmp(command, "echo", 5))
		echo_btin(NULL, args);
	else if (!ft_strncmp(command, "cd", 3))
		printf("__CD__\n");
	else if (!ft_strncmp(command, "pwd", 4))
		printf("PWD\n");
	else if (!ft_strncmp(command, "export", 7))
		export_btin(NULL, args, env);
	else if (!ft_strncmp(command, "unset", 7))
		unset_btin(NULL, NULL);
	else if (!ft_strncmp(command, "env", 4))
		env_btin(env);
	else if (!ft_strncmp(command, "exit", 7))
		printf("EXIT\n");
	return (1);
}

void static exe_cmd(t_exec data, pid_t *pid)
{
	*pid = fork();
	// TODO
	printf(CYAN "\tpid dentro %d\n", *pid);
	printf(YELLOW "-\n");

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
			// close(cmd->filefd[0][OUT]);
		}
		if (data.out_fd != STDOUT_FILENO)
		{
			dup2(data.out_fd, STDOUT_FILENO);
			close(data.out_fd);
			// close(cmd->filefd[0][IN]);
		}
		close(data.to_close);
		// close(cmd->filefd[1][IN]);
		// close(cmd->filefd[1][OUT]);

		(data.builting && exec_btin(data.command, data.args, data.env));
		(!data.builting && execve(data.command, data.args, data.env));
		// TODO
		// Hacer funcion error y exit
		// if (data.builting)
		// 	exec_btin(data.command, data.env, data.out_fd);
		// else
		// {
		// 	if (execve(data.command, data.args, data.env) == -1)
		// 		perror("Error al ejecutar el comando");
		// }
		exit(1);
	}
}

void static one_comman(t_data *data, t_cmd *cmd, int *pid)
{
	(void)pid;
	if (!ft_strncmp(cmd->command[0], "echo", 5))
		echo_btin(data->env, cmd->args[0]);
	else if (!ft_strncmp(cmd->command[0], "export", 7))
		export_btin(data->env, cmd->args[0], cmd->env);
	else if (!ft_strncmp(cmd->command[0], "unset", 6))
		unset_btin(data->env, cmd->args[0]);
	else
	{
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env, STDIN_FILENO,
						 STDOUT_FILENO, cmd->builtin[0], -1},
				&pid[0]);
		wait_pipe(pid, cmd->num_cmd);
		;
	}
}

void static two_comman(t_cmd *cmd, int *pid)
{
	if (*cmd->out[0] == '>' || *cmd->out[0] == D_REDIR_OUT)
	{
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env,
						 STDIN_FILENO, cmd->filefd[1][OUT], cmd->builtin[0], -1},
				&pid[0]);
	}
	else if (*cmd->out[0] == '<' || *cmd->out[0] == D_REDIR_IN)
	{
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env,
						 cmd->filefd[1][IN], STDOUT_FILENO, cmd->builtin[0], -1},
				&pid[0]);
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env,
						 cmd->filefd[0][IN], STDOUT_FILENO, cmd->builtin[0], -1},
				&pid[1]);
	}
	else
	{
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env, STDIN_FILENO,
						 cmd->filefd[0][OUT], cmd->builtin[0], cmd->filefd[0][IN]},
				&pid[0]);
		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->env, cmd->filefd[0][IN],
						 STDOUT_FILENO, cmd->builtin[1], cmd->filefd[0][OUT]},
				&pid[1]);
		close(cmd->filefd[0][IN]);
		close(cmd->filefd[0][OUT]);
	}
	wait_pipe(pid, cmd->num_cmd);
}

int execute_command(t_data *data, t_cmd *cmd)
{
	int res;
	int i;
	pid_t *pid;

	pid = ft_calloc(cmd->num_cmd, sizeof(pid_t));
	i = 1;
	res = CMD_NOT_FOUND;
	(void)data;
	if (cmd->num_cmd == 1)
		one_comman(data, cmd, &pid[0]);
	else if (cmd->num_cmd == 2)
		two_comman(cmd, pid);
	else
	{
		;
		// // Execute the first command in the pipeline
		// printf(MAGENTA "\tFirst %d\n", i - 1);
		// exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
		// 				 cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
		// 		&pid[0]);
		// close(cmd->filefd[0][OUT]);
		// while (i < (cmd->num_cmd - 1))
		// {
		// 	printf(MAGENTA "\tMiddle %d, %s\n", i, cmd->out[i]);
		// 	exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
		// 					 //   cmd->filefd[i][OUT], cmd->env, cmd->filefd[i - 1][IN]},
		// 					 cmd->filefd[i][OUT], cmd->env, cmd->filefd[i][IN]},
		// 			&pid[i]);
		// 	close(cmd->filefd[i][OUT]);
		// 	i++;
		// }
		// // Execute the last command in the pipeline
		// printf(MAGENTA "\tLast %d\n", i);
		// exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
		// 				 STDOUT_FILENO, cmd->env, -1},
		// 		//  STDOUT_FILENO, cmd->env, cmd->filefd[i - 1][IN]},
		// 		&pid[i]);
		// // close(cmd->filefd[i - 1][IN]);

		// wait_pipe(pid, cmd->num_cmd);
	}

	free(pid);
	return (res);
}
