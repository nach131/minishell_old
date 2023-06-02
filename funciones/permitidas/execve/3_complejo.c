/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_complejo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:04:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/02 11:20:03 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	pid_t pid;
	int pipefd1[2], pipefd2[2], pipefd3[2];
	int filefd;

	if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1 || pipe(pipefd3) == -1)
	{
		perror("Error al crear las tuberías");
		return 1;
	}

	filefd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo de salida");
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
		// Proceso hijo 1: redirige la salida estándar al extremo de escritura de la primera tubería
		close(pipefd1[0]);
		dup2(pipefd1[1], STDOUT_FILENO);
		close(pipefd1[1]);

		// Ejecuta el comando "cat archivo.txt"
		char *argv[] = {"cat", "archivo.txt", NULL};
		char *env[] = {NULL};
		if (execve("/bin/cat", argv, env) == -1)
		{
			perror("Error al ejecutar el comando cat");
			return 1;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		return 1;
	}

	if (pid == 0)
	{
		// Proceso hijo 2: redirige la entrada desde la primera tubería y la salida hacia la segunda tubería
		close(pipefd1[1]);
		dup2(pipefd1[0], STDIN_FILENO);
		close(pipefd1[0]);

		close(pipefd2[0]);
		dup2(pipefd2[1], STDOUT_FILENO);
		close(pipefd2[1]);

		// Ejecuta el comando "grep 'patrón'"
		char *argv[] = {"grep", "Barcelona", NULL};
		char *env[] = {NULL};
		if (execve("/bin/grep", argv, env) == -1)
		{
			perror("Error al ejecutar el comando grep");
			return 1;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		return 1;
	}

	if (pid == 0)
	{
		// Proceso hijo 3: redirige la entrada desde la segunda tubería y la salida hacia la tercera tubería
		close(pipefd2[1]);
		dup2(pipefd2[0], STDIN_FILENO);
		close(pipefd2[0]);

		close(pipefd3[0]);
		dup2(pipefd3[1], STDOUT_FILENO);
		close(pipefd3[1]);

		// Ejecuta el comando "sed 's/buscar/reemplazar/g'"
		char *argv[] = {"sed", "s/buscar/reemplazar/g", NULL};
		char *env[] = {NULL};
		if (execve("/bin/sed", argv, env) == -1)
		{
			perror("Error al ejecutar el comando sed");
			return 1;
		}
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		return 1;
	}

	if (pid == 0)
	{
		// Proceso hijo 4: redirige la entrada desde la tercera tubería hacia el archivo de salida
		close(pipefd3[1]);
		dup2(pipefd3[0], STDIN_FILENO);
		close(pipefd3[0]);

		dup2(filefd, STDOUT_FILENO);

		// Ejecuta el comando "sort"
		char *argv[] = {"sort", NULL};
		char *env[] = {NULL};
		if (execve("/bin/sort", argv, env) == -1)
		{
			perror("Error al ejecutar el comando sort");
			return 1;
		}
	}

	// Proceso padre: cierra los extremos no utilizados de las tuberías y espera a que los procesos hijos terminen
	close(pipefd1[0]);
	close(pipefd1[1]);
	close(pipefd2[0]);
	close(pipefd2[1]);
	close(pipefd3[0]);
	close(pipefd3[1]);
	close(filefd);

	for (int i = 0; i < 4; i++)
	{
		wait(NULL);
	}

	return 0;
}

// cat archivo.txt | grep "42" | sed "131" | sort > salida.txt

// falta por hacer
// cat archivo.txt | grep "patrón" | sed "s/buscar/reemplazar/g" | sort > salida.txt

// modificar con refacorizacion
