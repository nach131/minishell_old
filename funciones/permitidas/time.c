/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:16:25 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 15:20:29 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int	main(void)
{
	const char	*path;
	struct stat	fileStat;
	time_t		ctime_valor;
	struct tm	*tm;
	char		datetime[20];

	path = "archivo.txt";
	if (stat(path, &fileStat) == 0)
	{
		printf("Información del archivo:\n");
		printf("Último cambio de estado: %s", ctime(&fileStat.st_ctime));
		// Formatear el valor de st_ctime como fecha y hora legible
		ctime_valor = fileStat.st_ctime;
		tm = localtime(&ctime_valor);
		strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", tm);
		printf("Último cambio de estado (formato personalizado): %s\n",
				datetime);
	}
	else
	{
		perror("Error al obtener información del archivo");
		return (1);
	}
	return (0);
}
