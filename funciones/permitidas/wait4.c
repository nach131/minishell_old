/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:22:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 10:31:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t			childPid;
	int				status;
	struct rusage	usage;

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
		wait4(-1, &status, 0, &usage);
		printf("Proceso hijo terminado\n");
		printf("Uso de recursos del hijo: Tiempo de CPU = %ld segundos,\
				Memoria = % ld KB\n ",
				usage.ru_utime.tv_sec,
				usage.ru_maxrss);
	}
	else
	{
		perror("Error al crear el proceso hijo");
		exit(1);
	}
	return (0);
}
