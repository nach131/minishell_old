/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:35:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/21 10:09:18 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"
#include "working_tools.h"

void	commands(t_cmd *cmd, t_list *token)
{
	t_list	*current;
	int		i;
	int		flag;

	current = token;
	cmd->command = malloc((cmd->num_cmd + 1) * sizeof(char *));
	i = 0;
	flag = 1;
	current = token;
	while (current != NULL)
	{
		if (current->content[0] != '-' && current->content[0] != '<'
			&& current->content[0] != '>' && current->content[0] != '|' && flag)
		{
			// cmd->command[i] = strdup(current->content);
			cmd->command[i] = access_file(current->content);
			i++;
			flag = 0;
		}
		if (current->content[0] == '|')
			flag = 1;
		current = current->next;
	}
	cmd->command[i] = NULL;
}

void static	args(t_cmd *cmd, t_list *token)
{
	int		num_args;
	int		arg_index;
	t_list	*current_token;
	int		arg_length;
	t_list	*arg_token;
	int		i;

	num_args = cmd->num_cmd + 1;
	cmd->args = malloc((num_args) * sizeof(char *));
	arg_index = 0;
	current_token = token;
	while (current_token != NULL)
	{
		if (!ft_strncmp(current_token->content, "|", 1)
			|| !ft_strncmp(current_token->content, ">", 1)
			|| !ft_strncmp(current_token->content, "<", 1))
		{
			current_token = current_token->next;
			continue ;
		}
		arg_length = 0;
		arg_token = current_token;
		while (arg_token != NULL && ft_strncmp(arg_token->content, "|", 1)
			&& ft_strncmp(arg_token->content, ">", 1)
			&& ft_strncmp(arg_token->content, "<", 1))
		{
			arg_length++;
			arg_token = arg_token->next;
		}
		cmd->args[arg_index] = malloc((arg_length + 1) * sizeof(char *));
		cmd->args[arg_index][arg_length] = NULL;
		i = 0;
		while (i < arg_length)
		{
			cmd->args[arg_index][i] = ft_strdup(current_token->content);
			current_token = current_token->next;
			i++;
		}
		arg_index++;
	}
	cmd->args[arg_index] = NULL;
}

// Buscar en la lista el nodo con nombre PATH y devuelve solo el valor
char static	*path_env(t_list *env)
{
	char	*res;

	res = ft_lstfind_to_dptr(env, "PATH", find_env);
	res = env_value(res);
	return (res);
}

void	init_cmd(t_list *token, t_list *env, t_cmd *cmd)
{
	char	*path;

	path = path_env(env);
	printf(GREEN "%s\n", path);
	//
	cmd->num_cmd = count_commands(token) + 1;
	commands(cmd, token);
	args(cmd, token);
	cmd->env = ft_lst_to_dptr(&env, 0);
	process_redirections(cmd, token);
	pipe_to_cmd(cmd);
}

// ANTIC
// void static	commands(t_cmd *cmd, t_list *token)
// {
// 	int	i;
// 	int	valid_cmds;

// 	i = 0;
// 	valid_cmds = 0;
// 	// Contador para rastrear el número de comandos válidos agregados
// 	cmd->command = malloc((cmd->num_cmd + 1) * sizeof(char *));
// 	while (token != NULL)
// 	{
// 		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content,
// 				">", 1) || !ft_strncmp(token->content, "<", 1))
// 		{
// 			// Ignorar "|", "<" y ">"
// 			token = token->next;
// 			continue ;
// 		}
// 		if (i % 2 == 0)
// 		{
// 			// Agregar el primer valor de la lista
// 			// cmd->command[valid_cmds] = access_file(token->content);
// 			cmd->command[valid_cmds] = ft_strdup(token->content);
// 			valid_cmds++;
// 		}
// 		token = token->next;
// 		i++;
// 	}
// 	cmd->command[valid_cmds] = NULL;
// }
