/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isatty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:18:42 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 10:21:19 by nmota-bu         ###   ########.fr       */
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
// 	if (isatty(fileno(stdin)))
// 	{
// 		printf("La entrada estándar es un terminal interactivo.\n");
// 	}
// 	else
// 	{
// 		printf("La entrada estándar no es un terminal interactivo.\n");
// 	}

// 	return 0;
// }

int main()
{
	if (isatty(fileno(stdout)))
	{
		printf("La salida estándar es un terminal interactivo.\n");
	}
	else
	{
		printf("La salida estándar no es un terminal interactivo.\n");
	}

	return 0;
}
