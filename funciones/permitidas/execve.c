/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:26:19 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/02 11:46:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int main()
// {
// 	char *const argv[] = {"ls", "-la", NULL};
// 	char *const envp[] = {NULL};

// 	if (execve("/bin/ls", argv, envp) == -1)
// 	{
// 		perror("Error al ejecutar el programa");
// 		return 1;
// 	}

// 	return 0;
// }
int main()
{
	char *pwd = getenv("PWD");
	if (pwd == NULL)
	{
		perror("Error al obtener la variable de entorno PWD");
		return 1;
	}

	char *argv[] = {"echo", "Valor de PWD:", pwd, NULL};
	char *env[] = {"CUSTOM_VAR=42 Barcelona", NULL};

	if (execve("/bin/echo", argv, env) == -1)
	{
		perror("Error al ejecutar el programa");
		return 1;
	}

	return 0;
}

// int main() {
//     char *args[] = {"./mi_programa", "arg1", "arg2", NULL};
//     char *env[] = {"VAR1=valor1", "VAR2=valor2", NULL};
//     execve("./mi_programa", args, env);
//     return 0;
// }

// int main() {
//     char *args[] = {"python", "mi_script.py", "arg1", "arg2", NULL};
//     execve("/usr/bin/python", args, NULL);
//     return 0;
// }

// int main() {
//     char *args[] = {"ls", "-l", "/root", NULL};
//     execve("/usr/bin/sudo", args, NULL);
//     return 0;
// }
