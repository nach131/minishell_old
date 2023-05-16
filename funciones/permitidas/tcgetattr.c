/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcgetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:10:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 11:26:18 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// int main()
// {
// 	struct termios attr;
// 	if (tcgetattr(STDIN_FILENO, &attr) == -1)
// 	{
// 		perror("Error al obtener la configuración del terminal");
// 		return 1;
// 	}

// 	printf("Configuración del terminal:\n");
// 	printf("Velocidad de transmisión: %lu\n", cfgetospeed(&attr));
// 	printf("Modos de línea: %lu\n", attr.c_lflag);
// 	// Otros parámetros de configuración...

// 	return 0;
// }

int main()
{
	struct termios attr;
	if (tcgetattr(STDIN_FILENO, &attr) == -1)
	{
		perror("Error al obtener la configuración del terminal");
		return 1;
	}

	if (attr.c_lflag & ECHO)
	{
		printf("El eco de caracteres está habilitado.\n");
	}
	else
	{
		printf("El eco de caracteres está deshabilitado.\n");
	}

	if (attr.c_iflag & IXON)
	{
		printf("El control de flujo de entrada XON/XOFF está habilitado.\n");
	}
	else
	{
		printf("El control de flujo de entrada XON/XOFF está deshabilitado.\n");
	}

	// Otros parámetros de configuración...

	return 0;
}
