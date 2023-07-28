/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/07/28 13:17:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

void	exe_cmd(char *command, char **args, int in_fd, int out_fd, char **env,
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

int	ctrl_builtin(char *command)
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
	pid_t	*pid;
	int		i;

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
					cmd->filefd[0][OUT], cmd->env, &pid[0], -1);
			close(cmd->filefd[0][OUT]);
		}
		else
		{
			exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][OUT], cmd->env, &pid[0], cmd->filefd[0][IN]);
			close(cmd->filefd[0][OUT]);
			exe_cmd(cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
					STDOUT_FILENO, cmd->env, &pid[1], cmd->filefd[0][OUT]);
			close(cmd->filefd[0][IN]);
		}
	}
	else
	{
		printf(MAGENTA "\tPRIMERO %d\n", i);
		// Execute the first command in the pipeline
		exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO,
				cmd->filefd[i][OUT], cmd->env, &pid[i], cmd->filefd[i][IN]);
		close(cmd->filefd[i][OUT]);
		i++;
		// Execute commands in the middle of the pipeline
		while (i < (cmd->num_cmd - 1))
		{
			printf(MAGENTA "\tLOS DE EN MEDIO %d, %s\n", i, cmd->out[i]);
			exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
					cmd->filefd[i][OUT], cmd->env, &pid[i], cmd->filefd[i][IN]);
			close(cmd->filefd[i][OUT]);
			close(cmd->filefd[i - 1][IN]);
			i++;
		}
		// Execute the last command in the pipeline
		printf(MAGENTA "\tULTIMO %d\n", i);
		exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
				STDOUT_FILENO, cmd->env, &pid[i], -1);
		close(cmd->filefd[i - 1][IN]);
	}
	wait_pipe(pid, cmd->num_cmd);
	free(pid);
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int		res;
	pid_t	*pid;
	int		i;

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
					cmd->filefd[0][OUT], cmd->env, &pid[0], -1);
			close(cmd->filefd[0][OUT]);
		}
		else
		{
			exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO,
					cmd->filefd[0][OUT], cmd->env, &pid[0], cmd->filefd[0][IN]);
			close(cmd->filefd[0][OUT]);
			exe_cmd(cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
					STDOUT_FILENO, cmd->env, &pid[1], cmd->filefd[0][OUT]);
			close(cmd->filefd[0][IN]);
		}
	}
	else
	{
		printf(MAGENTA "\tPRIMERO %d\n", i);
		// Execute the first command in the pipeline
		exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO,
				cmd->filefd[i][OUT], cmd->env, &pid[i], cmd->filefd[i][IN]);
		close(cmd->filefd[i][OUT]);
		i++;
		// Execute commands in the middle of the pipeline
		while (i < (cmd->num_cmd - 1))
		{
			printf(MAGENTA "\tLOS DE EN MEDIO %d, %s\n", i, cmd->out[i]);
			exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
					cmd->filefd[i][OUT], cmd->env, &pid[i], cmd->filefd[i][IN]);
			close(cmd->filefd[i][OUT]);
			close(cmd->filefd[i - 1][IN]);
			i++;
		}
		// Execute the last command in the pipeline
		printf(MAGENTA "\tULTIMO %d\n", i);
		exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
				STDOUT_FILENO, cmd->env, &pid[i], -1);
		close(cmd->filefd[i - 1][IN]);
	}
	wait_pipe(pid, cmd->num_cmd);
	free(pid);
	return (res);
}

// int	execute_builtin(t_data *data, t_cmd *cmd)
// {
// 	int		res;
// 	pid_t	*pid;
// 	int		i;

