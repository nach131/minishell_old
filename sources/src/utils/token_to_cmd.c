/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:25:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/10 13:55:33 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

char static	**args(t_list *token)
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

t_cmd static *one_cmd(t_list *token, t_list *env)
{
	t_cmd	*tmp;

	tmp = cmd_new((t_cmd){
		.command = access_file(token->content),
		.args = args(token),
		// .env = env_to_array(env),
		.env = ft_lst_to_dptr(&env, 0),
		.filefd = {STDIN_FILENO, STDOUT_FILENO},
		.prev = NULL,
		.next = NULL});
	return (tmp);
}

t_cmd static *two_cmd(t_list *token, t_list *env)
{
	t_cmd	*tmp;

	tmp = cmd_new((t_cmd){
		.command = access_file(token->content),
		.args = args(token),
		.env = ft_lst_to_dptr(&env, 0),
		.filefd = {STDIN_FILENO, STDOUT_FILENO},
		.prev = NULL,
		.next = NULL});
	return (tmp);
}

t_cmd	*token_to_pipe(t_list *token, t_list *env)
{
	t_cmd	*tmp;
	int		num_cmd;
	char	*command;

	num_cmd = count_cmd(token);
	printf(RED "\t%d\n", num_cmd);
	command = access_file(token->content);
	if (!command)
		tmp = NULL;
	else if (command && num_cmd == 0)
	{
		tmp = one_cmd(token, env);
		// tmp = cmd_new((t_cmd){command, args(token), {STDIN_FILENO,
		// 		STDOUT_FILENO}, NULL, NULL});
	}
	else if (command && num_cmd == 1)
	{
		printf("Solo Uno...\n");
		tmp = two_cmd(token, env);
	}
	else
	{
		printf("mas...\n");
		tmp = NULL;
	}
	return (tmp);
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt
