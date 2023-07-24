#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <poll.h>
#include <signal.h>

enum
{
	IN,
	OUT,
};

void handler(int sig)
{
	printf("Se recibió la señal %d\n", sig);
}

void handler_ctrd(int sig)
{
	printf("Pulsado ctrl+d %d\n", sig);
}

void executeCommand(char *command, char **args, int input_fd, int output_fd)
{
	pid_t pid;
	char c;

	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		execve(command, args, NULL);
		perror("Error al ejecutar el comando");

		exit(1);
	}
	else if (pid > 0)
	{

		printf("-----------------------------\n");
		printf("Soy el proceso padre\n");
		while (read(STDIN_FILENO, &c, 1) == 1)
		{
			if (c == '\n')
			{
				printf("Has pulsado Enter\n");
				break;
			}
		}
		printf("-----------------------------\n");
		wait(NULL);
		printf("El proceso hijo ha finalizado\n");
	}
	else
	{
		// Error al crear el proceso hijo
		perror("fork");
		exit(1);
	}
}

int main(void)
{
	int pipefd[2];

	char *cmd_cat[2] = {"/bin/cat", NULL};
	char *cmd_ls[2] = {"/bin/ls", NULL};
	// char *args_cat[3] = {"cat", "mas_toma.txt", NULL};
	char *args_cat[2] = {"cat", NULL};
	char *args_ls[2] = {"ls", NULL};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(EXIT_FAILURE);
	}

	executeCommand(cmd_cat[0], args_cat, STDIN_FILENO, pipefd[OUT]);
	close(pipefd[OUT]);

	executeCommand(cmd_ls[0], args_ls, STDIN_FILENO, STDOUT_FILENO);
	close(pipefd[IN]);

	// Esperar a que el usuario presione Enter
	printf("Presiona Enter para terminar el proceso hijo...\n");
	getchar(); // Esperar a que el usuario presione Enter

	// Enviamos la señal SIGTERM al proceso hijo
	kill(-getpid(), SIGTERM);

	return 0;
}
