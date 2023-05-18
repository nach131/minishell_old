/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:41 by caguerre          #+#    #+#             */
/*   Updated: 2023/05/18 18:14:16 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"
#include "tools.h"

// // Función para salir del programa,
// // cerrando todos los fd y liberando memoria.
// // Ejecutamos una función para cerrar los fd y otra para liberar data.
// //
// static void	exit_msl(t_data *data, int gbl)
// {
// 	if (data)
// 	{
// 		if (data->cmd && data->cmd->fds)
// 			close_fds(data->cmd, true); // pendiente
// 		free_data(data, true);          // pendiente
// 	}
// 	exit(gbl);
// }

//
// Chequeamos los argumentos al iniciar minishell.El programa funcionará tanto
// si no hay argumentos como si se proporciona un -c seguido de un argumento.
// Devolverá true si minishell puede proceder y printeará false si no.
//

// static bool	check_params(t_data *data, int argc, char **argv)
// {
// 	if (argc != 1 && argc != 3)
// 		return (print_message(false));
// 	if (argc == 3)
// 	{
// 		data->interactive = false;
// 		if (!argv[1] || (argv[1] && ft_strcmp(argv[1], "-c") != 0))
// 			return (print_message(false));
// 		else if (!argv[2] || (argv[2] && argv[2][0] == '\0'))
// 			return (print_message(false));
// 	}
// 	else
// 		data->interactive = true;
// 	return (true);
// }

// Programa principal, arranca minishell y lo primero que hacemos es check de
// parámetros. Luego determinamos si funciona en modo interactivo o no, y en
// función de cada caso llamamos a la función correspondiente.
//
// La salida del programa es con el último comando.

void	start(t_data *data)
{
	printf_env(data->env);
	while (1)
	{
		data->line = readline("Minishell> ");
		printf("La línea ingresada es:\n%s\n", data->line);
		free(data->line);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = ft_calloc(sizeof(t_data), 1);
	data->env = env;
	// esto es para comprobar
	// if (!check_params(&data, argc, argv))
	// 	exit_msl(NULL, EXIT_FAILURE); // pendiente
	// if (data->interactive == true)
	// 	msl_interact(&data); // pendiente
	// else
	// 	msl_non_interact(&data); // pendiente
	// exit_msl(&data, gbl_exit_code);
	start(data);
	return (0);
}
