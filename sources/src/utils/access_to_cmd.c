/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_to_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:24:26 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/23 16:54:00 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

char static	*real_command(char *file)
{
	char	*path;

	path = ft_strjoin("/bin/", file);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	path = ft_strjoin("/usr/bin/", file);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	path = ft_strjoin("/sbin/", file);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	path = ft_strjoin("/usr/sbin/", file);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	return (NULL);
}

char	*access_file(char *file)
{
	// if (!ft_strncmp(file, "echo", 5))
	// 	return (ft_strdup("echo"));
	if (!ft_strncmp(file, "cd", 3))
		return (ft_strdup("cd"));
	else if (!ft_strncmp(file, "pwd", 4))
		return (ft_strdup("pwd"));
	else if (!ft_strncmp(file, "export", 7))
		return (ft_strdup("export"));
	else if (!ft_strncmp(file, "unset", 7))
		return (ft_strdup("unset"));
	else if (!ft_strncmp(file, "env", 4))
		return (ft_strdup("env"));
	else if (!ft_strncmp(file, "exit", 7))
		return (ft_strdup("exit"));
	return (real_command(file));
}
