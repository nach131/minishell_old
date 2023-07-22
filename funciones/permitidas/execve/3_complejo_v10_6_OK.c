#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

// Función para ejecutar un comando y redirigir la entrada y salida según los descriptores de archivo dados
void executeCommand(char *command, char **args, char **envp, int input_fd, int output_fd)
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

		// Cierra el descriptor de archivo de entrada, si es diferente del descriptor estándar
		if (input_fd != STDIN_FILENO)
			close(input_fd);

		// Cierra el descriptor de archivo de salida, si es diferente del descriptor estándar
		if (output_fd != STDOUT_FILENO)
			close(output_fd);

		// Ejecuta el comando
		execve(command, args, envp);
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

	char *cmd_cat = "./toma.sh";
	char *args_cat[] = {NULL};

	char *envp[] = {NULL};

	// No se cierran los descriptores de archivo antes de ejecutar el script
	executeCommand(cmd_cat, args_cat, envp, STDIN_FILENO, STDOUT_FILENO);

	return 0;
}

// ejecuta el archivo
// ./toma.sh
