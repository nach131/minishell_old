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
		execvp(command, args);
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

	char *cmd_cat = "/bin/cat";
	char *args_cat[] = {"cat", "archivo.txt", NULL};

	char *cmd_grep = "/usr/bin/grep";
	char *args_grep[] = {"grep", "42", NULL};

	char *cmd_sed = "/usr/bin/sed";
	char *args_sed[] = {"sed", "s/42/131/g", NULL};

	char *cmd_sort = "/usr/bin/sort";
	char *args_sort[] = {"sort", NULL};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	executeCommand(cmd_cat, args_cat, STDIN_FILENO, pipefd[1]);
	close(pipefd[1]);

	executeCommand(cmd_grep, args_grep, pipefd[0], pipefd[1]);
	close(pipefd[1]);

	executeCommand(cmd_sed, args_sed, pipefd[0], pipefd[1]);
	close(pipefd[1]);

	executeCommand(cmd_sort, args_sort, pipefd[0], filefd);
	filefd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo salida.txt");
		exit(1);
	}
	close(pipefd[1]);
	close(filefd);

	printf("Archivo creado correctamente.\n");

	return 0;
}
