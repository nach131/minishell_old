/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioctl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:41:22 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 10:48:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
	struct winsize ws;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
	{
		perror("Error al obtener el tamaño de la ventana de terminal");
		return 1;
	}

	printf("El tamaño actual de la ventana de terminal es %d columnas x %d filas\n", ws.ws_col, ws.ws_row);

	ws.ws_col = 80;
	ws.ws_row = 24;

	if (ioctl(STDOUT_FILENO, TIOCSWINSZ, &ws) == -1)
	{
		perror("Error al cambiar el tamaño de la ventana de terminal");
		return 1;
	}

	printf("El tamaño de la ventana de terminal ha sido cambiado a %d columnas x %d filas\n", ws.ws_col, ws.ws_row);

	return 0;
}
