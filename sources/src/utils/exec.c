/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/08/03 10:44:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

void static exec_btin(char *command, char **env, int out_fd)
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

void static	exe_cmd(t_exec data, pid_t *pid)
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
		if (execve(data.command, data.args, data.env) == -1)
			perror("Error al ejecutar el comando");
		exit(1);
	}
}

void static	one_comman(t_cmd *cmd, int *pid)
{

	if (cmd->builtin[0])
		exec_btin(cmd->command[0], cmd->env, STDOUT_FILENO);
	else
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
						 STDOUT_FILENO, cmd->env, -1},
				pid);
	if (!cmd->builtin[0])
		wait_pipe(pid, cmd->num_cmd);
}

void static	two_comman(t_cmd *cmd, int *pid)
{
	if (cmd->out[cmd->num_cmd - 2][0] == '>')
	{
		if (cmd->builtin[0])
			exec_btin(cmd->command[0], cmd->env, cmd->filefd[0][OUT]);
		else
			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
							 cmd->filefd[0][OUT], cmd->env, -1},
					&pid[0]);
		close(cmd->filefd[0][OUT]); // NO ES NECESARIO...?
	}
	else
	{
		if (cmd->builtin[0])
		{
			exec_btin(cmd->command[0], cmd->env, cmd->filefd[0][OUT]);
			// close(cmd->filefd[0][IN]);
		}
		else
		{
			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
							 cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
					&pid[0]);
		}
		close(cmd->filefd[0][OUT]);
		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
						 //  STDOUT_FILENO, cmd->env, -1},
						 STDOUT_FILENO, cmd->env, -1},
				&pid[0]);
		// &pid[1]); // OK cat | ls
		close(cmd->filefd[0][IN]);
	}
	if (!cmd->builtin[0] || cmd->out[cmd->num_cmd - 2][0] == '|')
		wait_pipe(pid, cmd->num_cmd);
}

//======TODO OK, pero cat | ls no es como original====================================================
// void static	two_comman(t_cmd *cmd, int *pid)
// {
// 	int	builtin;

// 	builtin = ctrl_builtin(cmd->command[0]);
// 	if (cmd->out[cmd->num_cmd - 2][0] == '>')
// 	{
// 		if (builtin)
// 			filter_builtin(builtin, cmd, cmd->filefd[0][OUT]);
// 		else
// 			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 							 cmd->filefd[0][OUT], cmd->env, -1},
// 					&pid[0]);
// 	}
// 	else
// 	{
// 		if (builtin)
// 			filter_builtin(builtin, cmd, cmd->filefd[0][OUT]);
// 		else
// 		{
// 			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 							 cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
// 					&pid[0]);
// 		}
// 		close(cmd->filefd[0][OUT]);
// 		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
// 						 STDOUT_FILENO, cmd->env, -1},
// 				&pid[0]);
// 		close(cmd->filefd[0][IN]);
// 	}
// 	if (!builtin || cmd->out[cmd->num_cmd - 2][0] == '|')
// 		wait_pipe(pid, cmd->num_cmd);
// }

//=========================================================================

// // ESTE HACE cat | ls como el original
// ls -ls | grep a //  haveces se queda encallado
// void static two_comman(t_cmd *cmd, int *pid)
// {
// 	if (cmd->out[cmd->num_cmd - 2][0] == '>')
// 	{
// 		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 						 cmd->filefd[0][OUT], cmd->env, -1},
// 				&pid[0]);
// 		close(cmd->filefd[0][OUT]);
// 	}
// 	else
// 	{
// 		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 						 cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
// 				&pid[0]);
// 		close(cmd->filefd[0][OUT]);
// 		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
// 						 STDOUT_FILENO, cmd->env, cmd->filefd[0][OUT]},
// 				&pid[1]);
// 		close(cmd->filefd[0][IN]);
// 	}
// 	// if (!builtin) // hay que ponerla para que no se quede un fd..?
// 	wait_pipe(pid, cmd->num_cmd);
// }

// //===============OK==menos cat | ls ==============================================
// void static two_comman(t_cmd *cmd, int *pid)
// {
// 	// int builtin;

// 	// builtin = ctrl_builtin(cmd->command[0]);
// 	if (cmd->out[cmd->num_cmd - 2][0] == '>')
// 	{
// 		if (cmd->builtin[0])
// 			exec_btin(cmd->command[0], cmd->env, cmd->filefd[0][OUT]);

// 		// filter_builtin(cmd->builtin[0], cmd, cmd->filefd[0][OUT]);
// 		else
// 			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 							 cmd->filefd[0][OUT], cmd->env, -1},
// 					&pid[0]);
// 		close(cmd->filefd[0][OUT]);
// 	}
// 	else
// 	{
// 		if (cmd->builtin[0])
// 			exec_btin(cmd->command[0], cmd->env, cmd->filefd[0][OUT]);

// 		// filter_builtin(cmd->builtin[0], cmd, cmd->filefd[0][OUT]);
// 		else
// 		{
// 			exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
// 							 cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
// 					&pid[0]);
// 		}
// 		close(cmd->filefd[0][OUT]);
// 		exe_cmd((t_exec){cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
// 						 STDOUT_FILENO, cmd->env, -1},
// 				&pid[0]);
// 		close(cmd->filefd[0][IN]);
// 	}
// 	if (cmd->out[cmd->num_cmd - 2][0] != '>')
// 		wait_pipe(pid, cmd->num_cmd);
// }
// //=========================================================================

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
		one_comman(cmd, &pid[0]);
	else if (cmd->num_cmd == 2)
		two_comman(cmd, pid);
	else
	{
		// Execute the first command in the pipeline
		printf(MAGENTA "\tFirst %d\n", i - 1);
		exe_cmd((t_exec){cmd->command[0], cmd->args[0], STDIN_FILENO,
						 cmd->filefd[0][OUT], cmd->env, cmd->filefd[0][IN]},
				&pid[0]);
		close(cmd->filefd[0][OUT]);
		while (i < (cmd->num_cmd - 1))
		{
			printf(MAGENTA "\tMiddle %d, %s\n", i, cmd->out[i]);
			exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
							 //   cmd->filefd[i][OUT], cmd->env, cmd->filefd[i - 1][IN]},
							 cmd->filefd[i][OUT], cmd->env, cmd->filefd[i][IN]},
					&pid[i]);
			close(cmd->filefd[i][OUT]);
			i++;
		}
		// Execute the last command in the pipeline
		printf(MAGENTA "\tLast %d\n", i);
		exe_cmd((t_exec){cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
						 STDOUT_FILENO, cmd->env, -1},
				//  STDOUT_FILENO, cmd->env, cmd->filefd[i - 1][IN]},
				&pid[i]);
		// close(cmd->filefd[i - 1][IN]);

		wait_pipe(pid, cmd->num_cmd);
	}

	free(pid);
	return (res);
}
