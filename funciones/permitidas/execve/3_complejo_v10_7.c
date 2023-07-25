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

	char *cmd[3] = {"/bin/ls", "/usr/bin/grep", "/usr/bin/grep"};
	char *args[3][5] = {
		{"ls", "-la", NULL},
		{"grep", "3_", NULL},
		{"grep", "3_", NULL}};

	// Create the two output files
	int file1_fd = open("uno.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file1_fd == -1)
	{
		perror("Error al abrir/crear uno.txt");
		exit(1);
	}

	int file2_fd = open("dos.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file2_fd == -1)
	{
		perror("Error al abrir/crear dos.txt");
		exit(1);
	}

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}

	executeCommand(cmd[0], args[0], STDIN_FILENO, pipefd[1]);
	// close(pipefd[1]);

	// Redirect output to uno.txt
	executeCommand(cmd[1], args[1], pipefd[0], file1_fd);
	// close(pipefd[0]);

	// Redirect output to dos.txt
	executeCommand(cmd[2], args[2], STDIN_FILENO, file2_fd);

	// Close the file descriptors
	// close(file1_fd);
	// close(file2_fd);

	return 0;
}

// ls > uno.txt > dos.txt
