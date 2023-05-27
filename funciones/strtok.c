/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:21:48 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/26 23:38:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strtok(char *str, const char *sep)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == *sep)
			break;
		i++;
	}

	str[i] = '\0';

	return (str);
}

int main(void)
{
	char str[] = "COLORTERM=truecolor";
	char *token;

	printf("mio: %s\n", ft_strtok(str, "="));
	// Utilizar strtok para obtener el primer token antes del espacio en blanco
	token = strtok(str, "=");

	// Imprimir el token obtenido
	printf("%s\n", token);

	return 0;
}
