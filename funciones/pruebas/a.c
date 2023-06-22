#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return (new_node);
}

void ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list *temp;

	if (*lst == NULL)
	{
		*lst = new_node;
		return;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

char *ft_strdup(const char *s)
{
	size_t len;
	char *dup;

	len = strlen(s) + 1;
	dup = malloc(len);
	if (dup)
		memcpy(dup, s, len);
	return (dup);
}

void separar_nodos_limitadores(t_list **a)
{
	t_list *current = *a;
	t_list *new_list = NULL;

	while (current != NULL)
	{
		char *str = (char *)current->content;
		char *delimiters = "<>|";
		char *word = strtok(str, delimiters);
		t_list *prev_node = NULL;

		while (word != NULL)
		{
			t_list *new_node = ft_lstnew(ft_strdup(word));
			ft_lstadd_back(&new_list, new_node);

			if (prev_node != NULL)
			{
				t_list *delimiter_node = ft_lstnew(ft_strdup(current->content));
				ft_lstadd_back(&new_list, delimiter_node);
			}

			prev_node = new_node;
			word = strtok(NULL, delimiters);
		}

		current = current->next;
	}

	// Liberar la lista original
	t_list *temp = *a;
	while (temp != NULL)
	{
		t_list *next = temp->next;
		free(temp->content);
		free(temp);
		temp = next;
	}

	*a = new_list;
}

void ft_lstprint(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int main(void)
{
	t_list *a = NULL;

	// Crear la lista original
	a = ft_lstnew(ft_strdup("cat"));
	ft_lstadd_back(&a, ft_lstnew(ft_strdup("Make|grep")));
	ft_lstadd_back(&a, ft_lstnew(ft_strdup("a")));

	// Separar los nodos
	separar_nodos_limitadores(&a);

	// Imprimir los nodos separados
	ft_lstprint(a);

	// Liberar memoria
	t_list *temp = a;
	while (temp != NULL)
	{
		t_list *next = temp->next;
		free(temp->content);
		free(temp);
		temp = next;
	}

	return 0;
}
