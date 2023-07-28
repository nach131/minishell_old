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
	int pipefd[2][2];
	int filefd;

	char *cmd[3] = {"/bin/ls", "/usr/bin/grep", "/usr/bin/sed"};
	char *args[3][3] = {
		{"ls", "-ls", NULL},
		{"grep", "toma", NULL},
		{"sed", "s/42/131/g", NULL}};

	for (int i = 0; i < 2; i++)
	{
		if (pipe(pipefd[i]) == -1)
		{
			perror("Error al crear la tubería");
			exit(1);
		}
	}

	filefd = open("toma.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo toma.txt");
		exit(1);
	}

	//=========================================================================
	executeCommand(cmd[0], args[0], STDIN_FILENO, pipefd[0][OUT]);
	close(pipefd[0][OUT]);

	int i = 0;

	while (i < 1)
	{
		executeCommand(cmd[i + 1], args[i + 1], pipefd[i][IN], pipefd[i + 1][OUT]);
		close(pipefd[i][IN]);
		close(pipefd[i + 1][OUT]);
		i++;
	}

	executeCommand(cmd[2], args[2], pipefd[1][IN], filefd);
	close(pipefd[1][IN]);
	close(filefd);
	return (0);
}
