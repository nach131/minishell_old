/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:07:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 17:11:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// int main()
// {
// 	int fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	if (fd == -1)
// 	{
// 		perror("Error al abrir el archivo");
// 		return 1;
// 	}

// 	if (dup2(fd, STDOUT_FILENO) == -1)
// 	{
// 		perror("Error al redirigir la salida estándar");
// 		return 1;
// 	}

// 	printf("Este texto se escribirá en el archivo salida.txt\n");

// 	close(fd);

// 	return 0;
// }

int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return 1;
	}

	int newfd = open("copia.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (newfd == -1)
	{
		perror("Error al abrir el archivo de destino");
		return 1;
	}

	if (dup2(fd, newfd) == -1)
	{
		perror("Error al duplicar el descriptor de archivo");
		return 1;
	}

	printf("Archivo duplicado exitosamente.\n");

	close(fd);
	close(newfd);

	return 0;
}
