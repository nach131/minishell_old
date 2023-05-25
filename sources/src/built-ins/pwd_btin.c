/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_btin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carles <carles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:58:55 by carles            #+#    #+#             */
/*   Updated: 2023/05/25 19:46:14 by carles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// Esto ejecuta el buildin pwd y nos muestra el directorio actual (act_dir) con
// su path mediante la función de sistema getcwd. 
//
// int pwd_btin(t_data *data, char **args)
// {
//     char    buf[PATH_MAX];
//     char    *dir;

//     (void)args;
//     if (data->act_dir)
//     {
//         ft_putendl_fd(data->act_dir, 1);
//         return (EXIT_SUCCESS);
//     }
//     dir = getcwd(buf, PATH_MAX);
//     if (dir)
//     {
//         ft_putendl_fd(dir, 1);
//         return (EXIT_SUCCESS);      
//     }
//     // Aquí nos faltaría mostrar un mensaje de error por si lo otro falla...
//     return (EXIT_FAILURE);
// }
void    pwd_btin(t_data *data)
{
    char    *buffer;

    buffer = getcwd(0, 0);
    if (!buffer)
    {
        perror("pwd");
        return ;
    }
    ft_printf(1, "%s\n", buffer);
    free (buffer);
}