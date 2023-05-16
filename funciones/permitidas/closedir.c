/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closedir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:47:56 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 09:51:49 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>

// int main()
// {
// 	DIR *dir;
// 	struct dirent *entry;

// 	dir = opendir("directorio/"); // Reemplaza "directorio/" con la ruta de tu directorio

// 	if (dir == NULL)
// 	{
// 		perror("Error al abrir el directorio");
// 		return 1;
// 	}

// 	while ((entry = readdir(dir)) != NULL)
// 	{
// 		printf("%s\n", entry->d_name);
// 	}

// 	closedir(dir); // Cerrar el directorio

// 	return 0;
// }

bool directoryExists(const char *path)
{
	DIR *dir = opendir(path);

	if (dir)
	{
		closedir(dir); // Cerrar el directorio
		return true;
	}

	return false;
}

int main()
{
	const char *path = "directorio/"; // Reemplaza "directorio/" con la ruta de tu directorio

	if (directoryExists(path))
	{
		printf("El directorio existe.\n");
	}
	else
	{
		printf("El directorio no existe.\n");
	}

	return 0;
}
