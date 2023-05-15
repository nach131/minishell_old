/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:57:47 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 16:00:46 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	int			fd;
	struct stat	fileStat;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	if (fstat(fd, &fileStat) == 0)
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
	close(fd);
	return (0);
}

// int	main(void)
// {
// 	struct stat	fileStat;

// 	if (fstat(STDIN_FILENO, &fileStat) == 0)
// 	{
// 		if (S_ISCHR(fileStat.st_mode))
// 		{
// 			printf("El descriptor de archivo se refiere a una terminal\n");
// 		}
// 		else
// 		{
// 			printf("El descriptor de archivo no se refiere a una terminal\n");
// 		}
// 	}
// 	else
// 	{
// 		perror("Error al obtener información del descriptor de archivo");
// 		return (1);
// 	}
// 	return (0);
// }
