/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_clear_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:16:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/08 12:26:54 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

// EN PROCESO......

int	main(void)
{
	// Agregamos algunas entradas al historial
	add_history("comando1");
	add_history("comando2");
	add_history("comando3");
	// Imprimimos el historial actual
	printf("Historial antes de borrar:\n");
	for (int i = 0; i < history_length; i++)
	{
		printf("%s\n", history_get(i)->line);
	}
	// Borramos todo el historial
	rl_clear_history();
	// Imprimimos el historial actualizado
	printf("Historial después de borrar:\n");
	for (int i = 0; i < history_length; i++)
	{
		printf("%s\n", history_get(i)->line);
	}
	return (0);
}

// gcc rl_clear_history.c -lreadline
