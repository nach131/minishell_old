/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_btin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:58:55 by carles            #+#    #+#             */
/*   Updated: 2023/07/23 14:34:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// Esto ejecuta el buildin pwd y nos muestra el directorio actual (act_dir) con
// su path mediante la función de sistema getcwd.
//
int pwd_btin(t_data *data, char **args)
{
    char    buf[PATH_MAX];
    char    *dir;

    (void)args;
    if (data->act_dir)
    {
        ft_putendl_fd(data->act_dir, 1);
        return (EXIT_SUCCESS);
    }
    dir = getcwd(buf, PATH_MAX);
    if (dir)
    {
        ft_putendl_fd(dir, 1);
		return (EXIT_SUCCESS);
	}
    // Aquí nos faltaría mostrar un mensaje de error por si lo otro falla...
    return (EXIT_FAILURE);
}

// TODO
// env PWD
// Buscar y devolver el valor en la lista env
