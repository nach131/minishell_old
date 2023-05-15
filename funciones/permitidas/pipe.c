/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:20:24 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 22:52:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {
// 	int fd[2]; // Arreglo de descriptores de archivo para la tubería
// 	char message[] = "Hola desde el proceso hijo";

// 	if (pipe(fd) == -1)
// 	{
// 		perror("Error al crear la tubería");
// 		exit(EXIT_FAILURE);
// 	}

// 	pid_t pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("Error al crear el proceso hijo");
// 		exit(EXIT_FAILURE);
// 	}

// 	if (pid == 0)
// 	{
// 		// Proceso hijo
// 		close(fd[0]); // Cierra el extremo de lectura de la tubería

// 		write(fd[1], message, strlen(message) + 1); // Escribe el mensaje en la tubería

// 		close(fd[1]); // Cierra el extremo de escritura de la tubería

// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		// Proceso padre
// 		close(fd[1]); // Cierra el extremo de escritura de la tubería

// 		char received_message[100];
// 		read(fd[0], received_message, sizeof(received_message)); // Lee el mensaje de la tubería

// 		printf("Mensaje recibido: %s\n", received_message);

// 		close(fd[0]); // Cierra el extremo de lectura de la tubería
// 	}

// 	return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd[2]; // Arreglo de descriptores de archivo para la tubería

	if (pipe(fd) == -1)
	{
		perror("Error al crear la tubería");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		// Proceso hijo
		close(fd[0]); // Cierra el extremo de lectura de la tubería

		dup2(fd[1], STDOUT_FILENO); // Redirige la salida estándar al extremo de escritura de la tubería

		// Ejecuta el comando 'ls' y redirige su salida al proceso padre
		execlp("ls", "ls", NULL);

		close(fd[1]); // Cierra el extremo de escritura de la tubería

		exit(EXIT_SUCCESS);
	}
	else
	{
		// Proceso padre
		close(fd[1]); // Cierra el extremo de escritura de la tubería

		dup2(fd[0], STDIN_FILENO); // Redirige la entrada estándar al extremo de lectura de la tubería

		// Lee y muestra la salida del proceso hijo
		char buffer[256];
		ssize_t bytesRead;
		while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
		{
			write(STDOUT_FILENO, buffer, bytesRead);
		}

		close(fd[0]); // Cierra el extremo de lectura de la tubería
	}

	return 0;
}
