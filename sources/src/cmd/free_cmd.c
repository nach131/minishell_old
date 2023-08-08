/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:59:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/08 15:42:59 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"

void static	free_filefd(t_cmd *cmd)
{
	int	i;

	if (cmd->filefd == NULL)
		return ;
	if (cmd->filefd != NULL)
	{
		i = -1;
		while (cmd->filefd[++i] != NULL)
		{
			free(cmd->filefd[i]);
			cmd->filefd[i] = NULL;
		}
		free(cmd->filefd);
		cmd->filefd = NULL;
	}
}

void static	free_intptr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	ft_free_dptr(cmd->command);
	ft_free_tptr(cmd->args);
	ft_free_dptr(cmd->env);
	// ft_free_dptr(cmd->out);
	free_intptr(cmd->out);
	free_filefd(cmd);
	free(cmd->builtin);
	cmd->command = NULL;
	cmd->args = NULL;
	cmd->env = NULL;
	cmd->out = NULL;
	cmd->builtin = NULL;
}
