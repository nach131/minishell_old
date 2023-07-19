#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

enum
{
	IN,
	OUT,
};

void executeCommand(char *command, char **args, int input_fd, int output_fd)
{
	pid_t pid;

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
	else
	{
		wait(NULL);
	}
}
int main(void)
{
	int pipefd[3][2];
	int filefd;

	char *cmd[4] = {"/bin/cat", "/usr/bin/grep", "/usr/bin/grep", "/usr/bin/sed"};
	char *args[4][3] = {
		{"cat", "Makefile", NULL},
		{"grep", "echo", NULL},
		{"grep", "todo", NULL},
		{"sed", "s/Barcelona/New York/g", NULL}};

	// Crear las tuberías
	for (int i = 0; i < 3; i++)
	{
		if (pipe(pipefd[i]) == -1)
		{
			perror("Error al crear la tubería");
			exit(EXIT_FAILURE);
		}
	}

	filefd = open("toma.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo toma.txt");
		exit(EXIT_FAILURE);
	}

	//=========================================================================
	executeCommand(cmd[0], args[0], STDIN_FILENO, pipefd[0][OUT]);
	close(pipefd[0][OUT]);

	executeCommand(cmd[1], args[1], pipefd[0][IN], pipefd[1][OUT]);
	close(pipefd[0][IN]);
	close(pipefd[1][OUT]);

	executeCommand(cmd[2], args[2], pipefd[1][IN], filefd);
	close(pipefd[1][IN]);
	close(filefd);

	return 0;
}

// cat Makefile | grep echo | grep todo > toma.txt
