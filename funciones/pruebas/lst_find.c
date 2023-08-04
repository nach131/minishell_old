#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
	char *content;
	struct s_list *next;
} t_list;

void ft_lstprint(t_list *list)
{
	t_list *current = list;
	while (current != NULL)
	{
		printf("%s \n", current->content);
		current = current->next;
	}
	// printf("\n");
}

int find_env(char *s1, char *s2)
{
	if (!strncmp(s1, s2, 5)) // contar hasta el =
		return (1);
	else
		return (0);
}

t_list *ft_lstfind(t_list *lst, void *data_ref, int (*cmp)(char *, char *))
{
	t_list *curr;

	curr = lst;
	while (curr)
	{
		if ((*cmp)(curr->content, data_ref) == 1)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

int main(void)
{
	t_list *list = malloc(1 * sizeof(t_list));
	list->next = malloc(1 * sizeof(t_list));
	list->next->next = malloc(1 * sizeof(t_list));
	list->next->next->next = malloc(1 * sizeof(t_list));
	list->content = strdup("USER=nacho");
	list->next->content = strdup("LANG=es_ES.UTF-8");
	list->next->next->content = strdup("HOME=/Users/nacho");
	list->next->next->next->content = strdup("uno=\"\"");
	list->next->next->next->next = NULL;

	ft_lstprint(list);

	t_list *a;
	a = ft_lstfind(list, "USER=\"\"", find_env);

	if (a)
		printf("%s\n", a->content);
	else
		printf("__nada__\n");

	return (0);
}
