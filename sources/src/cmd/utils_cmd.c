/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:37:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/19 17:00:46 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "cmd.h"
#include "minishell.h"

// Cuenta cuantos comandos tiene readline
int	count_commands(t_list *token)
{
	int	count;
	int	inCommand;

	count = 0;
	inCommand = 0;
	while (token != NULL)
	{
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content,
				">", 1) || !ft_strncmp(token->content, "<", 1))
			inCommand = 1;
		else if (inCommand && ft_strncmp(token->content, "|", 1)
				&& ft_strncmp(token->content, ">", 1)
				&& ft_strncmp(token->content, "<", 1))
		{
			count++;
			inCommand = 0;
		}
		token = token->next;
	}
	return (count);
}

// Contar el numero de elementos del comando
int	count_elements(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
	{
		count++;
	}
	return (count);
}
