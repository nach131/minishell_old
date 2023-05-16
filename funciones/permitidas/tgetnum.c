/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:00:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 12:09:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main()
{
	char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

	// Cargar la entrada terminfo para el terminal actual
	if (tgetent(term_buffer, getenv("TERM")) == -1)
	{
		perror("Error al cargar la entrada terminfo");
		return 1;
	}

	// Obtener el ancho de la ventana del terminal
	int width = tgetnum("cols");
	if (width != -1)
		printf("Ancho de la ventana del terminal: %d\n", width);
	else
		printf("No se pudo obtener el ancho de la ventana del terminal.\n");
	return 0;
}

// gcc tgetnum.c -lcurses
