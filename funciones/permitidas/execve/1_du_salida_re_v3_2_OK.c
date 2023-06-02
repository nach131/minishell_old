#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

// Función para ejecutar un comando y redirigir la entrada y salida según los descriptores de archivo dados
void executeCommand(char *command, char **args, int input_fd, int output_fd)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}

	if (pid == 0)
	{
		// Redirige la entrada y salida según los descriptores de archivo dados
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);

		// Cierra los descriptores de archivo no necesarios
		close(input_fd);
		close(output_fd);

		// Ejecuta el comando
		execve(command, args, NULL);
		perror("Error al ejecutar el comando");
		exit(1);
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

	char *cmd_1 = "/usr/bin/du";
	char *args_1[] = {"du", "-h", "../../", NULL};
	char *cmd_2 = "/usr/bin/sort";
	char *args_2[] = {"sort", "-rh", NULL};
	char *cmd_3 = "/usr/bin/head";
	char *args_3[] = {"head", "-n", "5", NULL};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	executeCommand(cmd_1, args_1, STDIN_FILENO, pipefd[1]);
	close(pipefd[1]);

	int pipefd2[2];
	if (pipe(pipefd2) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	executeCommand(cmd_2, args_2, pipefd[0], pipefd2[1]);
	close(pipefd[0]);
	close(pipefd2[1]);

	filefd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo salida.txt");
		exit(1);
	}

	executeCommand(cmd_3, args_3, pipefd2[0], filefd);
	close(pipefd2[0]);
	close(filefd);

	printf("Archivo creado correctamente.\n");

	return 0;
}
