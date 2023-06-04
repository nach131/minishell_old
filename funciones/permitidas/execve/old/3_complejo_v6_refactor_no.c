#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

enum
{
	IN,
	OUT,
};

void executePipeline(char ***commands, int num_commands, int input_fd, int output_fd)
{
	int pipefd[2];
	int prev_pipefd[2] = {input_fd, output_fd};

	for (int i = 0; i < num_commands; i++)
	{
		if (i < num_commands - 1 && pipe(pipefd) == -1)
		{
			perror("Error al crear la tubería");
			exit(1);
		}

		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Error al crear el proceso hijo");
			exit(1);
		}

		if (pid == 0)
		{
			// Redirige la entrada y salida
			dup2(prev_pipefd[IN], STDIN_FILENO);
			if (i < num_commands - 1)
				dup2(pipefd[OUT], STDOUT_FILENO);
			else
				dup2(output_fd, STDOUT_FILENO);

			// Cierra los descriptores de archivo no necesarios
			if (i > 0)
			{
				close(prev_pipefd[IN]);
				close(prev_pipefd[OUT]);
			}
			if (i < num_commands - 1)
			{
				close(pipefd[IN]);
				close(pipefd[OUT]);
			}

			// Ejecuta el comando
			execvp(commands[i][0], commands[i]);
			perror("Error al ejecutar el comando");
			exit(1);
		}
		else
		{
			// Cierra los descriptores de archivo no necesarios en el padre
			if (i > 0)
			{
				close(prev_pipefd[IN]);
				close(prev_pipefd[OUT]);
			}

			// Almacena el descriptor de archivo de la tubería actual para usarlo en la siguiente iteración
			if (i < num_commands - 1)
			{
				prev_pipefd[IN] = pipefd[IN];
				prev_pipefd[OUT] = pipefd[OUT];
			}

			// Espera a que el proceso hijo termine
			wait(NULL);
		}
	}
}

int main()
{
	int filefd;

	char *cmd_cat[] = {"cat", "archivo.txt", NULL};
	char *cmd_grep[] = {"grep", "42", NULL};
	char *cmd_sed1[] = {"sed", "s/42/131/g", NULL};
	char *cmd_sed2[] = {"sed", "s/Barcelona/New York/g", NULL};

	char **commands[] = {cmd_cat, cmd_grep, cmd_sed1, cmd_sed2};
	int num_commands = sizeof(commands) / sizeof(commands[0]);

	filefd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo salida.txt");
		exit(1);
	}

	executePipeline(commands, num_commands, STDIN_FILENO, filefd);

	close(filefd);

	return 0;
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt
