/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:41 by caguerre          #+#    #+#             */
/*   Updated: 2023/08/08 22:37:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"
#include "cmd.h"
#include "control.h"
#include "enum.h"
#include "ft_printf.h"
#include "minishell.h"
#include "working_tools.h"

// char static	*getpwd(void)
// {
// 	char	*pwd;
// 	char	*tmp;

// 	pwd = getcwd(NULL, 0);
// 	tmp = ft_strjoin("\033[0;33m", pwd);
// 	free(pwd);
// 	pwd = ft_strjoin(tmp, "$ \033[0;37m");
// 	free(tmp);
// 	return (pwd);
// }

void	start(t_data *data)
{
	char	*line;
	t_list	*token;
	t_cmd	*cmd;

	// char	*prompt;
	cmd = ft_calloc(1, sizeof(t_cmd));
	while (1)
	{
		// prompt = getpwd();
		// line = readline(prompt);
		//
		line = readline("Minishell> ");
		add_history(line);
		token = parser_space_lst(line);
		// TODO
		// solucionar el token_split con >>  y <<
		// token_split(&token);
		ft_lstiter(token, remove_quotes);
		if (token)
			init_cmd(token, data->env, cmd);
		if (token && cmd->command[0])
		{
			printf("________________________________________\n");
			ft_lstprint(token);
			printf(ORANGE "num_command: %d\n" WHITE, cmd->num_cmd);
			ft_printf(ORANGE "\tCOMMANDS\n" WHITE);
			ft_print_dptr(cmd->command);
			ft_printf(ORANGE "\tARGS\n" WHITE);
			ft_print_tptr(cmd->args);
			print_filefd(cmd->filefd);
			print_out(cmd->out);
			print_builtin(cmd->builtin, cmd->num_cmd);
			//
			execute_command(data, cmd);
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
		// free(prompt); // ACTIVAR CUANDO prompt
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
	//
	if (data.power)
		printf("Power: %d \n", data.power);
	printf("Power: %d \n", data.power);
	data.power = ON;
	//
	data.env = init_env(env);
	// signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, (void *)handle_int);
	signal(SIGQUIT, (void *)handle_quit);
	start(&data);
	return (0);
}

// TODO
// en el caso de que se ejecute minishell dentro de minishell hay que sumar uno en SHLVL=2
// Funcion exit hay que restar un numero de SHLVL=2 y salir ..?
// FALTA
// $?
// >> <<
//  cotrolar el typeo dinamico
//
// built-ins
// todo lo que salga en pantalla (printf) hacerlo pasar por ft_putchar,
// usando el fd necesario asi cuando este el pipe se puede rediriguir...?
