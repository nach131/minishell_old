/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:54:00 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/26 14:59:30 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"

// quita las "" de contenido de la lista
// Pasar esta funcion desde ft_lstiter
// Tinene que ser void *content por el protype de ft_lstiter

void	remove_quotes(void *content)
{
	char	*str;
	int		len;

	str = (char *)content;
	len = strlen(str);
	if (len >= 2 && ((str[0] == '"' && str[len - 1] == '"') || (str[0] == '\''
				&& str[len - 1] == '\'')))
	{
		ft_memmove(str, str + 1, len - 1);
		str[len - 2] = '\0';
	}
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
		if (*line == DOUBLE_QUOTE || *line == QOUTE)
			// if (*line == DOUBLE_QUOTE)
			quotes = !quotes;
		else if (*line == WHITE_SPACE && !quotes)
		{
			if (line != start) // Evitar añadir espacios en blanco consecutivos
			{
				*line = '\0';
				ft_lstadd_back(&token, ft_lstnew(start));
			}
			start = line + 1;
		}
		line++;
	}
	if (line != start)
		// Añadir el último token si no hay espacio en blanco al final
		ft_lstadd_back(&token, ft_lstnew(start));
	return (token);
}
