#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char *content;
	struct s_list *next;
} t_list;

char *find_node_value(t_list *head, const char *target_value)
{
	t_list *current = head;

	// Recorre la lista hasta encontrar el nodo con el valor deseado
	while (current != NULL)
	{
		if (strcmp(current->content, target_value) == 0)
			return current->content;
		current = current->next;
	}

	// Si no se encuentra el valor en ningún nodo, retorna NULL
	return NULL;
}

// Función para agregar un nuevo nodo al final de la lista (solo para propósitos de prueba)
void append(t_list **head, const char *content)
{
	t_list *new_node = malloc(sizeof(t_list));
	new_node->content = strdup(content);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		t_list *current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

// Función para imprimir los valores de la lista (solo para propósitos de prueba)
void print_list(t_list *head)
{
	t_list *current = head;
	while (current != NULL)
	{
		printf("%s ", current->content);
		current = current->next;
	}
	printf("\n");
}

int main(void)
{
	t_list *head = NULL;

	// Agrega algunos nodos a la lista (solo para propósitos de prueba)
	append(&head, "apple");
	append(&head, "banana");
	append(&head, "orange");

	printf("Lista actual: ");
	print_list(head);

	const char *target_value = "banana";
	char *found_value = find_node_value(head, target_value);

	if (found_value != NULL)
		printf("Se encontró el valor '%s' en un nodo de la lista.\n", found_value);
	else
		printf("El valor '%s' no se encontró en ningún nodo de la lista.\n", target_value);

	// Clean up allocated memory
	t_list *current = head;
	while (current != NULL)
	{
		t_list *next = current->next;
		free(current->content);
		free(current);
		current = next;
	}

	return 0;
}
