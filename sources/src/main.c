/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:41 by caguerre          #+#    #+#             */
/*   Updated: 2023/06/19 17:33:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131/                       ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"
#include "cmd.h"
#include "minishell.h"
#include "working_tools.h"

void	start(t_data *data)
{
	char	*line;
	t_list	*token;
	t_cmd	*cmd;

	(void)data;
	cmd = malloc(sizeof(t_cmd));
	while (1)
	{
		line = readline("Minishell> ");
		add_history(line);
		token = parser_space_lst(line);
		// ft_lstprint(token); // ESTO QUITAR SOLO ES PARA IMPRIMIR
		// cmd = token_to_pipe(token, data->env);
		init_cmd(token, data->env, cmd);
		printf(CYAN "num:%d\n" WHITE, cmd->num_cmd);
		if (cmd)
		{
			printf(MAGENTA "hay cmd, hay que exec\n");

			execute_builtin(data, cmd);
			free_cmd(cmd);
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
