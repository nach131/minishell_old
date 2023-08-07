/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_btin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:02 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/07 10:54:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// TODO
// desarrollar aqui los $ENV y buscar env_dptr y devolver solo el valor
// cat archivo.txt | echo $(wc -l) // bruno si
// echo "Suma de los números:"
// echo "1 2 3 4 5" | tr " " "+" | bc
// NADIE LO HACE
// echo {1..10}

void echo_btin(t_list *env_lst, char **args)
{
	(void)env_lst;

	if (args[1] == NULL)
		printf("\n");
	else
	{
		printf("echo_btin\n");
	}
}
