/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_to_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:24:26 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/21 16:08:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// TODO
// Alaba comprobar el path de env separar por los :
// char static	*real_command(char *file)
// {
// 	char	*path;

// 	path = ft_strjoin("/bin/", file);
// 	if (access(path, X_OK) == 0)
// 		return (path);
// 	free(path);
// 	path = ft_strjoin("/usr/bin/", file);
// 	if (access(path, X_OK) == 0)
// 		return (path);
// 	free(path);
// 	path = ft_strjoin("/sbin/", file);
// 	if (access(path, X_OK) == 0)
// 		return (path);
// 	free(path);
// 	path = ft_strjoin("/usr/sbin/", file);
// 	if (access(path, X_OK) == 0)
// 		return (path);
// 	free(path);
// 	return (NULL);
// }

char static *real_command(char *file, char **paths)
{
	char	*path;

	(void)file;
	(void)path;
	(void)paths;
	int i = -1;

	while (paths[++i] != NULL)
	{

		printf("%s\n", paths[i]);
	}
	return (NULL);
}

char *access_file(char *file, char **paths)
{
	// if (!ft_strncmp(file, "echo", 5))
	// 	return (ft_strdup("echo"));
	// if (!ft_strncmp(file, "cd", 3))
	// 	return (ft_strdup("cd"));
	// else if (!ft_strncmp(file, "pwd", 4))
	// 	return (ft_strdup("pwd"));
	// else if (!ft_strncmp(file, "export", 7))
	// 	return (ft_strdup("export"));
	// else if (!ft_strncmp(file, "unset", 7))
	// 	return (ft_strdup("unset"));
	// else if (!ft_strncmp(file, "env", 4))
	// 	return (ft_strdup("env"));
	// else if (!ft_strncmp(file, "exit", 7))
	// 	return (ft_strdup("exit"));
	return (real_command(file, paths));
}
