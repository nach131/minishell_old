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
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}

		if (output_fd != STDOUT_FILENO)
		{
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}

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
	char *cmd_ls = "/bin/ls";
	char *args_ls[] = {"ls", "-la", NULL};

	char *cmd_grep = "/usr/bin/grep";
	char *args_grep[] = {"grep", "lib", NULL};

	int pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	executeCommand(cmd_ls, args_ls, STDIN_FILENO, pipefd[1]);
	close(pipefd[1]);

	executeCommand(cmd_grep, args_grep, pipefd[0], STDOUT_FILENO);
	close(pipefd[0]);

	return (0);
}
