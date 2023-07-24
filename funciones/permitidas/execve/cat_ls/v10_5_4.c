#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h> // Add this include for errno

enum
{
	IN,
	OUT,
};

void executeCommand(char *command, char **args, int input_fd, int output_fd,
					char **env)
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
		// Handling input_fd
		if (input_fd != STDIN_FILENO)
		{
			if (dup2(input_fd, STDIN_FILENO) == -1)
			{
				perror("Error en dup2 para STDIN_FILENO");
				exit(1);
			}
			close(input_fd);
		}

		// Handling output_fd
		if (output_fd != STDOUT_FILENO)
		{
			if (dup2(output_fd, STDOUT_FILENO) == -1)
			{
				perror("Error en dup2 para STDOUT_FILENO");
				exit(1);
			}
			close(output_fd);
		}

		execve(command, args, env);
		perror("Error al ejecutar el comando");
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "El proceso hijo terminó con un código de salida no exitoso: %d\n", WEXITSTATUS(status));
		}
		// Don't wait for child process here.
	}
}

int main(void)
{
	int pipefd[2];

	char *cmd[2] = {"/bin/cat", "/bin/ls"};
	char *args[2][2] = {
		{"cat", NULL},
		{"ls", NULL},
	};

	char *env[1] = {NULL};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(EXIT_FAILURE);
	}

	executeCommand(cmd[0], args[0], STDIN_FILENO, pipefd[OUT], env);
	close(pipefd[OUT]);

	executeCommand(cmd[1], args[1], pipefd[IN], STDOUT_FILENO, env);
	close(pipefd[IN]);

	// Wait for both child processes to finish
	// wait(NULL);
	// wait(NULL);

	return 0;
}
