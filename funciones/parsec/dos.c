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
	int		in_quotes;

	in_quotes = 0;
	// Variable para rastrear si estamos dentro de comillas dobles
	i = 0;
	token = strtok(line, " \t\n\r");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		if (token[0] == '\"') // Comienzo de comillas dobles
		{
			in_quotes = 1;
			args[i] = token + 1; // Omitir el primer carácter (comillas dobles)
		}
		else if (token[strlen(token) - 1] == '\"') // Fin de comillas dobles
		{
			in_quotes = 0;
			token[strlen(token) - 1] = '\0';
			// Reemplazar el último carácter (comillas dobles) con NULL
			args[i] = token;
			i++;
			break ; // Salir del bucle, ya que el argumento ha terminado
		}
		else if (in_quotes) // Dentro de comillas dobles
		{
			args[i] = token; // Mantener el token completo
		}
		else // Fuera de comillas dobles
		{
			args[i] = token;
			i++;
		}
		token = strtok(NULL, " \t\n\r");
	}
	args[i] = NULL; // Terminar la lista de argumentos con un puntero NULL
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
