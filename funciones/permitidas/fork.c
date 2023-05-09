/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:55:22 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/09 20:01:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		printf("Error al crear proceso hijo\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("Proceso hijo creado\n");
		printf("ID del proceso hijo: %d\n", getpid());
		execl("/bin/ls", "ls", "-l", NULL);
		printf("Error al ejecutar el comando\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Proceso padre\n");
		printf("ID del proceso padre: %d\n", getpid());
	}
	return (0);
}
//=========================================================================
// int	main(void)
// {
// 	pid_t pid;
// 	int x = 10;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		printf("Error al crear proceso hijo\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid == 0)
// 	{
// 		printf("Proceso hijo creado\n");
// 		printf("Valor de x en el proceso hijo: %d\n", x);
// 		x += 5;
// 		printf("Nuevo valor de x en el proceso hijo: %d\n", x);
// 	}
// 	else
// 	{
// 		printf("Proceso padre\n");
// 		printf("Valor de x en el proceso padre: %d\n", x);
// 		x += 10;
// 		printf("Nuevo valor de x en el proceso padre: %d\n", x);
// 	}

// 	return (0);
// }
