/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:22:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 10:27:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h>

// int main()
// {
// 	char *name = ttyname(fileno(stdin));
// 	if (name != NULL)
// 	{
// 		printf("El nombre del dispositivo de terminal de entrada es: %s\n", name);
// 	}
// 	else
// 	{
// 		printf("La entrada estándar no está asociada con un dispositivo de terminal.\n");
// 	}

// 	return 0;
// }

int main()
{
	char *name = ttyname(fileno(stdout));
	if (name != NULL)
	{
		printf("El nombre del dispositivo de terminal de salida es: %s\n", name);
	}
	else
	{
		printf("La salida estándar no está asociada con un dispositivo de terminal.\n");
	}

	return 0;
}
