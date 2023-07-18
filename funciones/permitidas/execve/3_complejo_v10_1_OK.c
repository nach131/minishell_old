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
	int pipefd[2];
	int filefd;

	char *cmd[2] = {"/bin/ls", "/usr/bin/grep"};
	char *args[2][4] = {
		{"ls", "-la", NULL},
		{"grep", "3_", NULL}};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	filefd = open("toma.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo toma.txt");
		exit(1);
	}

	executeCommand(cmd[0], args[0], STDIN_FILENO, pipefd[1]);
	close(pipefd[1]);

	executeCommand(cmd[1], args[1], pipefd[0], filefd);
	close(pipefd[0]);
	close(filefd);

	return 0;
}

// ls -la | grep 3 > toma.txt
