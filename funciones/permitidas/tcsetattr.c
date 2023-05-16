/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcsetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:59:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/16 11:09:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main()
{
	struct termios new_attr;
	if (tcgetattr(STDIN_FILENO, &new_attr) == -1)
	{
		perror("Error al obtener la configuración del terminal");
		return 1;
	}

	// Configuración básica del terminal
	new_attr.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
	new_attr.c_oflag &= ~OPOST;
	new_attr.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	new_attr.c_cflag &= ~(CSIZE | PARENB);
	new_attr.c_cflag |= CS8;

	if (tcsetattr(STDIN_FILENO, TCSANOW, &new_attr) == -1)
	{
		perror("Error al establecer la configuración del terminal");
		return 1;
	}

	printf("Configuración del terminal establecida correctamente.\n");

	return 0;
}

