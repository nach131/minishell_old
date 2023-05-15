/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:48:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 15:22:23 by nmota-bu         ###   ########.fr       */
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

	path = "archivo.txt";
	if (stat(path, &fileStat) == 0)
	{
		printf("Información del archivo:\n");
		printf("Tamaño: %lld bytes\n", fileStat.st_size);
		printf("Permisos: %o\n", fileStat.st_mode & 0777);
		printf("Último acceso: %s", ctime(&fileStat.st_atime));
		printf("Última modificación: %s", ctime(&fileStat.st_mtime));
		printf("Último cambio de estado: %s", ctime(&fileStat.st_ctime));
	}
	else
	{
		perror("Error al obtener información del archivo");
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	const char	*path;
// 	struct stat	dirStat;

// 	path = "directorio";
// 	if (stat(path, &dirStat) == 0)
// 	{
// 		if (S_ISDIR(dirStat.st_mode))
// 		{
// 			printf("El directorio existe\n");
// 		}
// 		else
// 		{
// 			printf("El directorio no existe\n");
// 		}
// 	}
// 	else
// 	{
// 		perror("Error al obtener información del directorio\n");
// 		return (1);
// 	}
// 	return (0);
// }
