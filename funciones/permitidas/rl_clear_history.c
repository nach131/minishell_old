/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_clear_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:16:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/08 20:22:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

// copiar en el main del proyecto y hacer make

int	main(void)
{
	HIST_ENTRY	*entry;

	// Agregamos algunas entradas al historial
	add_history("comando1");
	add_history("comando2");
	add_history("comando3");
	// Imprimimos el historial actual
	printf(CYAN "Historial antes de borrar:\n");
	// Acceder al tercer comando del historial
	// entry = history_get(3);
	for (int i = history_length; i > 0; i--)
	{
		entry = history_get(i);
		if (entry)
		{
			printf("%s\n", entry->line);
		}
	}
	printf(MAGENTA "Numero en el history: %d\n", history_length);
	rl_clear_history();
	printf(RED "Despues de rl_clear_history: %d\n", history_length);
	return (0);
}

// gcc rl_clear_history.c -lreadline -lhistory
