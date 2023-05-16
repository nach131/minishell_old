/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:03:36 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 10:05:02 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <errno.h>

int main()
{
	FILE *file = fopen("archivo_no_existente.txt", "r");

	if (file == NULL)
	{
		perror("Error al abrir el archivo");
		return 1;
	}

	// Resto del código para trabajar con el archivo

	fclose(file);

	return 0;
}
