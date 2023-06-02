#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void executeCommand(char *command, int pipefd[2])
{
	pid_t pid;

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}

	if (pid == 0)
	{
		// Redirige la salida estándar al extremo de escritura de la tubería
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		// Ejecuta el comando
		char *argv[] = {"bash", "-c", command, NULL};
		char *env[] = {NULL};
		if (execve("/bin/bash", argv, env) == -1)
		{
			perror("Error al ejecutar el comando");
			exit(1);
		}
	}
	else
	{
		// Espera a que el proceso hijo termine
		wait(NULL);
	}
}

int main()
{
	int pipefd[2];
	int filefd;

	executeCommand("find ~/Desktop/ -type f -mtime 0", pipefd);
	executeCommand("sort", pipefd);
	close(pipefd[1]);

	filefd = open("archivos_modificados.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo archivos_modificados.txt");
		exit(1);
	}

	dup2(pipefd[0], STDIN_FILENO);
	dup2(filefd, STDOUT_FILENO);
	close(pipefd[0]);

	printf("Archivo creado correctamente.\n");

	return 0;
}

// find ~/Desktop/ -type f -mtime 0 | sort > archivos_modificados.txt
