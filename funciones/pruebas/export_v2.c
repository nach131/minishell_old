// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(void)
// {
// 	char **env = malloc(4 * sizeof(char *));

// 	env[0] = strdup("NVM_RC_VERSION=");
// 	env[1] = strdup("TERM_PROGRAM=iTerm.app");
// 	env[2] = strdup("Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.QvsX3bwQhs/Render");
// 	env[3] = NULL;

// 	int i = 0;
// 	while (env[i] != NULL)
// 	{
// 		printf("%s\n", env[i]);
// 		i++;
// 	}

// 	return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *insertQuotesIfNeeded(const char *input)
{
	// Buscar el índice del signo igual (=)
	const char *equals_sign = strchr(input, '=');

	if (equals_sign == NULL)
	{
		// Si no hay igual, solo devolver la clave con el igual y dos comillas dobles
		char *result = (char *)malloc(strlen(input) + 4); // longitud de la clave + igual + 2 comillas dobles + caracter nulo '\0'
		sprintf(result, "%s\"\"", input);
		return result;
	}

	// Calcular el tamaño del valor después del igual
	size_t value_length = strlen(equals_sign + 1);

	// Crear el resultado con el tamaño adecuado (clave + igual + valor + 2 comillas dobles + caracter nulo)
	char *result = (char *)malloc(equals_sign - input + value_length + 5);
	sprintf(result, "%.*s\"%s\"", (int)(equals_sign - input), input, equals_sign + 1);
	return result;
}

int main(void)
{
	char **env = malloc(4 * sizeof(char *));

	env[0] = strdup("NVM_RC_VERSION=");
	env[1] = strdup("TERM_PROGRAM=iTerm.app");
	env[2] = strdup("Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.QvsX3bwQhs/Render");
	env[3] = NULL;

	int i = 0;
	while (env[i] != NULL)
	{
		char *value = insertQuotesIfNeeded(env[i]);
		printf("%s\n", value);
		free(value); // Liberar la memoria asignada por la función
		i++;
	}

	// Liberar la memoria asignada para cada cadena en el arreglo
	for (int j = 0; j < i; j++)
	{
		free(env[j]);
	}

	// Liberar la memoria del arreglo en sí
	free(env);

	return 0;
}
