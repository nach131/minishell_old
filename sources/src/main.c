/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:41 by caguerre          #+#    #+#             */
/*   Updated: 2023/05/09 16:09:08 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// // Función para salir del programa,
// // cerrando todos los fd y liberando memoria.
// // Ejecutamos una función para cerrar los fd y otra para liberar data.
// //
// static void	exit_msl(t_data *data, int gbl)
// {
// 	if (data)
// 	{
// 		if (data->cmd && data->cmd->fds)
// 			close_fds(data->cmd, true); //pendiente
// 		free_data(data, true);          //pendiente
// 	}
// 	exit(gbl);
// }

//
// Chequeamos los argumentos al iniciar minishell. El programa funcionará tanto
// // si no hay argumentos como si se proporciona un -c seguido de un argumento.
// // Devolverá true si minishell puede proceder y printeará false si no.
// //
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

// // Programa principal, arranca minishell y lo primero que hacemos es check de
// // parámetros. Luego determinamos si funciona en modo interactivo o no, y en
// // función de cada caso llamamos a la función correspondiente.
// //
// // La salida del programa es con el último comando.
// //
// int	main(int argc, char **argv, char **env)
// {
// 	t_data	data;

// 	ft_memset(&data, 0, sizeof(t_data));
// 	if (!check_params(&data, argc, argv))
// 		exit_msl(NULL, EXIT_FAILURE); //pendiente
// 	if (data.interactive == true)
// 		msl_interact(&data); //pendiente
// 	else
// 		msl_non_interact(&data); //pendiente
// 	exit_msl(&data, gbl_exit_code);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*linea;

// 	ft_printf(CYAN "Main\n");
// 	linea = readline("Ingrese una línea de texto: ");
// 	printf("La línea ingresada es:\n%s\n", linea);
// 	free(linea);
// }

// int	main(void)
// {
// 	HIST_ENTRY	*entry;

// 	// Agregamos algunas entradas al historial
// 	add_history("comando1");
// 	add_history("comando2");
// 	add_history("comando3");
// 	// Imprimimos el historial actual
// 	printf(CYAN "Historial antes de borrar:\n");
// 	// Acceder al tercer comando del historial
// 	// entry = history_get(3);
// 	for (int i = history_length; i > 0; i--)
// 	{
// 		entry = history_get(i);
// 		if (entry)
// 		{
// 			printf("%s\n", entry->line);
// 		}
// 	}
// 	printf(MAGENTA "Numero en el history: %d\n", history_length);
// 	rl_clear_history();
// 	printf(RED "Despues de rl_clear_history: %d\n", history_length);
// 	return (0);
// }

int	main(void)
{
	char	*input;

	while ((input = readline("Minishell> ")) != NULL)
	{
		// Procesamos la entrada
		printf("Entrada recibida: %s\n", input);
		// Reemplazamos la línea actual de entrada con una nueva línea
		rl_replace_line("Nueva línea\n", 1);
		// Redibujamos la nueva línea
		rl_redisplay();
		// Liberamos la memoria utilizada por readline para la entrada
		free(input);
	}
	return (0);
}
