/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:55:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 23:09:58 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <dirent.h>

int main()
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir("directorio/"); // Reemplaza "directorio/" con la ruta de tu directorio

	if (dir == NULL)
	{
		perror("Error al abrir el directorio");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL)
		printf("%s\n", entry->d_name);

	closedir(dir);

	return 0;
}
