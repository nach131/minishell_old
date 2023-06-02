#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../../sources/lib/libft/inc/libft.h"

void executeCommand(char *command[], char *env[], int pipefd[2])
{
	pid_t pid;

	char *cmd;

	cmd = ft_strjoin("/usr/bin/", command[0]);

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
		// char *argv[] = {command, NULL};
		// char *env[] = {NULL};
		if (execve(cmd, command, env) == -1)
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

	char *argv_1[] = {"du", "-h", "/Users/nacho/Desktop/", NULL};
	char *argv_2[] = {"sort", "-rh", NULL};
	char *argv_3[] = {"head", "-n", "5", NULL};
	char *env[] = {NULL};

	executeCommand(argv_1, env, pipefd);
	// executeCommand(argv_2, env, pipefd);
	// close(pipefd[1]);

	// filefd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	// if (filefd == -1)
	// {
	// 	perror("Error al abrir el archivo salida.txt");
	// 	exit(1);
	// }

	// dup2(pipefd[0], STDIN_FILENO);
	// dup2(filefd, STDOUT_FILENO);
	// close(pipefd[0]);

	// executeCommand(argv_3, env, pipefd);

	// printf("Archivo creado correctamente.\n");

	return 0;
}

// du -h ~/Desktop/ | sort -rh | head -n 5 > salida.txt

// una pasada para contar los | o los > >>
// una pasada para contar env $

// malloc pidefd
// malloc de cada orde
