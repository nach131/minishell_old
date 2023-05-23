/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carles <carles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:17:14 by carles            #+#    #+#             */
/*   Updated: 2023/05/23 23:52:12 by carles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
//	Primero cerramos todos los fd que tengamos. Puede que también tengamos 
// que cerrar los fd pipes.
//
void	close_fds(t_cmd *cmd, bool close_backups)
{
	if (cmd->fds)
	{
		if (cmd->fds->in_file != -1)
			close(cmd->fds->in_file);
		if (cmd->fds->out_file != -1)
			close(cmd->fds->out_file);
	}
}

// Cerramos todos los fd que tengamos abiertos y salimos de minishell
// liberando toda la memoria alocada
//
void	exit_msl(t_data *data, int res)
{
	if (data)
	{
		if (data->cmd && data->cmd->fds)
			close_fds(data->cmd, true);
		//free_all(data, true);  <--- esto tiene mucha chicha, hay que liberar incluso punteros
	}
	exit(res);
}
