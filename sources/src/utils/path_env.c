/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:47:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/21 11:27:36 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"
#include "path_env.h"

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

// Buscar en la lista el nodo con nombre PATH y devuelve solo el valor

char	**path_env(t_list *env)
{
	char	*res;
	char	**paths;
	int		num_paths;
	char	*path_copy;
	char	*token;

	paths = NULL;
	num_paths = 0;
	res = ft_lstfind_to_dptr(env, "PATH", find_env);
	res = env_value(res);
	path_copy = strdup(res);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		num_paths++;
		token = strtok(NULL, ":");
	}
	paths = (char **)malloc(num_paths * sizeof(char *));
	free(path_copy);
	path_copy = strdup(res);
	token = strtok(path_copy, ":");
	for (int i = 0; i < num_paths; i++)
	{
		paths[i] = strdup(token);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (paths);
}
