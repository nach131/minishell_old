/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_btin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:50:12 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/05 20:36:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// TODO

// // unset uno dos tres
// Tiene que borra los tres env

#include "builtins.h"

// combinacion de la funcion ft_lstfind_rm y ft_lstfind
// busca el nombre de la variable dentro del la lista
// y si lo hay lo borra de la lista original

void static	env_find_rm(t_list **head, void *data_ref, int (*cmp)(char *,
			char *))
{
	t_list	*current;
	t_list	*prev;

	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		if ((*cmp)(current->content, data_ref) == 0)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->content);
			free(current);
			current = NULL;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	unset_btin(t_list *env_lst, char **args)
{
	int		i;
	char	*tmp;

	if (!args[1])
		return ;
	else
	{
		i = 1;
		while (args[i] != NULL)
		{
			take_quote(args[i]);
			tmp = ft_substr(args[i], 0, ft_strcspn(args[i], "="));
			if (!ft_lstfind(env_lst, tmp, find_env))
			{
				printf(RED "NO HAY: \n");
				return ;
			}
			else
				env_find_rm(&env_lst, tmp, find_env);
			free(tmp);
			i++;
		}
	}
}
