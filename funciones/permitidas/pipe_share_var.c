#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	int		pipefd[2];
	int		shared_variable;
	pid_t	pid;
		int value_received;

	if (pipe(pipefd) == -1)
	{
		perror("Error al crear el pipe");
		exit(1);
	}
	shared_variable = 42;
	pid = fork();
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}
	if (pid == 0)
	{
		// Proceso hijo
		// Cerramos el extremo de escritura del pipe ya que el hijo solo leerá
		close(pipefd[1]);
		read(pipefd[0], &value_received, sizeof(value_received));
		printf("Proceso hijo - Valor recibido: %d\n", value_received);
		close(pipefd[0]);
	}
	else
	{
		// Proceso padre
		// Cerramos el extremo de lectura del pipe ya que el padre solo escribirá
		close(pipefd[0]);
		printf("Proceso padre - Valor a enviar: %d\n", shared_variable);
		write(pipefd[1], &shared_variable, sizeof(shared_variable));
		// Esperar a que el proceso hijo termine
		wait(NULL);
		close(pipefd[1]);
	}
	return (0);
}
