/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:02 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/05 23:32:30 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_printf.h"

// TODO
// desarrollar aqui los $ENV y buscar env_dptr y devolver solo el valor
// cat archivo.txt | echo $(wc -l) // bruno si
// echo "Suma de los números:"
// echo "1 2 3 4 5" | tr " " "+" | bc
// NADIE LO HACE
// echo {1..10}

void	toma(void)
{
	ft_printf("toma\n");
}
