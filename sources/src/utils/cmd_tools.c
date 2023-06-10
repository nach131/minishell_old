/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:15:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/10 12:30:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// cuenta la cantidad de elementos (cmd) en la lista
int	count_cmd(t_list *token)
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
