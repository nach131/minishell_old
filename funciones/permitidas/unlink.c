/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:09:06 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 16:23:29 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	const char *filename;

	filename = "archivo.txt";
	if (unlink(filename) == 0)
	{
		printf("Archivo eliminado exitosamente.\n");
	}
	else
	{
		perror("Error al eliminar el archivo");
		return (1);
	}
	return (0);
}

// int main(void)
// {
// 	const char *filenames[] = {"archivo1.txt", "archivo2.txt", "archivo3.txt"};
// 	int numFiles = sizeof(filenames) / sizeof(filenames[0]);

// 	for (int i = 0; i < numFiles; i++)
// 	{
// 		if (unlink(filenames[i]) == 0)
// 		{
// 			printf("Archivo %s eliminado exitosamente.\n", filenames[i]);
// 		}
// 		else
// 		{
// 			perror("Error al eliminar el archivo");
// 			return (1);
// 		}
// 	}

// 	return (0);
// }
