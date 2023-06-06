/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:38:34 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/05 10:08:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

// int	main(void)
// {
// 	// Verifica si el archivo existe
// 	if (access("archivo.txt", F_OK) != -1)
// 		printf("El archivo existe.\n");
// 	else
// 		printf("El archivo no existe.\n");
// 	return (0);
// }

// int	main(void)
// {
// 	// Verifica si el archivo es escribible y ejecutable
// 	if (access("archivo.txt", W_OK | X_OK) == 0)
// 		printf("El archivo es escribible y ejecutable.\n");
// 	else
// 		printf("El archivo no es escribible y ejecutable.\n");
// 	return (0);
// }

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	const char	*executable;
		char path[256];
		char path[256];

	executable = "nombre_del_ejecutable";
	// Verificar la existencia del ejecutable en /bin
	if (access("/bin", X_OK) == 0)
	{
		snprintf(path, sizeof(path), "/bin/%s", executable);
		if (access(path, X_OK) == 0)
		{
			printf("El ejecutable se encuentra en /bin\n");
		}
	}
	// Verificar la existencia del ejecutable en /usr/bin
	if (access("/usr/bin", X_OK) == 0)
	{
		snprintf(path, sizeof(path), "/usr/bin/%s", executable);
		if (access(path, X_OK) == 0)
		{
			printf("El ejecutable se encuentra en /usr/bin\n");
		}
	}
	return (0);
}
