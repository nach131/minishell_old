// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main()
// {
// 	char *command = "/bin/sh";
// 	char *args[] = {"/bin/sh", "-c", "echo 'Hola, mundo'", NULL};
// 	char *env[] = {NULL};

// 	execve(command, args, env);

// 	// Esta línea solo se ejecutará en caso de que execve falle
// 	perror("Error al ejecutar el comando");
// 	return 1;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *command = "/usr/bin/env";
	char *args[] = {"/usr/bin/env", NULL};

	char *env[] = {
		"MY_VARIABLE=Hola",
		"ANOTHER_VARIABLE=Mundo",
		NULL};

	execve(command, args, env);

	// Esta línea solo se ejecutará en caso de que execve falle
	perror("Error al ejecutar el comando");
	return 1;
}

// MY_VARIABLE=Hola
// ANOTHER_VARIABLE=Mundo
