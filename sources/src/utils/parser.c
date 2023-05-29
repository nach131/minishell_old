/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:54:00 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/29 17:14:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// CONTROL DE LOS FLAG PARA EL PARSER
void	ctrl_line(int flag[], char *line)
{
	int	i;
	int	double_quote;

	double_quote = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == DOUBLE_QUOTE)
			double_quote++;
		i++;
	}
	if (double_quote == 2)
		flag[DOUBLE_QUOTE] = 1;
}

void	parser_space(int flag[], char *line)
{
	char	*token;

	(void)flag;
	token = ft_strtok(line, " ");
	while (token != NULL)
	{
		// Imprimir el token actual
		//AQUI ES DONDE PASAMOS LOS RECORTES A NUESTRA ESTRUCTURA
		printf("%s\n", token);
		// Obtener el siguiente token
		token = ft_strtok(NULL, " ");
	}
}

// CUANDO SEA IMPAR " o ' SE abre la consola de lineas,
// esto hay que comprobarlo en el segundo paso de parser_space

// en la stacic de next_token
