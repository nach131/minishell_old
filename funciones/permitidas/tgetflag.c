/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:50:16 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 11:59:19 by nmota-bu         ###   ########.fr       */
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

	// Verificar si el terminal admite el cursor parpadeante
	if (tgetflag("blink") != -1)
		printf("El terminal admite el cursor parpadeante.\n");
	else
		printf("El terminal no admite el cursor parpadeante.\n");
	if (tgetflag("rev") != -1)
		printf("El terminal admite el resaltado de texto.\n");
	else
		printf("El terminal no admite el resaltado de texto.\n");
	return 0;
}

// gcc tgetflag.c -lcurses
