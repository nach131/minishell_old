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
		// close(input_fd); // no son necesarias aqui
		// close(output_fd);

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

	char *cmd_1 = "/usr/bin/find";
	char *args_1[] = {"find", "../../", "-type", "f", "-mtime", "0", NULL};
	char *cmd_2 = "/usr/bin/sort";
	char *args_2[] = {"sort", NULL};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	executeCommand(cmd_1, args_1, STDIN_FILENO, pipefd[1]);
	close(pipefd[1]);

	filefd = open("toma.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo archivos_modificados.txt");
		exit(1);
	}

	executeCommand(cmd_2, args_2, pipefd[0], filefd);
	close(pipefd[0]);
	close(filefd);

	printf("Archivo actualizado correctamente.\n");

	return 0;
}

// USADO O_APPEND
// En esta versión, se utiliza la bandera O_APPEND al abrir el archivo "archivos_modificados.txt"
// para asegurar que la salida se agregue al final del archivo existente.

// find ../../ -type f -mtime 0 | sort >> archivos_modificados.txt