// 	res = CMD_NOT_FOUND;
// 	pid = calloc(cmd->num_cmd, sizeof(pid_t));
// 	i = 0;
// 	if (!pid)
// 	{
// 		perror("Error en la asignación de memoria");
// 		return (res);
// 	}
// 	(void)data;
// 	while (i < cmd->num_cmd)
// 	{
// 		if (cmd->num_cmd == 1)
// 		{
// 			if (ctrl_builtin(cmd->command[0]))
// 			{
// 				printf("tomate\n");
// 			}
// 			else
// 			{
// 				exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO,
// 						STDOUT_FILENO, cmd->env, &pid[0], -1);
// 			}
// 			break ;
// 		}
// 		else if (cmd->num_cmd == 2)
// 		{
// 			if (cmd->out[cmd->num_cmd - 2][0] == '>')
// 			{
// 				exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO,
// 						cmd->filefd[0][OUT], cmd->env, &pid[0], -1);
// 				close(cmd->filefd[0][OUT]);
// 			}
// 			else
// 			{
// 				exe_cmd(cmd->command[0], cmd->args[0], STDIN_FILENO,
// 						cmd->filefd[0][OUT], cmd->env, &pid[0],
// 						cmd->filefd[0][IN]);
// 				close(cmd->filefd[0][OUT]);
// 				exe_cmd(cmd->command[1], cmd->args[1], cmd->filefd[0][IN],
// 						STDOUT_FILENO, cmd->env, &pid[1], cmd->filefd[0][OUT]);
// 				close(cmd->filefd[0][IN]);
// 			}
// 			break ;
// 		}
// 		else
// 		{
// 			printf(MAGENTA "\tPRIMERO %d\n", i);
// 			exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO,
// 					cmd->filefd[i][OUT], cmd->env, &pid[i], cmd->filefd[i][IN]);
// 			close(cmd->filefd[i][OUT]);
// 			i++;
// 			while (i < (cmd->num_cmd - 1))
// 			{
// 				printf(MAGENTA "\tLOS DE EN MEDIO %d, %s\n", i, cmd->out[i]);
// 				exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
// 						cmd->filefd[i][OUT], cmd->env, &pid[i],
// 						cmd->filefd[i][IN]);
// 				close(cmd->filefd[i][OUT]);
// 				close(cmd->filefd[i - 1][IN]);
// 				i++;
// 			}
// 			printf(MAGENTA "\tULTIMO %d\n", i);
// 			exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
// 					STDOUT_FILENO, cmd->env, &pid[i], -1);
// 			close(cmd->filefd[i - 1][IN]);
// 			break ;
// 		}
// 	}
// 	wait_pipe(pid, cmd->num_cmd);
// 	free(pid);
// 	return (res);
// }

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int res;
	pid_t *pid;
	int i;

	(void)data;
	res = CMD_NOT_FOUND;
	pid = calloc(cmd->num_cmd, sizeof(pid_t));
	i = 0;
	if (!pid)
	{
		perror("Error en la asignación de memoria");
		return (res);
	}
	while (i < cmd->num_cmd)
	{
		if (ctrl_builtin(cmd->command[i]))
		{
			printf("tomate\n");
			i++;
			continue ;
		}
		else if (cmd->num_cmd == 1)
		{
			exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO, STDOUT_FILENO,
					cmd->env, &pid[i], -1);
		}
		else if (i == 0)
		{
			exe_cmd(cmd->command[i], cmd->args[i], STDIN_FILENO,
					cmd->filefd[i][OUT], cmd->env, &pid[i], -1);
			close(cmd->filefd[i][OUT]);
		}
		else if (i == cmd->num_cmd - 1)
		{
			exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
					STDOUT_FILENO, cmd->env, &pid[i], -1);
			close(cmd->filefd[i - 1][IN]);
		}
		else
		{
			exe_cmd(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN],
					cmd->filefd[i][OUT], cmd->env, &pid[i], -1);
			close(cmd->filefd[i][OUT]);
			close(cmd->filefd[i - 1][IN]);
		}
		i++;
	}
	wait_pipe(pid, cmd->num_cmd);
	free(pid);
	return (res);
}
