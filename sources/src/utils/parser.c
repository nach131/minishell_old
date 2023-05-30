/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:54:00 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/30 23:59:10 by nmota-bu         ###   ########.fr       */
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

// void	parser_space(int flag[], char *line, t_cmd **cmd)
// {
// 	char	*token;

// 	(void)flag;
// 	token = ft_strtok(line, " ");
// 	while (token != NULL)
// 	{
// 		// Imprimir el token actual
// 		//AQUI ES DONDE PASAMOS LOS RECORTES A NUESTRA ESTRUCTURA
// 		cmd_add_back(cmd, cmd_new(token));
// 		// printf("%s\n", token);
// 		// Obtener el siguiente token
// 		token = ft_strtok(NULL, " ");
// 	}
// }

void	parser_space(int flag[], char *line, t_cmd **cmd)
{
	int		quotes;
	char	*start;

	(void)flag;
	quotes = 0;
	start = line;
	while (*line != '\0')
	{
		if (*line == DOUBLE_QUOTE)
			quotes = !quotes;
		else if (*line == WHITE_SPACE && !quotes)
		// else if (*line == ' ' && !quotes)
		{
			*line = '\0';
			cmd_add_back(cmd, cmd_new(start));
			start = line + 1;
		}
		line++;
	}
	cmd_add_back(cmd, cmd_new(start));
}

// CUANDO SEA IMPAR " o ' SE abre la consola de lineas,
// esto hay que comprobarlo en el segundo paso de parser_space

// en la stacic de next_token
