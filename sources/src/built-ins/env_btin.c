/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_btin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:26:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/03 12:02:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"
#include "libft.h"

void	env_btin(char **env, int fd)
{
	int	i;
	// TODO
	// quitar fd de la funcion si al final no la necesito para
	// las redirecciones
	(void)fd;

	i = 0;
	if (env == NULL)
		return ;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
