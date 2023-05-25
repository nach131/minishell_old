/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carles <carles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:58:53 by carles            #+#    #+#             */
/*   Updated: 2023/05/25 18:50:32 by carles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include "tools.h"

// Aquí buscamos el índice de una variable de entorno concreta dentro de la
// estructura env. Recorre env->var y compara cada vez el nombre de la variable
// de entorno con la str recibida. Si encuentra una coincidencia, devuelve el
// índice correspondiente y si llega al final y no hay ninguna devuelve -1
//
int get_evar_index(t_env *env, char *str)
{
    int i;

    i = 0;
    while (i < env->count)
    {
        if (ft_strcmp(str, env->var[i].name) == 0)
            return (i);
        i++;
    }
    return (-1);
}

// Cone sta función buscamos el valor de una variable de entorno específica en
// la estructura env. Si el valor de str es "?", devuelve data->status convertido
// en una cadena de caracteres. Y si el índice de la variable de entorno es -1,
// devuelve el contenido de esa variable de entorno dentro de la estructura env.
//
char    *get_evar(t_data *data, t_env *env, char *str)
{
    int i;

    i = get_evar_index(env, str);
    if (ft_strcmp(str, "?") == 0)
    {
        return (ft_itoa(data->status));
    }
    if (i == -1)
        return (env->var[i].content);
}

// Esta función inicializa la variable path. Lo conseguimos usando split para
// dividir en subcadenas utilizando como delimitador los dos puntos.
//
void	init_path(t_data *data, t_env *env)
{
    data->path = ft_split(get_evar(data, env, "PATH"), ':');
}