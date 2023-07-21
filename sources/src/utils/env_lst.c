/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:01:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/21 10:09:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// Encuentra el valor, del nombre pasado en un lista
int	find_env(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	if (s1[i] == '=')
		return (0);
	return (1);
}

// Quita el nombre del env y devuelve el valor
char	*env_value(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '=')
		{
			s++;
			return (s);
		}
		s++;
	}
	return (s);
}

// char *find_node_value(t_list *head, const char *target_value)
// {
// 	t_list *current = head;

// 	// Recorre la lista hasta encontrar el nodo con el valor deseado
// 	while (current != NULL)
// 	{
// 		if (strcmp(current->content, target_value) == 0)
// 			return (current->content);
// 		current = current->next;
// 	}

// 	// Si no se encuentra el valor en ningún nodo, retorna NULL
// 	return (NULL);
// }
