/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_btin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:50:12 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/04 14:54:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// TODO

// // unset uno dos tres
// Tiene que borra los tres env

#include "builtins.h"

void unset_btin(t_list *env_lst, char **args)
{
	int i;
	if (!args[1])
		return;
	else
	{
		i = 1;
		while (args[i] != NULL)
		{
			printf("%s\n", args[i]);
			ft_lstadd_back(&env_lst, ft_lstnew(args[i]));

			i++;
		}

		// ft_lstprint(env_lst);
	}
}
