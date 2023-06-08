/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:54:00 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/08 23:00:17 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// CONTROL DE LOS FLAG PARA EL PARSER
// esta sin usar
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

t_list	*parser_space_lst(char *line)
{
	int		quotes;
	char	*start;
	t_list	*token;

	quotes = 0;
	start = line;
	token = NULL;
	while (*line != '\0')
	{
		if (*line == DOUBLE_QUOTE)
			quotes = !quotes;
		else if (*line == WHITE_SPACE && !quotes)
		{
			if (line != start) // Evitar añadir espacios en blanco consecutivos
			{
				*line = '\0';
				ft_lstadd_back(&token, ft_lstnew(ft_strdup(start)));
			}
			start = line + 1;
		}
		line++;
	}
	if (line != start)
		// Añadir el último token si no hay espacio en blanco al final
		ft_lstadd_back(&token, ft_lstnew(ft_strdup(start)));
	return (token);
}

// YA NO
// CUANDO SEA IMPAR " o ' SE abre la consola de lineas,
// esto hay que comprobarlo en el segundo paso de parser_space
// en la stacic de next_token
