/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_to_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:24:26 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/04 13:31:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// Busca en el doble puntero de env si el comando pasado existe
// si es asi lo devuelve

char static	*real_command(char *file, char **paths)
{
	char	*tmp;
	char	*path;
	int		i;

	i = -1;
	while (paths[++i] != NULL)
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, file);
		if (access(path, X_OK) == 0)
		{
			free(tmp);
			return (path);
		}
		else
		{
			free(tmp);
			free(path);
		}
	}
	return (NULL);
}

char	*access_file(char *file, char **paths)
{
	// TODO
	if (!ft_strncmp(file, "echo", 5))
		return (ft_strdup("echo"));
	if (!ft_strncmp(file, "cd", 3))
		return (ft_strdup("cd"));
	// else if (!ft_strncmp(file, "pwd", 4))
	// 	return (ft_strdup("pwd"));
	else if (!ft_strncmp(file, "export", 7))
		return (ft_strdup("export"));
	else if (!ft_strncmp(file, "unset", 6))
		return (ft_strdup("unset"));
	else if (!ft_strncmp(file, "env", 4))
		return (ft_strdup("env"));
	else if (!ft_strncmp(file, "exit", 5))
		return (ft_strdup("exit"));
	else if (!ft_strncmp(file, ".", 1))
		return (ft_strdup(file));
	else if (!ft_strncmp(file, "/", 1))
		return (ft_strdup(file));
	return (real_command(file, paths));
}
