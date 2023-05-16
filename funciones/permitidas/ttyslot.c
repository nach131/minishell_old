/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyslot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:34:43 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 10:37:29 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ttyent.h>

int main()
{
	int slot = ttyslot();
	if (slot == -1)
	{
		perror("Error al obtener el número de ranura del terminal");
		return 1;
	}

	struct ttyent *tty = getttyent();
	if (tty == NULL)
	{
		perror("Error al obtener la información del terminal");
		return 1;
	}

	printf("El terminal asociado con la ranura %d es: %s\n", slot, tty->ty_name);

	endttyent();

	return 0;
}
