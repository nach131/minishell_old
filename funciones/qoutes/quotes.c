/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:03:36 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/30 23:24:17 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void	print_cmd(char **str)
{
	printf("%s\n", *str);
}

void	remove_quote(char **str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*result;

	i = 0;
	j = 0;
	tmp = *str;
	result = malloc(strlen(tmp) + 1);
	// Cadena temporal para almacenar el resultado
	while (tmp[i] != '\0')
	{
		if (tmp[i] != '\"')
		{
			result[j] = tmp[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	*str = result; // Asignar la cadena resultante a la cadena original
}

void	ft_lstiter(t_cmd *cmd, void (*funcion)(void *))
{
	while (cmd)
	{
		funcion(&cmd->command);
		cmd = cmd->next;
	}
}

void	cmd_free(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd != NULL)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->command); // Liberar la memoria de la cadena de comando
		free(tmp);          // Liberar la memoria del nodo
	}
}

int	main(void)
{
	t_cmd	*cmd;

	cmd = NULL;
	cmd_add_back(&cmd, cmd_new("NUEVO=\"toma mas\""));
	cmd_add_back(&cmd, cmd_new("dos"));
	cmd_add_back(&cmd, cmd_new("tres"));
	// remove_quotes_from_cmd_list(cmd);
	// print_lst(cmd);
	ft_lstiter(cmd, (void *)remove_quote);
	ft_lstiter(cmd, (void *)print_cmd);
	cmd_free(cmd);
	// Volver a asignar valores
	return (0);
}
