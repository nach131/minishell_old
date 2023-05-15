/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:53:00 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 10:01:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	childPid;
	int		status;

	childPid = fork();
	if (childPid == 0)
	{
		// Código del proceso hijo
		printf("Proceso hijo ejecutándose\n");
		sleep(2);
		exit(0);
	}
	else if (childPid > 0)
	{
		// Código del proceso padre
		printf("Proceso padre esperando a que el hijo termine\n");
		waitpid(-1, &status, 0);
		printf("Proceso hijo terminado\n");
	}
	else
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}
	return (0);
}
