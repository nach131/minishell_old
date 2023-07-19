
#include <stdio.h>

int main(void)
{
	int i = 0;

	((i = 1) && printf("i: %d\n", i) && (i = 10));
	printf("i: %d\n", i);
	return (0);
}

// ls - ls > lista.txt

// 		  int
// 		  main(void)
// {
// 	int filefd;

// 	char *cmd[2] = {"/bin/ls", NULL};
// 	char *args[2][3] = {
// 		{"ls", "-la", NULL},
// 	};

// 	filefd = open("list.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
// 	if (filefd == -1)
// 	{
// 		perror("Error al abrir el archivo list.txt");
// 		exit(EXIT_FAILURE);
// 	}

// 	//=========================================================================
// 	executeCommand(cmd[0], args[0], STDIN_FILENO, filefd);
// 	close(filefd);

// 	return 0;
// }

// pipie |

// 	ls - la | grep lib

// 				  // Ejecutar el comando ls -la
// 				  executeCommand(cmd_ls[0], args_ls[0], STDIN_FILENO, pipefd[OUT]);
// close(pipefd[OUT]);

// // Ejecutar el comando grep lib y redirigir su salida al archivo lib_files.txt
// executeCommand(cmd_grep[0], cmd_grep, pipefd[IN], filefd);
// close(pipefd[IN]);
// close(filefd);
