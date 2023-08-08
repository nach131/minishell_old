/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:03:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/08 18:06:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"
#include <fcntl.h>
#include <stdlib.h> // para open
#include <unistd.h> // Para la función pipe()

void static	create_pipe(t_cmd *cmd, int i)
{
	if (pipe(cmd->filefd[i]) == 1)
	{
		perror("Error al crear la tubería");
		exit(1);
	}
}

void	pipe_to_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->num_cmd > 1)
	{
		cmd->filefd = malloc((cmd->num_cmd) * sizeof(int *));
		while (i < cmd->num_cmd - 1)
		{
			cmd->filefd[i] = malloc(2 * sizeof(int));
			if (cmd->out[i][0] == '|')
				create_pipe(cmd, i);
			else if (*cmd->out[i] == '>')
			{
				cmd->filefd[i][IN] = -1;
				cmd->filefd[i][OUT] = open(cmd->args[i + 1][0],
											O_WRONLY | O_CREAT | O_TRUNC,
											S_IRUSR | S_IWUSR);
			}
			else if (*cmd->out[i] == D_REDIR_OUT)
			{
				cmd->filefd[i][IN] = -1;
				cmd->filefd[i][OUT] = open(cmd->args[i + 1][0],
											O_WRONLY | O_CREAT | O_APPEND,
											S_IRUSR | S_IWUSR);
			}
			else if (*cmd->out[i] == '<')
			{
				cmd->filefd[i][OUT] = -1;
				cmd->filefd[i][IN] = open(cmd->args[i + 1][0], O_RDONLY);
			}
			i++;
		}
		cmd->filefd[i] = NULL;
	}
}

// Pone en cmd->out que tipo de redireccionamiento tine el comando
// Recorrer la lista token y guardar los valores de redirección en out

int static	what_pipe(char *pipe)
{
	if (!ft_strncmp(pipe, "|", 1))
		return (PIPE);
	else if (!ft_strncmp(pipe, ">>", 2))
		return (D_REDIR_OUT);
	else if (!ft_strncmp(pipe, ">", 1))
		return (REDIR_OUT);
	else if (!ft_strncmp(pipe, "<<", 2))
		return (D_REDIR_IN);
	else if (!ft_strncmp(pipe, "<", 1))
		return (REDIR_IN);
	return (-1);
}

void	process_redirections(t_cmd *cmd, t_list *token)
{
	t_list	*current_token;
	int		i;

	cmd->out = malloc((cmd->num_cmd + 1) * sizeof(char *));
	current_token = token;
	i = 0;
	while (current_token != NULL)
	{
		if (current_token->content[0] == '|' || current_token->content[0] == '>'
			|| current_token->content[0] == '<')
		{
			cmd->out[i] = ft_numdup(what_pipe(current_token->content));
			i++;
		}
		current_token = current_token->next;
	}
	cmd->out[i] = NULL;
}
