/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:20:11 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/09 14:14:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"

void	wait_pipe(pid_t *pid, int num_cmd)
{
	int	status;
	int	finished;
	int	i;
	int	result;

	i = -1;
	status = 0;
	finished = 0;
	// if (num_cmd >= 2)
	// num_cmd--;
	while (finished < num_cmd)
	{
		i = -1;
		while (++i < num_cmd)
		{
			result = waitpid(pid[i], &status, WNOHANG);
			if (result > 0)
				finished++;
		}
	}
	// TODO
	printf(CYAN "End\n" WHITE);
}
