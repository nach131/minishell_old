/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:03:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/23 17:05:51 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"
#include <unistd.h> // Para la función pipe()

void	pipe_to_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->num_cmd == 1)
	{
		cmd->filefd = malloc(2 * sizeof(int *));
		cmd->filefd[0] = malloc(2 * sizeof(int));
		cmd->filefd[0][0] = STDIN_FILENO;
		cmd->filefd[0][1] = STDOUT_FILENO;
		cmd->filefd[1] = NULL;
	}
	else
	{
		cmd->filefd = malloc((cmd->num_cmd) * sizeof(int *));
		while (i < cmd->num_cmd - 1)
		{
			cmd->filefd[i] = malloc(2 * sizeof(int));
			if (!ft_strncmp(cmd->out[i], "|", 1))
				if (pipe(cmd->filefd[i]) == 1)
				{
					perror("Error al crear la tubería");
					exit(1);
				}
			if (!ft_strncmp(cmd->out[i], ">", 1))
			{
				printf(RED "%s\n", cmd->out[i]);
				// Aqui abrir el filfd del fichero;
			}
			if (!ft_strncmp(cmd->out[i], "<", 1))
			{
				printf(RED "%s\n", cmd->out[i]);
				// Aqui abrir el filfd del fichero;
			}
			i++;
		}
		cmd->filefd[i] = NULL;
	}
}

// Pone en cmd->out que tipo de redireccionamiento tine el comando
void	process_redirections(t_cmd *cmd, t_list *token)
{
	t_list	*current_token;
	int		redirection_index;

	cmd->out = malloc((cmd->num_cmd) * sizeof(char *));
	current_token = token;
	redirection_index = 0;
	// Recorrer la lista token y guardar los valores de redirección en out
	while (current_token != NULL)
	{
		if (!ft_strncmp(current_token->content, "|", 1) ||
			!ft_strncmp(current_token->content, ">", 1) ||
			!ft_strncmp(current_token->content, "<", 1))
		{
			cmd->out[redirection_index] = ft_strdup(current_token->content);
			redirection_index++;
		}
		current_token = current_token->next;
	}
	cmd->out[redirection_index] = NULL;
}
