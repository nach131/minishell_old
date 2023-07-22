/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:41 by caguerre          #+#    #+#             */
/*   Updated: 2023/07/22 13:44:15 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"
#include "cmd.h"
#include "control.h"
#include "ft_printf.h"
#include "minishell.h"
#include "working_tools.h"

void	start(t_data *data)
{
	char	*line;
	t_list	*token;
	t_cmd	*cmd;

	(void)data;
	cmd = ft_calloc(1, sizeof(t_cmd));
	while (1)
	{
		line = readline("Minishell> ");
		add_history(line);
		token = parser_space_lst(line);
		token_split(&token);
		if (token)
			init_cmd(token, data->env, cmd);
		if (token && cmd->command[0])
		{
			ft_lstprint(token);
			ft_printf(ORANGE "\tCOMMANDS\n" WHITE);
			ft_print_dptr(cmd->command);
			ft_printf(ORANGE "\tARGS\n" WHITE);
			ft_print_tptr(cmd->args);
			print_filefd(cmd->filefd);
			ft_print_dptr(cmd->out);
			//
			execute_builtin(data, cmd);
			//
			free_cmd(cmd);
		}
		else if (cmd->num_cmd && token)
			// esta tiene que estar en una funcion y pasarla tambien cuando
			// en algun comano no hace nada
			printf(RED "-Minishell: %s: command not found \n" WHITE,
					token->content);
		if (token)
			// AQUI SOLO FREE DE LOS ELEMENTOS DE LA LISTA
			// FREE DE TOKEN EN EL EXIT
			ft_lstfree_node(&token);
		// ft_lstfree(token);
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

TODO
	// en el caso de que se ejecute minishell dentro de minishell hay que sumar uno en SHLVL=2
	// Funcion exit hay que restar un numero de SHLVL=2 y salir...?
