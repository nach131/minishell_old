/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:11:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 21:20:01 by nmota-bu         ###   ########.fr       */
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
#include <ncurses.h>

int main()
{
	char term_buffer[2048]; // Buffer para almacenar la entrada terminfo

	// Cargar la entrada terminfo para el terminal actual
	if (tgetent(term_buffer, getenv("TERM")) == -1)
	{
		perror("Error al cargar la entrada terminfo");
		return 1;
	}

	// Obtener la secuencia de escape para mover el cursor hacia arriba
	char *cursor_up_v = tgetstr("up", NULL);
	if (cursor_up_v != NULL)
	{
		printf("Secuencia de escape para mover el cursor hacia arriba: %s\n", cursor_up_v);
	}
	else
	{
		printf("No se pudo obtener la secuencia de escape para mover el cursor hacia arriba.\n");
	}

	return 0;
}
