/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:25:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/08 08:23:03 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

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

char	*access_file(char *file)
{
	char	*path;

	path = ft_strjoin("/bin/", file);
	if (access(path, X_OK) == 0)
		return (path);
	else if (!ft_strncmp(file, "export", 7))
		return (ft_strdup("export"));
	else if (!ft_strncmp(file, "exit", 7))
		return (ft_strdup("exit"));
	else if (!ft_strncmp(file, "unset", 7))
		return (ft_strdup("unset"));
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

int	count_to_token(t_list *token)
{
	int	i;

	i = 0;
	while (token != NULL)
	{
		//CUIADO CON EL ESPACIO EN BLANCO
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content,
				">", 1))
			break ;
		i++;
		token = token->next;
	}
	return (i);
}

char	**args(t_list *token)
{
	int		num;
	char	**res;
	int		i;

	num = count_to_token(token);
	res = malloc(num * sizeof(char *) + 1);
	i = 0;
	while (i < num)
	{
		res[i] = ft_strdup(token->content);
		i++;
		token = token->next;
	}
	res[i] = NULL;
	return (res);
	// borrar todo los nodos ya pasados hasta el "|"
}

t_cmd	*token_to_pipe(t_list *token)
{
	t_cmd	*tmp;
	int		num_cmd;
	char	*command;

	num_cmd = count_token(token);
	command = access_file(token->content);
	if (!command)
		tmp = NULL;
	else
	{
		tmp = cmd_new((t_cmd){
			.command = access_file(token->content),
			.args = args(token),
			.filefd = {STDIN_FILENO, STDOUT_FILENO},
			.prev = NULL,
			.next = NULL});
	}
	return (tmp);
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt

// HACER EL TAB para listar los elementos de la carpeta actual
