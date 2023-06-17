/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:03:04 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/17 19:24:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"
#include <unistd.h> // Para la función pipe()

// void	pipes_to_cmd(t_cmd *cmd, t_list *token)
// {
// 	if (cmd->num_cmd == 1)
// 	{
// 		cmd->filefd[0] = malloc(2 * sizeof(int));
// 		cmd->filefd[0][0] = STDIN_FILENO;
// 		cmd->filefd[0][1] = STDOUT_FILENO;
// 		cmd->filefd[1] = NULL;
// 	}
// }

void	pipes_to_cmd(t_cmd *cmd, t_list *token)
{
	t_list	*current_token;
	int		i;

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
		cmd->filefd = malloc((cmd->num_cmd + 1) * sizeof(int *));
		current_token = token;
		i = 0;
		while (current_token != NULL)
		{
			if (!ft_strncmp(current_token->content, "|", 1))
			{
				cmd->filefd[i] = malloc(2 * sizeof(int));
				pipe(cmd->filefd[i]);
				i++;
			}
			current_token = current_token->next;
		}
		cmd->filefd[i] = malloc(2 * sizeof(int));
		cmd->filefd[i][0] = STDIN_FILENO;
		cmd->filefd[i][1] = STDOUT_FILENO;
		cmd->filefd[i + 1] = NULL;
	}
}
