/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:32:18 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/02 23:00:31 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "control.h"

int ctrl_built_ins(char *command)
{
	if (command == NULL)
		return (0);
	else if (!ft_strncmp(command, "echo", 5))
		return (1);
	else if (!ft_strncmp(command, "cd", 3))
		return (1);
	else if (!ft_strncmp(command, "pwd", 4))
		return (1);
	else if (!ft_strncmp(command, "export", 7))
		return (1);
	else if (!ft_strncmp(command, "unset", 7))
		return (1);
	else if (!ft_strncmp(command, "env", 4))
		return (1);
	else if (!ft_strncmp(command, "exit", 7))
		return (1);
	return (0);
}
