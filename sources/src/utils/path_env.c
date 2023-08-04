/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:47:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/04 15:38:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "libft.h"
#include "minishell.h"
#include "path_env.h"

// Encuentra el valor, del nombre pasado en un lista

int find_env(char *s1, char *s2)
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

char static	*find_env_to_ptr(t_list *env)
{
	char	*res;

	res = ft_lstfind_to_dptr(env, "PATH", find_env);
	res = env_value(res);
	return (res);
}

// pasa los PATH  de la lista env a doble ptr

char	**path_env(t_list *env)
{
	t_path_env	data;

	data.res = find_env_to_ptr(env);
	data.path_copy = ft_strdup(data.res);
	data.token = ft_strtok(data.path_copy, ":");
	data.num_paths = ft_len_token(data.token, ":");
	data.paths = (char **)malloc((data.num_paths + 1) * sizeof(char *));
	free(data.path_copy);
	data.path_copy = ft_strdup(data.res);
	data.token = ft_strtok(data.path_copy, ":");
	data.i = -1;
	while (++data.i < data.num_paths)
	{
		data.paths[data.i] = ft_strdup(data.token);
		data.token = ft_strtok(NULL, ":");
	}
	data.paths[data.i] = NULL;
	free(data.path_copy);
	return (data.paths);
}
