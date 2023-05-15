/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:26:19 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/15 16:34:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <unistd.h>
#include <stdio.h>

int main()
{
	char *const argv[] = {"ls", "-la", NULL};
	char *const envp[] = {NULL};

	if (execve("/bin/ls", argv, envp) == -1)
	{
		perror("Error al ejecutar el programa");
		return 1;
	}

	return 0;
}

// int main()
// {
// 	char *const argv[] = {"echo", "Hello, World!", NULL};
// 	char *const envp[] = {"CUSTOM_VAR=OpenAI", NULL};

// 	if (execve("/bin/echo", argv, envp) == -1)
// 	{
// 		perror("Error al ejecutar el programa");
// 		return 1;
// 	}

// 	return 0;
// }
