/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:48:18 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 12:51:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char path[256];

	printf("Ingrese el directorio al que desea cambiar: ");
	scanf("%s", path);

	if (chdir(path) == 0)
	{
		printf("Directorio cambiado correctamente\n");
	}
	else
	{
		perror("Error al cambiar el directorio");
		return (1);
	}

	return (0);
}
