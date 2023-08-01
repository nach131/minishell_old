/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/08/01 19:45:30 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

void static	exe_cmd(t_exec data, pid_t *pid)
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

void	exec_btin(t_btin data, pid_t *pid)
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
		filter_builtin(data.builtin, data.cmd, data.out_fd);
		// if (execve(data.command, data.args, data.env) == -1)
		// 	perror("Error al ejecutar el comando");
		exit(1);
	}
}

void static	one_comman(t_cmd *cmd, int *pid)
{
	int	builtin;

	builtin = ctrl_builtin(cmd->command[0]);
	if (builtin)
		filter_builtin(builtin, cmd, STDOUT_FILENO);
	else
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
				STDOUT_FILENO, cmd->env, -1}, pid);
	// &pid[0]);
	if (!builtin)
		wait_pipe(pid, cmd->num_cmd);
}

// void static	one_comman(t_cmd *cmd, int *pid)
// {
// 	int	builtin;

// 	builtin = ctrl_builtin(cmd->command[0]);
// 	if (builtin)
// 	{
// 		// filter_builtin(builtin, cmd, STDOUT_FILENO);
// 		exec_btin((t_btin){
// 						builtin,
// 						cmd,
// 						STDIN_FILENO,
// 						STDOUT_FILENO,
// 						-1},
// 					pid);
// 	}
// 	else
// 		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 				STDOUT_FILENO, cmd->env, -1}, pid);
// 	// &pid[0]);
// 	// if (!builtin)
// 	wait_pipe(pid, cmd->num_cmd);
// }

void static	two_comman(t_cmd *cmd, int *pid)
{
	int	builtin;

	builtin = ctrl_builtin(cmd->command[0]);
	if (cmd->out[cmd->num_cmd - 2][0] == '>')
	{
		if (builtin)
			filter_builtin(builtin, cmd, cmd->filefd[0][OUT]);
		else
			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][OUT], cmd->env, -1}, &pid[0]);
		close(cmd->filefd[0][OUT]);
	}
	else
	{
		if (builtin)
			filter_builtin(builtin, cmd, cmd->filefd[0][OUT]);
		else
		{
			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
					&pid[0]);
		}
		close(cmd->filefd[0][OUT]);
		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
				STDOUT_FILENO, cmd->env, -1}, &pid[0]);
		close(cmd->filefd[0][IN]);
	}
	if (cmd->out[cmd->num_cmd - 2][0] != '>')
		wait_pipe(pid, cmd->num_cmd);
}

// ESTE HACE cat | ls como el original
// void static	two_comman(t_cmd *cmd, int *pid)
// {
// 	if (cmd->out[cmd->num_cmd - 2][0] == '>')
// 	{
// 		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 				cmd->filefd[0][OUT], cmd->env, -1},
// 				&pid[0]);
// 		close(cmd->filefd[0][OUT]);
// 	}
// 	else
// 	{
// 		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 				cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
// 				&pid[0]);
// 		close(cmd->filefd[0][OUT]);
// 		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
// 				STDOUT_FILENO, cmd->env, cmd->filefd[0][OUT]},
// 				&pid[1]);
// 		close(cmd->filefd[0][IN]);
// 	}
// 	// if (!builtin) // hay que ponerla para que no se quede un fd..?
// 	wait_pipe(pid, cmd->num_cmd);
// }

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int		res;
	int		i;
	pid_t	*pid;

	pid = calloc(cmd->num_cmd, sizeof(pid_t));
	i = 1;
	res = CMD_NOT_FOUND;
	(void)data;
	if (cmd->num_cmd == 1)
		one_comman(cmd, &pid[0]);
	else if (cmd->num_cmd == 2)
		two_comman(cmd, pid);
	else
	{
		// Execute the first command in the pipeline
		printf(MAGENTA "\tPRIMERO %d\n", i - 1);
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
						 cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
				&pid[0]);
		close(cmd->filefd[0][OUT]);
		while (i < (cmd->num_cmd - 1))
		{
			printf(MAGENTA "\tLOS DE EN MEDIO %d, %s\n", i, cmd->out[i]);
			exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
							 cmd->filefd[i][OUT], cmd->env, cmd->filefd[i - 1][IN]},
					&pid[i]);
			close(cmd->filefd[i][OUT]);
			i++;
		}
		// Execute the last command in the pipeline
		printf(MAGENTA "\tULTIMO %d\n", i);
		exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
						 STDOUT_FILENO, cmd->env, cmd->filefd[i - 1][IN]},
				&pid[i]);
		close(cmd->filefd[i - 1][OUT]);

		wait_pipe(pid, cmd->num_cmd);
	}
	// {
	// Execute the first command in the pipeline
	// exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
	// 		cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
	// 		&pid[0]);
	// close(cmd->filefd[0][OUT]);
	// Execute commands in the middle of the pipeline
	// while (i < (cmd->num_cmd - 1))
	// {
	// 	exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i
	// 			- 1][IN], cmd->filefd[i][OUT], cmd->env,
	// 			cmd->filefd[i][IN]},
	// 			&pid[i]);
	// 	close(cmd->filefd[i][OUT]);
	// 	close(cmd->filefd[i - 1][IN]);
	// 	i++;
	// }
	// // Execute the last command in the pipeline
	// if (cmd->out[i - 1][0] != '>')
	// {
	// 	exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i
	// 			- 1][IN], STDOUT_FILENO, cmd->env, -1},
	// 			&pid[i]);
	// 	close(cmd->filefd[i - 1][IN]);
	// }
	// // if (!builtin) // hay que ponerla para que no se quede un fd..?
	// wait_pipe(pid, cmd->num_cmd);
	// }
	free(pid);
	return (res);
}

//=========================================================================

//=========================================================================
