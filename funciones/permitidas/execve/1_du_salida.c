#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
		// Proceso hijo 1: redirige la salida estándar al extremo de escritura de la tubería
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		// Ejecuta el comando "du -h ~/Desktop/"
		// char *argv[] = {"du", "-h", "/Users/nacho/Desktop/", NULL};
		char *argv[] = {"du", "-h", "../../../../", NULL};
		char *env[] = {NULL};
		if (execve("/usr/bin/du", argv, env) == -1)
		{
			perror("Error al ejecutar el comando du");
			return 1;
		}
	}
	else
	{
		int pipefd2[2];
		if (pipe(pipefd2) == -1)
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
			// Proceso hijo 2: redirige la entrada desde la primera tubería y la salida hacia la segunda tubería
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);

			close(pipefd2[0]);
			dup2(pipefd2[1], STDOUT_FILENO);
			close(pipefd2[1]);

			// Ejecuta el comando "sort -rh"
			char *argv[] = {"sort", "-rh", NULL};
			char *env[] = {NULL};
			if (execve("/usr/bin/sort", argv, env) == -1)
			{
				perror("Error al ejecutar el comando sort");
				return 1;
			}
		}
		else
		{
			// Proceso padre: redirige la entrada desde la segunda tubería al archivo "salida.txt"
			close(pipefd[0]);
			close(pipefd[1]);

			close(pipefd2[1]);
			dup2(pipefd2[0], STDIN_FILENO);
			close(pipefd2[0]);

			int filefd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
			if (filefd == -1)
			{
				perror("Error al abrir el archivo salida.txt");
				return 1;
			}

			dup2(filefd, STDOUT_FILENO);

			// Ejecuta el comando "head -n 5"
			char *argv[] = {"head", "-n", "5", NULL};
			char *env[] = {NULL};
			if (execve("/usr/bin/head", argv, env) == -1)
			{
				perror("Error al ejecutar el comando head");
				return 1;
			}
		}
	}

	return 0;
}

// du -h ~/Desktop/ | sort -rh | head -n 5 > salida.txt
