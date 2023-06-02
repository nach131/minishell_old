/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con_pip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:39:39 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/01 11:39:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		return 1;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		return 1;
	}

	if (pid == 0)
	{
		// Proceso hijo: redirige la salida estándar al extremo de escritura de la tubería
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		// Ejecuta el comando "cat archivo.txt"
		char *argv[] = {"cat", "archivo.txt", NULL};
		char *env[] = {NULL};
		if (execve("/bin/cat", argv, env) == -1)
		{
			perror("Error al ejecutar el comando cat");
			return 1;
		}
	}
	else
	{
		// Proceso padre: redirige la entrada estándar al extremo de lectura de la tubería
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);

		// Ejecuta el comando "wc -l"
		char *argv[] = {"wc", "-l", NULL};
		char *env[] = {NULL};
		if (execve("/usr/bin/wc", argv, env) == -1)
		{
			perror("Error al ejecutar el comando wc");
			return 1;
		}
	}

	return 0;
}
