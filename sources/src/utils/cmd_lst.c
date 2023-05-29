/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:32:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/29 17:32:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

t_cmd	*cmd_new(char *str)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (!new)
		return (NULL);
	new->command = str;
	new->next = NULL;
	return (new);
}

// void cmd_add_back(t_cmd **cmd, t_cmd *new)
// {
// 	t_cmd
// }
