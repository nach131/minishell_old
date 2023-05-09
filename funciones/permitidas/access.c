/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:38:34 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/09 16:42:18 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// Verifica si el archivo existe
	if (access("archivo.txt", F_OK) != -1)
		printf("El archivo existe.\n");
	else
		printf("El archivo no existe.\n");
	return (0);
}

// int	main(void)
// {
// 	// Verifica si el archivo es escribible y ejecutable
// 	if (access("archivo.txt", W_OK | X_OK) == 0)
// 		printf("El archivo es escribible y ejecutable.\n");
// 	else
// 		printf("El archivo no es escribible y ejecutable.\n");
// 	return (0);
// }
