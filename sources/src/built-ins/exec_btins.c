/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_btins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:02:58 by carles            #+#    #+#             */
/*   Updated: 2023/05/30 12:34:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// Chequea qué comando estamos introduciendo, si no es un builtin devuelve -1.
//	Si es un builtin ejecuta la función correspondiente.
//
int	execute_builtin(t_data *data, t_cmd *cmd)
{
	int	res;

	(void)data;
	res = CMD_NOT_FOUND;
	if (!ft_strncmp(cmd->command, "env", 4))
		// res = env_btin(data, cmd->args);
		print_env(data->env);
	else if (ft_strncmp(cmd->command, "export", 7) == 0)
		add_export(data->env, data->cmd);
	// res = export_btin(data, cmd->args);
	// else if (ft_strncmp(cmd->command, "pwd", 4) == 0)
	// 	res = pwd_btin(data, cmd->args);
	// else if (ft_strncmp(cmd->command, "cd", 3) == 0)
	// 	res = cd_btin(data, cmd->args);
	// else if (ft_strncmp(cmd->command, "echo", 5) == 0)
	// 	res = echo_btin(data, cmd->args);
	// else if (ft_strncmp(cmd->command, "unset", 6) == 0)
	// 	res = unset_btin(data, cmd->args);
	// else if (ft_strncmp(cmd->command, "exit", 5) == 0)
	// 	res = exit_btin(data, cmd->args);
	return (res);
}

// CMD_NOT_FOUND ES 127 NO -1 POR...?
