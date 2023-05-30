/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:03:36 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/30 10:23:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_cmd
{
	char			*command;
	struct s_cmd	*next;
}					t_cmd;

t_cmd	*cmd_last(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next != NULL)
		cmd = cmd->next;
	return (cmd);
}

t_cmd	*cmd_new(char *str)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = str;
	new->next = NULL;
	return (new);
}

void	cmd_clear(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (cmd)
	{
		while (cmd != NULL)
		{
			tmp = cmd;
			cmd = cmd->next;
			free(tmp);
		}
	}
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!(*cmd))
		*cmd = new;
	else
	{
		last = cmd_last(*cmd);
		last->next = new;
	}
}

void	print_lst(t_cmd *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->command);
		lst = lst->next;
	}
}

int	main(void)
{
	t_cmd	*cmd;
	t_cmd	*current;

	cmd = NULL;
	cmd_add_back(&cmd, cmd_new("uno"));
	cmd_add_back(&cmd, cmd_new("dos"));
	cmd_add_back(&cmd, cmd_new("tres"));
	print_lst(cmd);
	cmd_clear(cmd);
	// Volver a asignar valores
	cmd = NULL;
	cmd_add_back(&cmd, cmd_new("cuatro"));
	cmd_add_back(&cmd, cmd_new("cinco"));
	cmd_add_back(&cmd, cmd_new("seis"));
	print_lst(cmd);
	cmd_clear(cmd);
	return (0);
}
