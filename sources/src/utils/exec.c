/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/18 18:17:23 by nmota-bu         ###   ########.fr       */
=======
/*   Updated: 2023/07/17 14:07:26 by nmota-bu         ###   ########.fr       */
>>>>>>> 8c0a9f6c52b9ea9975209e36d9e30e8dbf3fb421
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
		// close(input_fd);
		// close(output_fd);
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		execve(command, args, env);
		perror("Error al ejecutar el comando");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}

int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int	res;
	int	i;

	i = 0;
	res = CMD_NOT_FOUND;
	(void)data;
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
	// ;
	//
	printf(ORANGE "num_command: %d\n" WHITE, cmd->num_cmd);
	if (cmd->num_cmd > 1)
		printf(CYAN "out: %c\n" WHITE, cmd->out[cmd->num_cmd - 2][0]);
	//
	if (cmd->num_cmd == 1)
<<<<<<< HEAD
		// si es 1 no hay que generar pipe
		executeCommand(cmd->command[0], cmd->args[0], STDIN_FILENO, STDOUT_FILENO, cmd->env);
	else if (cmd->num_cmd == 2)
	{
		executeCommand(cmd->command[0], cmd->args[0], STDIN_FILENO, cmd->filefd[0][OUT], cmd->env);
		close(cmd->filefd[0][OUT]);
		if (cmd->out[0][0] == '>')
			executeCommand(cmd->command[1], cmd->args[1], cmd->filefd[0][IN], cmd->filefd[0][OUT], cmd->env);
		// FALTA HACER ALGO PARA QUE SE PARE LA ORDEN CUANDO SESCRIBA EL FICHERO
		else
			executeCommand(cmd->command[1], cmd->args[1], cmd->filefd[0][IN], STDOUT_FILENO, cmd->env);
		close(cmd->filefd[0][IN]);
	}
=======
		executeCommand(cmd->command[0], cmd->args[0], cmd->filefd[0][IN],
					   cmd->filefd[0][OUT], cmd->env);
>>>>>>> 8c0a9f6c52b9ea9975209e36d9e30e8dbf3fb421
	else
	{
		// printf(MAGENTA "\tPRIMERO %d\n", i);
		executeCommand(cmd->command[0], cmd->args[0], STDIN_FILENO, cmd->filefd[0][OUT], cmd->env);
		close(cmd->filefd[0][OUT]);
		while (++i < (cmd->num_cmd - 1))
		{
<<<<<<< HEAD
			executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN], cmd->filefd[i][OUT], cmd->env);
			close(cmd->filefd[i - 1][IN]);
			close(cmd->filefd[i][OUT]);
			// printf(MAGENTA "\tLOS DE EN MEDIO %d\n", i);
		}
		if (cmd->out[0][cmd->num_cmd - 2] == '>')
		{
			executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i - 2][IN], cmd->filefd[i - 1][OUT], cmd->env);
			close(cmd->filefd[i - 1][OUT]);
		}
		executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN], STDOUT_FILENO, cmd->env);
		close(cmd->filefd[i - 1][IN]);
		// printf(MAGENTA "\tULTIMO %d\n", i);
=======
			printf(RED "i: %d\n", i);
			if (i + 1 == 1)
			{
				executeCommand(cmd->command[i], cmd->args[i], STDIN_FILENO,
						cmd->filefd[i][OUT], cmd->env);
				close(cmd->filefd[i][OUT]);
				printf(CYAN "\tPRIMERO %d\n", i);
			}
			else if (i + 1 == cmd->num_cmd)
			{
				executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i
						- 1][IN], STDOUT_FILENO, cmd->env);
				// close(cmd->filefd[i][IN]);
				printf(CYAN "\tULTIMO %d\n", i);
			}
			else
			{
				executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i
						- 1][IN], cmd->filefd[i][OUT], cmd->env);
				printf(CYAN "\tLOS DE EN MEDIO %d\n", i);
			}
			i++;
		}
		printf(GREEN "i: %i\n", i);
		// printf(GREEN "i: %i\n", cmd->filefd[i][IN]);

		// close(cmd->filefd[i - 1][IN]);
>>>>>>> 8c0a9f6c52b9ea9975209e36d9e30e8dbf3fb421
	}
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?

