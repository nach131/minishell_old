/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:31:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/27 13:39:20 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "working_tools.h"

int parser_tmp(void)
{
	// char str[] = "Hello,World,How,Are,You";
	// char str[] = "env | grep PATH";
	char str[] = "env VAR1=valor1 VAR2=valor2 comando";
	char *token;

	// Utilizar strtok para dividir la cadena en tokens utilizando la coma como delimitador
	token = ft_strtok(str, " ");

	while (token != NULL)
	{
		// Imprimir el token actual
		printf("%s\n", token);

		// Obtener el siguiente token
		token = ft_strtok(NULL, " ");
	}

	return (0);
}
