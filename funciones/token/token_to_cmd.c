#include "../../sources/lib/libft/inc/libft.h"

enum	token
{
	NEW_LINE = '\n',
	WHITE_SPACE = ' ',
	DOUBLE_QUOTE = '\"',
	ENV = '$',
	QOUTE = '\'',
	_NULL = '0',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	ESCAPE = '\\',
	PIPE = '|',
};

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

int	main(void)
{
	t_list	*token;

	// token = parser_space_lst("cat Makefile | grep  \"clean\"");
	token = parser_space_lst("cat Makefile");
	if (token)
		ft_lstprint(token);
	return (0);
}
