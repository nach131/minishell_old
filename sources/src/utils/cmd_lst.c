/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:32:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/29 18:04:16 by nmota-bu         ###   ########.fr       */
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

	new = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!new)
		return (NULL);
	new->command = str;
	new->next = NULL;
	return (new);
}

// void cmd_add_back(t_cmd **cmd, t_cmd *new)
// {
// 	t_cmd
// }

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*l_aux;

	if (!(*cmd))
		*cmd = new;
	else
	{
		l_aux = cmd_last(*cmd);
		l_aux->next = new;
	}
}

t_cmd	*cmd_last(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd)
	{
		if (cmd->next == NULL)
			return (cmd);
		cmd = cmd->next;
	}
	return (cmd);
}
