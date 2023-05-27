/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:41 by caguerre          #+#    #+#             */
/*   Updated: 2023/05/27 13:13:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"
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
	// signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, (void *)handle_int);
	signal(SIGQUIT, (void *)handle_quit);
	while (1)
	{
		data->line = readline("Minishell> ");
		add_history(data->line);
		data->cmd = cmd_new(data->line);
		// FALTA PARSEAR LA LINEA Y GUARDARLA EN CMD CON SUS SEPARADORES TOKEN
		// FALTA LIMPIAR CMD DESPUES DE USAR
		if (data->cmd)
		{
			// ft_printf(RED "%s\n", data->cmd->command);
			execute_builtin(data, data->cmd);
		}
		// printf("La línea ingresada es:\n%s\n", data->line);
		free(data->line);
		// if (history_length)
		// {
		// 	ft_printf(RED "cmd %d\n" WHITE, history_length);
		// }
	}
}

t_list	*init_env(char **env)
{
	int		i;
	t_list	*new;

	i = 0;
	while (env[i] != NULL)
	{
		if (!i)
			new = ft_lstnew(env[i]);
		else
			ft_lstadd_back(&new, ft_lstnew(env[i]));
		i++;
	}
	return (new);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = ft_calloc(sizeof(t_data), 1);
	// ft_bzero(&data, sizeof(t_data));
	data->env = init_env(env);
	//=========================================================================
	parser();
	// start_export(data->env);
	//=========================================================================

	//init_path(data);
	//  if (!check_params(&data, argc, argv))
	//  	exit_msl(NULL, EXIT_FAILURE); // pendiente
	//  if (data->interactive == true)
	//  	msl_interact(&data); // pendiente
	//  else
	//  	msl_non_interact(&data); // pendiente
	//  exit_msl(&data, gbl_exit_code);
	start(data);
	return (0);
}
