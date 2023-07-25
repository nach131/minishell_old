#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

int exec_ls(char *cmd, char **av, char **envp)
{
	return execve(cmd, av, envp);
}

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	int i = 0;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], fd);
}

int main(int ac, char **av, char **envp)
{
	int fd;
	int fds[2];
	int pid;
	int rc;
	int waitstat;
	char buff[1024];

	if (ac != 1)
	{
		printf("Cantidad incorrecta de argumentos, no se necesita ninguno\n");
		return 1;
	}

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666); // Cambiar 777 a 0666 para los permisos adecuados

	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return 1;
	}

	pipe(fds);
	printf("Cambiando la salida estándar a fds\n");
	dup2(fds[1], STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		perror("Error en el fork: ");
	if (pid == 0)
	{
		close(fds[0]);
		if (exec_ls("/bin/ls", av, envp) == -1)
			printf("Error, no se pudo ejecutar ls!\n");
	}
	else
	{
		close(fds[1]);
		wait(&waitstat);
		rc = read(fds[0], buff, sizeof(buff) - 1);
		buff[rc] = '\0';
		close(fds[0]);
		if (rc == -1)
		{
			printf("Error al leer la salida\n");
			return 1;
		}
		ft_putstr_fd(buff, fd);
		close(fd);
	}

	printf("Finalizó la ejecución\n"); // Mensaje después de completar la ejecución
	return 0;
}
