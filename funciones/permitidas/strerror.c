/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:52:56 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 09:58:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	FILE *file = fopen("archivo_no_existente.txt", "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error al abrir el archivo: %s\n", strerror(errno));
		return 1;
	}

	// Resto del código para trabajar con el archivo

	fclose(file);

	return 0;
}

// int main()
// {
// 	int *ptr = malloc(1000000000000000); // Intenta asignar una cantidad excesiva de memoria

// 	if (ptr == NULL)
// 	{
// 		fprintf(stderr, "Error al asignar memoria: %s\n", strerror(errno));
// 		return 1;
// 	}

// 	// Resto del código para trabajar con el puntero asignado

// 	free(ptr);

// 	return 0;
// }
