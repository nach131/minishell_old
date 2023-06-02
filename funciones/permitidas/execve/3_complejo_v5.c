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

void executeCommand(char *command, char **args, int input_fd, int output_fd)
{
	pid_t pid = fork();

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
		// Espera a que el proceso hijo termine
		wait(NULL);
	}
}

int main()
{
	int pipefd[2];
	int filefd;

	char *cmd_cat = "/bin/cat";
	char *args_cat[] = {"cat", "archivo.txt", NULL};

	char *cmd_grep = "/usr/bin/grep";
	char *args_grep[] = {"grep", "42", NULL};

	char *cmd_sed = "/usr/bin/sed";
	char *args_sed[] = {"sed", "s/42/131/g", NULL};

	char *args_sed2[] = {"sed", "s/Barcelona/New York/g", NULL};

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}
	int pipefd2[2];
	if (pipe(pipefd2) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}
	int pipefd3[2];
	if (pipe(pipefd3) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	filefd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo salida.txt");
		exit(1);
	}

	//=========================================================================

	executeCommand(cmd_cat, args_cat, STDIN_FILENO, pipefd[OUT]);
	close(pipefd[OUT]);

	executeCommand(cmd_grep, args_grep, pipefd[IN], pipefd2[OUT]);
	close(pipefd[IN]);
	close(pipefd2[OUT]);

	executeCommand(cmd_sed, args_sed, pipefd2[IN], pipefd3[OUT]);
	close(pipefd2[IN]);
	close(pipefd3[OUT]);

	executeCommand(cmd_sed, args_sed2, pipefd3[IN], filefd);
	close(pipefd3[IN]);
	close(filefd);

	return 0;
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt
