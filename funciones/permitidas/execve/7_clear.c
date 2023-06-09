
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *command = "/usr/bin/clear";
	char *args[] = {command, NULL};

	char *env[] = {
		"TERM=xterm-256color",
		NULL};

	execve(command, args, env);

	// Esta línea solo se ejecutará en caso de que execve falle
	perror("Error al ejecutar el comando");
	return 1;
}
