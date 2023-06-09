/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:25:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/09 12:15:59 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// cuenta la cantidad de elementos (cmd) en la lista
int static	count_cmd(t_list *token)
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

// cuenta la cantidad de elementos en la lista token
//  hasta encontrar el primer "|" o ">"
int	count_to_token_cmd(t_list *token)
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

	num = count_to_token_cmd(token);
	res = malloc((num + 1) * sizeof(char *));
	i = 0;
	while (token != NULL)
	{
		res[i] = ft_strdup(token->content);
		i++;
		token = token->next;
	}
	res[i] = NULL;
	// borrar todo los nodos ya pasados hasta el "|"
	return (res);
}

t_cmd	*token_to_pipe(t_list *token, t_list *env)
{
	t_cmd	*tmp;
	int		num_cmd;
	char	*command;

	(void)env;
	num_cmd = count_cmd(token);
	command = access_file(token->content);
	if (!command)
		tmp = NULL;
	else
	{
		tmp = cmd_new((t_cmd){
			.command = command,
			.args = args(token),
			.env = env_to_array(env),
			.filefd = {STDIN_FILENO, STDOUT_FILENO},
			.prev = NULL,
			.next = NULL});
		// tmp = cmd_new((t_cmd){command, args(token), {STDIN_FILENO,
		// 		STDOUT_FILENO}, NULL, NULL});
	}
	return (tmp);
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt
