/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:39:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/08 11:54:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*linea;

	linea = readline("Ingrese una línea de texto: ");
	printf("La línea ingresada es:\n%s\n", linea);
	free(linea);
	return (0);
}

// gcc readline.c -lreadline

// Ingrese una línea de texto: Esto es una nueva linea
// La línea ingresada es:
// Esto es una nueva linea
