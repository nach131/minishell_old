/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/07/21 17:49:11 by nmota-bu         ###   ########.fr       */
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
	////
	printf(ORANGE "num_command: %d\n" WHITE, cmd->num_cmd);
	if (cmd->num_cmd > 1)
		printf(CYAN "out: %c\n" WHITE, cmd->out[cmd->num_cmd - 2][0]);
	////
	if (cmd->num_cmd == 1)
		// si es 1 no hay que generar pipe
		executeCommand(cmd->command[0], cmd->args[0], STDIN_FILENO, STDOUT_FILENO, cmd->env);
	else if (cmd->num_cmd == 2)
	{

		if (cmd->out[0][0] == '>')
		{
			executeCommand(cmd->command[0], cmd->args[0], STDIN_FILENO, cmd->filefd[0][OUT], cmd->env);
			close(cmd->filefd[0][OUT]);
		}
		else
		{
			executeCommand(cmd->command[0], cmd->args[0], STDIN_FILENO, cmd->filefd[0][OUT], cmd->env);
			close(cmd->filefd[0][OUT]);
			executeCommand(cmd->command[1], cmd->args[1], cmd->filefd[0][IN], STDOUT_FILENO, cmd->env);
			close(cmd->filefd[0][IN]);
		}
	}
	else
	{
		// printf(MAGENTA "\tPRIMERO %d\n", i);
		// Si hay más de dos comandos
		// Primero ejecutamos el primer comando con la entrada estándar y el primer pipe de salida
		executeCommand(cmd->command[0], cmd->args[0], STDIN_FILENO, cmd->filefd[0][OUT], cmd->env);
		close(cmd->filefd[0][OUT]);

		while (++i < (cmd->num_cmd - 1))
		{
			// Ejecutamos los comandos intermedios con sus respectivos pipes de entrada y salida
			executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN], cmd->filefd[i][OUT], cmd->env);
			close(cmd->filefd[i - 1][IN]);
			close(cmd->filefd[i][OUT]);
			// printf(MAGENTA "\tLOS DE EN MEDIO %d\n", i);
		}
		if (cmd->out[0][cmd->num_cmd - 2] == '>')
		{
			// Si el último operador de redirección es '>', ejecutamos el último comando con el penúltimo pipe de entrada y el último pipe de salida
			executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i - 2][IN], cmd->filefd[i - 1][OUT], cmd->env);
			close(cmd->filefd[i - 1][OUT]);
		}
		// Si el último operador de redirección no es '>', ejecutamos el último comando con el penúltimo pipe de entrada y la salida estándar
		executeCommand(cmd->command[i], cmd->args[i], cmd->filefd[i - 1][IN], STDOUT_FILENO, cmd->env);
		close(cmd->filefd[i - 1][IN]);
		// printf(MAGENTA "\tULTIMO %d\n", i);
	}
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?

