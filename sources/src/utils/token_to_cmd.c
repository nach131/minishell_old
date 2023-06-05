/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:25:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/04 21:19:48 by nmota-bu         ###   ########.fr       */
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

void	token_to_pipe(t_list *token, t_cmd **cmd)
{
	t_list	*tmp;
	int		num_cmd;

	num_cmd = count_token(token);
	(void)cmd;
	tmp = token;
	printf(RED "\t%d\n", num_cmd);
	// while (tmp != NULL && ft_strncmp(tmp->content, "|", 2) != 0)
	// while (tmp != NULL)
	// {
	// 	if (tmp && (ft_strncmp(tmp->content, "|", 2) != 0))
	// 		ft_printf(RED "\t%s\n", tmp->content);
	// 	else
	// 		break ;
	// 	tmp = tmp->next;
	// }
}
