/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:32:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/30 23:37:24 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

t_cmd	*cmd_new(char *str)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = ft_strdup(str);
	new->next = NULL;
	return (new);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!(*cmd))
		*cmd = new;
	else
	{
		last = cmd_last(*cmd);
		last->next = new;
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

// void	cmd_clear(t_cmd *cmd)
// {
// 	t_cmd	*tmp;

// 	if (cmd)
// 	{
// 		while (cmd != NULL)
// 		{
// 			tmp = cmd;
// 			cmd = cmd->next;
// 			free(tmp);
// 		}
// 	}
// }

void	cmd_free(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd != NULL)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->command)
			free(tmp->command);
		free(tmp);
	}
}
