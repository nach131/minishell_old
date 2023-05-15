/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:49:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 15:53:14 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int	main(void)
{
	const char	*path;
	struct stat	fileStat;

	path = "archivo.txt";
	if (lstat(path, &fileStat) == 0)
	{
		if (S_ISREG(fileStat.st_mode))
		{
			printf("El archivo es un archivo regular\n");
			printf("Tamaño: %lld bytes\n", fileStat.st_size);
			printf("Permisos: %o\n", fileStat.st_mode & 0777);
		}
		else
		{
			printf("El archivo no es un archivo regular\n");
		}
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
// 	struct stat	fileStat;

// 	path = "enlace_simbolico";
// 	if (lstat(path, &fileStat) == 0)
// 	{
// 		if (S_ISLNK(fileStat.st_mode))
// 		{
// 			printf("El archivo es un enlace simbólico\n");
// 			printf("Tamaño: %lld bytes\n", fileStat.st_size);
// 		}
// 		else
// 		{
// 			printf("El archivo no es un enlace simbólico\n");
// 		}
// 	}
// 	else
// 	{
// 		perror("Error al obtener información del enlace simbólico");
// 		return (1);
// 	}
// 	return (0);
// }
