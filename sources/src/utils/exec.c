/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/08/03 17:09:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

int static exec_btin(char *command, char **env, int out_fd)
{
	// TODO
	// quitar fd de la funcion si al final no la necesito para
	// las redirecciones

	if (!ft_strncmp(command, "echo", 5))
		ft_putstr_fd("ECHO\n", out_fd);
	if (!ft_strncmp(command, "cd", 3))
		ft_putstr_fd("CD\n", out_fd);
	else if (!ft_strncmp(command, "pwd", 4))
		ft_putstr_fd("PWD\n", out_fd);
	else if (!ft_strncmp(command, "export", 7))
		export_btin(NULL);
	else if (!ft_strncmp(command, "unset", 7))
		ft_putstr_fd("unset\n", out_fd);
	else if (!ft_strncmp(command, "env", 4))
		env_btin(env, out_fd);
	else if (!ft_strncmp(command, "exit", 7))
		ft_putstr_fd("exit\n", out_fd);
	return (1);
}

void static exe_cmd(t_exec data, pid_t *pid)
{
	*pid = fork();
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
		}
		if (data.out_fd != STDOUT_FILENO)
		{
			dup2(data.out_fd, STDOUT_FILENO);
			close(data.out_fd);
		}
		close(data.to_close);

		(data.builting && exec_btin(data.command, data.env, data.out_fd));
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
	(void)data;

	if (!ft_strncmp(cmd->command[0], "export", 7))
	{
		// ft_lstadd_back(&data->env, ft_lstnew("TOMATE_ONE=one_comman"));
		export_btin(data->env);
	}
	// printf("export\n");
	else
	{
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env, STDIN_FILENO,
						 STDOUT_FILENO, cmd->builtin[0], -1},
				&pid[0]);
		wait_pipe(pid, cmd->num_cmd);
	}
}

void static two_comman(t_cmd *cmd, int *pid)
{
	if (cmd->out[cmd->num_cmd - 2][0] == '>')
	{
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env,
						 STDIN_FILENO, cmd->filefd[0][OUT], cmd->builtin[0], -1},
				&pid[0]);
		close(cmd->filefd[0][OUT]); // NO ES NECESARIO...?
	}
	else
	{
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], cmd->env, STDIN_FILENO,
						 cmd->filefd[0][OUT], cmd->builtin[0], cmd->filefd[0][IN]},
				&pid[0]);
		close(cmd->filefd[0][OUT]);
		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->env, cmd->filefd[0][IN],
						 STDOUT_FILENO, cmd->builtin[1], -1},
				&pid[0]);
		// &pid[1]); // OK cat | ls
		close(cmd->filefd[0][IN]);
	}
	wait_pipe(pid, cmd->num_cmd);
}

int execute_command(t_data *data, t_cmd *cmd)
{
	int res;
	int i;
	pid_t *pid;

	pid = calloc(cmd->num_cmd, sizeof(pid_t));
	printf(RED "\tpid %d\n" WHITE, pid[0]);
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
