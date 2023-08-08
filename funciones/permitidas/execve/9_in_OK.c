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

	char *cmd_1 = "/bin/cat";
	char *args_1[] = {"cat", NULL};

	//=========================================================================
	int pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	// Redirect input from the file "archivo.txt" to the "cat" command
	int filefd = open("archivo.txt", O_RDONLY);
	if (filefd == -1)
	{
		perror("Error al abrir el archivo archivo.txt");
		exit(1);
	}

	//=========================================================================
	executeCommand(cmd_1, args_1, filefd, pipefd[1]);
	close(filefd);
	close(pipefd[1]);

	executeCommand(cmd_1, args_1, pipefd[0], STDOUT_FILENO);
	close(pipefd[0]);

	return (0);
}

// //=========================================================================
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <sys/wait.h>
// #include <unistd.h>

// enum
// {
// 	IN,
// 	OUT,
// };

// void executeCommand(char *command, int input_fd, int output_fd)
// {
// 	pid_t pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("Error al crear el proceso hijo");
// 		exit(1);
// 	}
// 	if (pid == 0)
// 	{
// 		if (input_fd != STDIN_FILENO)
// 		{
// 			dup2(input_fd, STDIN_FILENO);
// 			close(input_fd);
// 		}

// 		if (output_fd != STDOUT_FILENO)
// 		{
// 			dup2(output_fd, STDOUT_FILENO);
// 			close(output_fd);
// 		}

// 		execlp(command, command, NULL);
// 		perror("Error al ejecutar el comando");
// 		exit(1);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 	}
// }

// int main(void)
// {

// 	//=========================================================================
// 	int pipefd[2];

// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("Error al crear la tubería");
// 		exit(1);
// 	}

// 	// Redirect input from the file "archivo.txt" to the "cat" command
// 	int filefd = open("archivo.txt", O_RDONLY);
// 	if (filefd == -1)
// 	{
// 		perror("Error al abrir el archivo archivo.txt");
// 		exit(1);
// 	}

// 	//=========================================================================
// 	executeCommand("cat", filefd, pipefd[1]);
// 	close(filefd);
// 	close(pipefd[1]);

// 	executeCommand("cat", pipefd[0], STDOUT_FILENO);
// 	close(pipefd[0]);

// 	return (0);
// }
