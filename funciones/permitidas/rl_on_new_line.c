/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_on_new_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:42:35 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/08 12:51:48 by nmota-bu         ###   ########.fr       */
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

	while ((input = readline("Minishel> ")) != NULL)
	{
		// Procesamos la entrada
		printf("Entrada recibida: %s\n", input);
		// Notificamos a readline que se ha completado la entrada
		rl_on_new_line();
		// Liberamos la memoria utilizada por readline para la entrada
		free(input);
	}
	return (0);
}

// int	main(void)
// {
// 	char *input;

// 	// Configuramos un prefijo personalizado para el prompt
// 	rl_set_prompt("Mi Prompt> ");

// 	while ((input = readline(NULL)) != NULL)
// 	{
// 		// Procesamos la entrada
// 		printf("Entrada recibida: %s\n", input);

// 		// Notificamos a readline que se ha completado la entrada
// 		rl_on_new_line();

// 		// Liberamos la memoria utilizada por readline para la entrada
// 		free(input);
// 	}

// 	return (0);
// }

// gcc rl_on_new_line.c -lreadline
