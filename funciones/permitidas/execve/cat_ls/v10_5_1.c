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
		// quitando esto hacemos que no se espere a la ejecucion de cat
		// wait(NULL);
	}
}

int main(void)
{
	int pipefd[2];

	char *cmd_cat[2] = {"/bin/cat", NULL};
	char *args_cat[2] = {"cat", NULL};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(EXIT_FAILURE);
	}

	executeCommand(cmd_cat[0], args_cat, STDIN_FILENO, pipefd[OUT]);
	return 0;
}
