#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

int exec_ls(char **av, char **envp)
{
	return (execve("/usr/bin/ls", av, envp));
}

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
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

	if (ac != 2)
	{
		printf("Wrong number of arguments, should be one\n");
		return (0);
	}
	pipe(fds);
	printf("Changing standar output to fds\n");
	dup2(fds[1], STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		perror("Fork Error!: ");
	if (pid == 0)
	{
		close(fds[0]);
		if (exec_ls(av, envp) == -1)
			printf("Error, didn't execute!\n");
	}
	else
	{
		close(fds[1]);
		waitstat = WIFEXITED(pid);
		dup2(fds[0], 1);
		wait(&waitstat);
		rc = read(fds[0], buff, 1024);
		buff[rc] = 0;
		close(fds[0]);
		if (rc == -1)
		{
			printf("Error while reading\n");
			return (0);
		}
		fd = open("test.txt", O_RDONLY | O_CREAT | 777);
		ft_putstr_fd(buff, fd);
		close(fd);
	}
	printf("Finished Executing%s\n", buff); // This is not working I need to recover the STDOUT
	return (0);
}
