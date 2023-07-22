/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:02:29 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/22 13:02:34 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *path = "/Library/Frameworks/Python.framework/Versions/3.10/bin:/Library/Frameworks/Python.framework/Versions/3.7/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public:/opt/X11/bin:/usr/local/mongodb/bin";
	char **paths = NULL;
	size_t num_paths = 0;

	printf("Original path: %s\n\n", path);

	// Crea una copia de la ruta original ya que strtok la modificará
	char *path_copy = strdup(path);

	// Variable temporal para contener cada token
	char *token = strtok(path_copy, ":");

	// Cuenta el número de tokens
	while (token != NULL) // Add opening curly brace here
	{
		num_paths++;
		token = strtok(NULL, ":");
	} // Add closing curly brace here

	// Asignar memoria para rutas
	paths = (char **)malloc(num_paths * sizeof(char *));

	// Reiniciar el proceso de tokenización
	free(path_copy);				// Liberar la memoria utilizada para path_copy
	path_copy = strdup(path);		// Crear una nueva copia de la ruta original
	token = strtok(path_copy, ":"); // Restablece el token al inicio de la nueva copia

	// Almacenar cada token en rutas
	for (size_t i = 0; i < num_paths; i++)
	{
		paths[i] = strdup(token);
		token = strtok(NULL, ":");
	}

	// Imprime cada valor en rutas
	for (size_t i = 0; i < num_paths; i++)
	{
		printf("Path %zu: %s\n", i + 1, paths[i]);
	}

	// Limpiar la memoria asignada
	for (size_t i = 0; i < num_paths; i++)
	{
		free(paths[i]);
	}
	free(paths);
	free(path_copy);

	return 0;
}

// Original path: /Library/Frameworks/Python.framework/Versions/3.10/bin:/Library/Frameworks/Python.framework/Versions/3.7/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public:/opt/X11/bin:/usr/local/mongodb/bin

// Path 1: /Library/Frameworks/Python.framework/Versions/3.10/bin
// Path 2: /Library/Frameworks/Python.framework/Versions/3.7/bin
// Path 3: /usr/local/bin
// Path 4: /usr/bin
// Path 5: /bin
// Path 6: /usr/sbin
// Path 7: /sbin
// Path 8: /Applications/VMware Fusion.app/Contents/Public
// Path 9: /opt/X11/bin
// Path 10: /usr/local/mongodb/bin
