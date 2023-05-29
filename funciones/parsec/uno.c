#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10

void	parse_command(char *line, char **args)
{
	char	*token;
	int		i;

	i = 0;
	token = strtok(line, " \t\n\r");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n\r");
	}
	args[i] = NULL; // Terminating the argument list with a NULL pointer
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
