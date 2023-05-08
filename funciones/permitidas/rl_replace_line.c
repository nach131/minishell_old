/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_replace_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:48:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/08 14:10:49 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*input;

	while ((input = readline("> ")) != NULL)
	{
		// Procesamos la entrada
		printf("Entrada recibida: %s\n", input);
		// Reemplazamos la línea actual de entrada con una nueva línea
		rl_replace_line("Nueva línea\n", 1);
		// Redibujamos la nueva línea
		rl_redisplay();
		// Liberamos la memoria utilizada por readline para la entrada
		free(input);
	}
	return (0);
}

// En este ejemplo,
// utilizamos un ciclo `while` para leer continuamente líneas de entrada
// utilizando la función `readline`. Después de procesar la entrada,
// llamamos a la función
// `rl_replace_line` para reemplazar la línea actual de entrada con una nueva línea que dice
// "Nueva línea".
// También especificamos que se deben borrar los datos de deshacer (undo) de la línea actual de
//  entrada utilizando `1` como segundo argumento.

// Luego llamamos a la función `rl_redisplay` para redibujar la nueva línea en la consola.
// Finalmente liberamos la memoria utilizada por `readline`
// para la entrada utilizando la función `free`.

// gcc rl_replace_line.c  -lreadline
