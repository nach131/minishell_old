/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:11:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 23:45:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main()
{
	DIR *dir;
	struct dirent *entry;
	const char *extension = ".txt"; // Extensión a filtrar

	dir = opendir("directorio/"); // Reemplaza "directorio/" con la ruta de tu directorio

	if (dir == NULL)
	{
		perror("Error al abrir el directorio");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG && strstr(entry->d_name, extension) != NULL)
		{
			printf("%s\n", entry->d_name);
		}
	}

	closedir(dir);

	return 0;
}
