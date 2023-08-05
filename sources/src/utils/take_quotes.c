/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:29:29 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/05 11:33:46 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"

// Quita las " y ' del string pasado, para cuando export

void	take_quote(char *s)
{
	char	*i;
	char	*j;

	i = s;
	j = s;
	while (*j)
	{
		if (*j != '"' && *j != '\'')
		{
			*i = *j;
			i++;
		}
		j++;
	}
	*i = '\0';
}

// Comprueba si tiene igual

int	this_iqual(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (0);
}
