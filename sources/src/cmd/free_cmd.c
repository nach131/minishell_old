/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:59:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/20 16:21:24 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"

void static	free_commnad(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->num_cmd)
	{
		if (cmd->command[i] != NULL)
			free(cmd->command[i]);
		i++;
	}
	free(cmd->command);
}

void static	free_args(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (i < cmd->num_cmd)
	{
		if (cmd->args[i] != NULL)
		{
			j = 0;
			while (cmd->args[i][j] != NULL)
			{
				if (cmd->args[i][j] != NULL)
					free(cmd->args[i][j]);
				j++;
			}
			free(cmd->args[i]);
		}
		i++;
	}
	free(cmd->args);
}

void static	free_filefd(t_cmd *cmd)
{
	int	i;

	if (cmd->filefd != NULL)
	{
		i = -1;
		while (cmd->filefd[++i] != NULL)
		{
			// close(cmd->filefd[i][IN]);
			// close(cmd->filefd[i][OUT]);
			free(cmd->filefd[i]);
		}
		free(cmd->filefd);
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->command != NULL)
		free_commnad(cmd);
	if (cmd->args != NULL)
		free_args(cmd);
	if (cmd->filefd != NULL)
		free_filefd(cmd);
	// Free env if needed (assuming it follows the same structure as args)
	// free(cmd);
}
