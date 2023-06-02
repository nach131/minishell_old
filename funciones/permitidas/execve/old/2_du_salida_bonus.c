#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int filefd;

	// Abrir el archivo "toma.txt" en modo de escritura
	filefd = open("toma.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo toma.txt");
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
		// Proceso hijo: redirige la salida estándar al archivo "toma.txt"
		dup2(filefd, STDOUT_FILENO);
		close(filefd);

		// Ejecuta el comando "ls"
		char *argv[] = {"ls", NULL};
		char *env[] = {NULL};
		if (execve("/bin/ls", argv, env) == -1)
		{
			perror("Error al ejecutar el comando ls");
			return 1;
		}
	}
	else
	{
		// Espera a que el proceso hijo termine
		wait(NULL);

		// Cierra el archivo
		close(filefd);

		// Ejecuta el comando "cat toma.txt"
		char *argv[] = {"cat", "toma.txt", NULL};
		char *env[] = {NULL};
		if (execve("/bin/cat", argv, env) == -1)
		{
			perror("Error al ejecutar el comando cat");
			return 1;
		}
	}

	return 0;
}

//  ls > toma.txt && cat toma.txt
