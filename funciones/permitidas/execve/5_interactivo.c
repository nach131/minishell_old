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

	char *cmd_1 = "/bin/cat";
	char *args_1[] = {"cat", NULL};
	char *envp_1[] = {NULL};
	char line[] = "FIN\n";

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	// Crea un nuevo proceso para ejecutar cat
	pid_t cat_pid = fork();

	if (cat_pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}

	if (cat_pid == 0)
	{
		// Redirige la salida hacia la tubería
		dup2(pipefd[1], STDOUT_FILENO);

		// Cierra los descriptores de archivo no necesarios
		close(pipefd[0]);
		close(pipefd[1]);

		// Ejecuta el comando cat
		execve(cmd_1, args_1, envp_1);
		perror("Error al ejecutar el comando cat");
		exit(1);
	}
	else
	{
		// Cierra el extremo de escritura de la tubería en el proceso padre
		close(pipefd[1]);

		// Abre el archivo para escribir
		filefd = open("config.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (filefd == -1)
		{
			perror("Error al abrir el archivo config.txt");
			exit(1);
		}

		// Lee de la tubería y escribe en el archivo
		char buffer[1024];
		ssize_t read_bytes;
		while ((read_bytes = read(pipefd[0], buffer, sizeof(buffer))) > 0)
		{
			write(filefd, buffer, read_bytes);
		}

		// Cierra los descriptores de archivo
		close(pipefd[0]);
		close(filefd);

		// Espera a que el proceso hijo termine
		wait(NULL);

		printf("Archivo creado correctamente.\n");
	}

	return 0;
}

NO ACABADO
