/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:32:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/07 11:19:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

t_cmd	*cmd_new(t_cmd cmd)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = cmd.command;
	new->filefd[0] = cmd.filefd[0];
	new->filefd[1] = cmd.filefd[1];
	new->args = cmd.args;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!(*cmd))
	{
		*cmd = new;
		new->prev = NULL; // Establecer prev como NULL para el primer nodo
	}
	else
	{
		last = cmd_last(*cmd);
		last->next = new;
		new->prev = last; // Establecer prev como el último nodo existente
	}
}

t_cmd	*cmd_last(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next != NULL)
		cmd = cmd->next;
	return (cmd);
}

void	cmd_iter(t_cmd *cmd, void (*funcion)(void *))
{
	while (cmd)
	{
		funcion(&cmd->command);
		cmd = cmd->next;
	}
}

void	cmd_free(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd != NULL)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->command)
		{
			free(tmp->command);
			// AQUI HAY QUE LIBERAR TODO LO DEMAS;
		}
		free(tmp);
	}
}
