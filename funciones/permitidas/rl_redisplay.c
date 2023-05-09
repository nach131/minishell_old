/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_redisplay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:13:13 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/09 16:08:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

int	main(void)
{
	char	*line;

	rl_bind_key('\t', rl_abort);
	while ((line = readline("Minishell> ")) != NULL)
	{
		printf("Comando ingresado: %s\n", line);
		// Simular un error
		if (ft_strcmp(line, "error") == 0)
		{
			rl_replace_line("Error: comando no válido", 0);
			rl_redisplay();
		}
		else
			add_history(line);
		free(line);
	}
	return (0);
}

// En este ejemplo, si el usuario ingresa el comando "error",
// llamamos a rl_replace_line() para reemplazar la línea de entrada
// con el mensaje de error "Error: comando no válido". A continuación,
// llamamos a rl_redisplay() para mostrar el mensaje de error en la consola.
// Si el usuario ingresa cualquier otro comando, simplemente agregamos el
//  comando al historial como de costumbre.
