/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:01:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/10 13:55:03 by nmota-bu         ###   ########.fr       */
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

// PASSADA A LIBFT
// Pasa las lista env a array
// char	**env_to_array(t_list *env)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int		num;
// 	char	**array;

// 	tmp = env;
// 	i = 0;
// 	num = ft_lstsize(tmp);
// 	array = malloc((num + 1) * sizeof(char *));
// 	while (tmp)
// 	{
// 		array[i] = ft_strdup(tmp->content);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	array[i] = NULL;
// 	return (array);
// }
