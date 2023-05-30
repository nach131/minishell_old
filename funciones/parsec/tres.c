#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10

void	parse_command(char *line, char **args)
{
	int		i;
	int		in_quotes;
	char	*start;

	i = 0;
	in_quotes = 0;
	start = line;
	while (*line != '\0' && i < MAX_ARGS - 1)
	{
		if (*line == '\"')
		{
			in_quotes = !in_quotes;
		}
		else if (*line == ' ' && !in_quotes)
		{
			*line = '\0';
			args[i++] = start;
			start = line + 1;
		}
		line++;
	}
	args[i++] = start;
	args[i] = NULL;
}

int	main(void)
{
	char	*line;
	char	*args[MAX_ARGS];

	while (1)
	{
		line = readline("Minishell> ");
		if (line == NULL)
		{
			printf("\n");
			break ;
		}
		add_history(line);
		parse_command(line, args);
		// Imprimir los argumentos obtenidos del parsing (solo para demostración)
		for (int i = 0; args[i] != NULL; i++)
		{
			printf("Argument %d: %s\n", i, args[i]);
		}
		free(line);
	}
	return (0);
}

// ESTE SIIII
