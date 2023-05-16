/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:50:15 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 10:58:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *home = getenv("HOME");
	char *username = getenv("LOGNAME");
	char *path = getenv("PATH");
	if (home != NULL)
	{
		printf("El valor de la variable HOME es: %s\n", home);
		printf("El valor de la variable LOGNAME es: %s\n", username);
		printf("El valor de la variable PATH es: %s\n", path);
	}
	else
		printf("La variable HOME no está definida.\n");

	return 0;
}
