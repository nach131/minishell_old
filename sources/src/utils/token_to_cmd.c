/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:25:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/06 16:01:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// void	stop_to_pipe(t_list *token, t_cmd **cmd)
// {
// 	t_list	*tmp;

// 	(void)cmd;
// 	tmp = token;
// 	// while (tmp != NULL && ft_strncmp(tmp->content, "|", 2) != 0)
// 	while (tmp && (ft_strncmp(tmp->content, "|", 2) != 0))
// 	// && ft_strncmp(tmp->content, ">", 2) != 0))
// 	{
// 		ft_printf(RED "\t%s\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	// if (tmp != NULL)
// 	// 	stop_to_pipe(tmp, cmd);
// }

int static	count_token(t_list *token)
{
	t_list	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (tmp != NULL)
	{
		if (!ft_strncmp(tmp->content, "|", 1) || !ft_strncmp(tmp->content, ">",
				1))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

// cuando este todo en cmd, buscar desdel el primer args de cmd
char	*access_file(char *file)
{
	char	*path;

	path = ft_strjoin("/bin/", file);
	if (access(path, X_OK) == 0)
		return (path);
	else if (!ft_strncmp(file, "export", 7))
	{
		return ("tomate");
	}
	else
	{
		free(path);
		ft_strjoin("/usr/bin/", file);
		if (access(path, X_OK) == 0)
			return (path);
	}
	free(path);
	return (NULL);
}

// t_cmd	*token_to_pipe(t_list *token)
// {
// 	t_cmd	*tmp;
// 	int		num_cmd;

// 	// char	*command;
// 	tmp = malloc(sizeof(t_cmd));
// 	if (!access_file(token->content))
// 	{
// 		printf(RED "-bash: %s: command not found\n", token->content);
// 		return (tmp);
// 	}
// 	tmp->command = access_file(token->content);
// 	tmp->args = NULL;
// 	tmp->next = NULL;
// 	tmp->prev = NULL;
// 	// command = access_file(token->content);
// 	// printf(GREEN "command: %s\n", command);
// 	num_cmd = count_token(token);
// 	printf(RED "\t%d\n", num_cmd);
// 	return (tmp);
// }

// void	token_to_pipe(t_list *token, t_cmd **cmd)
t_cmd	*token_to_pipe(t_list *token)
{
	t_cmd	*tmp;
	int		num_cmd;

	(void)token;
	num_cmd = count_token(token);
	tmp = ft_calloc(1, sizeof(t_cmd));
	tmp->command = ft_strdup(token->content);
	// tmp->command = ft_substr(token->content, 0, 0xFFFFFFF);
	return (tmp);
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt

// cmd_add_back(t_cmd **cmd, t_cmd *new)
// cmd_add_back(t_cmd **cmd, (t_cmd){filefd[2],command...})
