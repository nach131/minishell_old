#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
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
	char *cmd[1] = {
		"/usr/bin/grep",
	};
	char *args[1][2] = {
		{"grep", NULL}};

	int pipefd[3][2];

	executeCommand(cmd[0], args, STDIN_FILENO, pipefd[0][OUT]);
	close(pipefd[0][OUT]);
	return (0);
}

// usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]
// 	[-e pattern] [-f file] [--binary-files=value] [--color=when]
// 	[--context[=num]] [--directories=action] [--label] [--line-buffered]
// 	[--null] [pattern] [file ...]
