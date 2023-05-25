/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_btin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:08:46 by carles            #+#    #+#             */
/*   Updated: 2023/05/25 13:42:26 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

// Esto simplemente para verificar que el argumento es un número válido
//
int	ft_isnumber(const char *str)
{
	if (*str == '-')
		str++;
	else if (*str == '+')
		str++;
	if (ft_isdigit(*str))
		return (TRUE);
	return (FALSE);
}

// Lo primero que hacemos es indicar que hay que salir del programa. Luego
// imprimimos exit en la salida de error y utilizamos un operador ternario
// para verificar si args[1] está presente o no... Si lo está, buena cara y
// si no lo está, cara de asco. Luego hacemos unas comprobaciones por si
// se han dado demasiados argumentos o si args[1] es o no un número válido.
// Si es válido usamos atoi e imprimimos lo que toca.
//
int	exit_btin(t_data *data, char **args)
{
	data->exit = 1;
	ft_putstr_fd("exit ", 2);
	args[1] ? ft_putendl_fd("😀", 2) : ft_putendl_fd("🤢", 2);
	if (args[1] && args[2])
	{
		data->ret = 1;
		ft_putendl_fd("exit: too many argument", 2);
	}
	else if (args[1] && ft_isnumber(args[1]))
	{
		data->ret = 255;
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": argument is not numeric", 2);
	}
	else if (args[1])
		data->ret = ft_atoi(args[1]);
	else
		data->ret = 0;
	return (1); // TIENE QUE DEVOLVER INT
}
