/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:35:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/16 18:39:26 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"

void static commands(t_cmd *cmd, t_list *token)
{
	int i = 0;
	int valid_cmds = 0; // Contador para rastrear el número de comandos válidos agregados

	cmd->command = malloc((cmd->num_cmd + 1) * sizeof(char *));
	while (token != NULL)
	{
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1) || !ft_strncmp(token->content, "<", 1))
		{
			// Ignorar "|", "<" y ">"
			token = token->next;
			continue;
		}
		if (i % 2 == 0)
		{
			// Agregar el primer valor de la lista
			cmd->command[valid_cmds] = access_file(token->content);
			valid_cmds++;
		}

		token = token->next;
		i++;
	}
}

void init_cmd(t_list *token, t_cmd *cmd)
{
	(void)token;
	cmd->num_cmd = count_commands(token) + 1;
	commands(cmd, token);
	int i = 0;
	while (i < cmd->num_cmd)
	{
		printf(CYAN "%s\n", cmd->command[i]);
		i++;
	}
}
