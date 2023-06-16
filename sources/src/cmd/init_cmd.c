/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:35:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/16 19:06:40 by nmota-bu         ###   ########.fr       */
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
void static args(t_cmd *cmd, t_list *token)
{
	int num_args = cmd->num_cmd + 1;
	cmd->args = malloc((num_args) * sizeof(char *));

	int arg_index = 0;
	t_list *current_token = token;
	while (current_token != NULL)
	{
		if (!ft_strncmp(current_token->content, "|", 1) || !ft_strncmp(current_token->content, ">", 1) || !ft_strncmp(current_token->content, "<", 1))
		{
			current_token = current_token->next;
			continue;
		}
		int arg_length = 0;
		t_list *arg_token = current_token;
		while (arg_token != NULL && ft_strncmp(arg_token->content, "|", 1) && ft_strncmp(arg_token->content, ">", 1) && ft_strncmp(arg_token->content, "<", 1))
		{
			arg_length++;
			arg_token = arg_token->next;
		}
		cmd->args[arg_index] = malloc((arg_length + 1) * sizeof(char *));
		cmd->args[arg_index][arg_length] = NULL;
		int i = 0;
		while (i < arg_length)
		{
			cmd->args[arg_index][i] = ft_strdup(current_token->content);
			current_token = current_token->next;
			i++;
		}
		arg_index++;
	}
}

void static print_test(t_cmd *cmd)
{
	int i = 0;
	while (i < cmd->num_cmd)
	{
		int j = 0;
		printf(CYAN "%d\n", count_elements(cmd->args[i]));
		while (j < count_elements(cmd->args[i]))
		{
			printf(ORANGE "\t%s\n", cmd->args[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < cmd->num_cmd)
	{
		printf(CYAN "%s\n", cmd->command[i]);
		i++;
	}
}

void init_cmd(t_list *token, t_cmd *cmd)
{
	(void)token;
	cmd->num_cmd = count_commands(token) + 1;
	commands(cmd, token);
	args(cmd, token);

	print_test(cmd);
}
