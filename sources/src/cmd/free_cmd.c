/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:59:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/21 20:32:58 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"
#include "working_tools.h"

// void static	free_commnad(char **command)
// {
// 	int	i;

// 	if (command == NULL)
// 		return ;
// 	i = 0;
// 	while (command[i] != NULL)
// 	{
// 		free(command[i]);
// 		// command[i] = NULL;
// 		i++;
// 	}
// 	free(command);
// 	command = NULL;
// }

// void static	free_args(t_cmd *cmd)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (cmd->args == NULL)
// 		return ;
// 	while (i < cmd->num_cmd)
// 	{
// 		if (cmd->args[i] != NULL)
// 		{
// 			j = 0;
// 			while (cmd->args[i][j] != NULL)
// 			{
// 				if (cmd->args[i][j] != NULL)
// 					free(cmd->args[i][j]);
// 				j++;
// 			}
// 			free(cmd->args[i]);
// 		}
// 		i++;
// 	}
// 	free(cmd->args);
// 	cmd->args = NULL;
// }

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
			// close(cmd->filefd[i][IN]);
			// close(cmd->filefd[i][OUT]);
			free(cmd->filefd[i]);
		}
		free(cmd->filefd);
		cmd->filefd = NULL;
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	ft_free_dptr(cmd->command);
	ft_free_dptr(cmd->env);
	ft_free_dptr(cmd->out);
	ft_free_tptr(cmd->args);
	free_filefd(cmd);
	cmd->command = NULL;
	cmd->args = NULL;
	cmd->env = NULL;
	cmd->out = NULL;
	// cmd->filefd = NULL;
	// Free env if needed (assuming it follows the same structure as args)
}
