/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgoto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:21:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 21:23:40 by nmota-bu         ###   ########.fr       */
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

	// Obtener la secuencia de escape para mover el cursor a la posición (5, 10)
	char *cursor_pos = tgoto(tgetstr("cm", NULL), 5, 10);
	if (cursor_pos != NULL)
		printf("Secuencia de escape para mover el cursor a la posición (5, 10): %s\n", cursor_pos);
	else
		printf("No se pudo obtener la secuencia de escape para mover el cursor.\n");

	return 0;
}

//  gcc tgoto.c -lncurses
