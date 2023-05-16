/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:24:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 21:32:19 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>

int main()
{
	char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

	// Cargar la entrada terminfo para el terminal actual
	if (tgetent(term_buffer, getenv("TERM")) == -1)
	{
		perror("Error al cargar la entrada terminfo");
		return 1;
	}

	// Obtener la secuencia de escape para imprimir en negrita
	char *bold_seq = tgetstr("bold", NULL);
	if (bold_seq != NULL)
	{
		// Enviar la secuencia de escape al terminal utilizando tputs
		if (tputs(bold_seq, 1, putchar) == ERR)
		{
			perror("Error al enviar la secuencia de escape");
			return 1;
		}

		// Imprimir texto en negrita
		printf("Texto en negrita\n");

		// Restaurar el formato normal
		char *reset_seq = tgetstr("sgr0", NULL);
		if (reset_seq != NULL)
		{
			tputs(reset_seq, 1, putchar);
		}
	}
	else
		printf("No se pudo obtener la secuencia de escape para imprimir en negrita.\n");

	return 0;
}

// gcc tputs.c -lncurses
