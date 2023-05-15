/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:33:25 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 12:45:10 by nmota-bu         ###   ########.fr       */
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
// 	char cwd[256];

// 	if (getcwd(cwd, sizeof(cwd)) != NULL)
// 	{
// 		printf("Directorio de trabajo actual: %s\n", cwd);
// 	}
// 	else
// 	{
// 		perror("Error al obtener el directorio de trabajo actual");
// 		return (1);
// 	}

// 	return (0);
// }

int	main(void)
{
	char	cwd[256];

	if (chdir("/tmp") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("Nuevo directorio de trabajo actual: %s\n", cwd);
		}
		else
		{
			perror("Error al obtener el directorio de trabajo actual");
			return (1);
		}
	}
	else
	{
		perror("Error al cambiar de directorio");
		return (1);
	}
	return (0);
}
