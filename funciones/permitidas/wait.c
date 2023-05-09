/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:06:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/09 20:18:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	handler(int sig)
{
	printf("Se recibió la señal %d\n", sig);
}

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		// Este es el proceso hijo
		printf("Soy el proceso hijo\n");
		sleep(2);
		printf("Proceso hijo terminando de manera anormal\n");
		raise(SIGTERM);
	}
	else if (pid > 0)
	{
		// Este es el proceso padre
		printf("Soy el proceso padre\n");
		signal(SIGTERM, handler);
		wait(NULL);
		printf("El proceso hijo ha finalizado\n");
	}
	else
	{
		// Error al crear el proceso hijo
		perror("fork");
		exit(1);
	}
	return (0);
}

// En este ejemplo, se crea un proceso hijo utilizando la función `fork`.
// El proceso hijo imprime un mensaje y sale de la ejecución utilizando
// la función `exit`. El proceso padre espera a que el proceso hijo finalice
// su ejecución utilizando la función `wait`. Una vez que el proceso hijo ha
// finalizado, el proceso padre imprime un mensaje indicando que el proceso
// hijo ha finalizado.
