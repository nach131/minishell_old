/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:41 by caguerre          #+#    #+#             */
/*   Updated: 2023/06/10 13:54:25 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"
#include "minishell.h"
#include "working_tools.h"

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
	char	*line;
	t_list	*token;
	t_cmd	*cmd;

	while (1)
	{
		line = readline("Minishell> ");
		add_history(line);
		token = parser_space_lst(line);
		ft_lstprint(token);
		cmd = token_to_pipe(token, data->env);
		if (cmd)
		{
			printf(RED "cmd: %s\n" WHITE, cmd->command);
			execute_builtin(data, cmd);
			cmd_free(cmd);
		}
		else
			printf(RED "-Minishell: %s: command not found\n" WHITE,
					token->content);
		if (token)
			ft_lstfree(token);
		if (line)
			free(line);
		// history_line(); // ESTO EN FUNCION EXIT
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
	t_data	data;

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	data.env = init_env(env);
	// signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, (void *)handle_int);
	signal(SIGQUIT, (void *)handle_quit);
	start(&data);
	return (0);
}
