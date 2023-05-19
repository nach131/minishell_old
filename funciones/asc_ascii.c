#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	compareASCII(const void *a, const void *b)
{
	const char	*strA;
	const char	*strB;

	strA = *((const char **)a);
	strB = *((const char **)b);
	return (strcmp(strA, strB));
}

void	printListAscending(t_list *list)
{
	int			count;
	t_list		*current;
	const char	**tempArray;
	int			i;

	// Contar el número de elementos en la lista
	count = 0;
	current = list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	// Crear un array temporal para almacenar los punteros a los elementos
	tempArray = malloc(count * sizeof(char *));
	if (tempArray == NULL)
	{
		fprintf(stderr, "Error: Fallo en la asignación de memoria.\n");
		return ;
	}
	// Guardar los punteros a los elementos en el array temporal
	current = list;
	i = 0;
	while (current != NULL)
	{
		tempArray[i] = current->content;
		current = current->next;
		i++;
	}
	// Ordenar el array temporal
	qsort(tempArray, count, sizeof(char *), compareASCII);
	// Imprimir los elementos ordenados
	for (int j = 0; j < count; j++)
	{
		printf("%s\n", tempArray[j]);
	}
	// Liberar la memoria del array temporal
	free(tempArray);
}

int	main(void)
{
	t_list	*list;

	// Crear una lista de ejemplo
	list = malloc(sizeof(t_list));
	list->content = "Hola";
	list->next = malloc(sizeof(t_list));
	list->next->content = "aundo";
	list->next->next = malloc(sizeof(t_list));
	list->next->next->content = "OpenAI";
	list->next->next->next = NULL;
	// Imprimir la lista en orden ascendente según la tabla ASCII
	printListAscending(list);
	// Liberar la memoria de la lista
	free(list->next->next);
	free(list->next);
	free(list);
	return (0);
}
