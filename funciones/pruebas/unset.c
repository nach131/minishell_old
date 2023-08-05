#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
	char *content;
	struct s_list *next;
} t_list;

void ft_lstprint(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void ft_lstremove(t_list **head, const char *str)
{
	t_list *current = *head;
	t_list *prev = NULL;

	while (current != NULL)
	{
		if (strcmp(current->content, str) == 0)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				*head = current->next;

			free(current->content);
			free(current);
			current = NULL; // Set to NULL to exit the loop after deletion
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

int main(void)
{
	t_list *lst = malloc(1 * sizeof(t_list));
	lst->next = malloc(1 * sizeof(t_list));
	lst->next->next = malloc(1 * sizeof(t_list));
	lst->next->next->next = malloc(1 * sizeof(t_list));
	lst->next->next->next->next = malloc(1 * sizeof(t_list));
	lst->next->next->next->next->next = malloc(1 * sizeof(t_list));
	lst->next->next->next->next->next->next = NULL;
	lst->content = strdup("USER=nacho");
	lst->next->content = strdup("LANG=es_ES.UTF-8");
	lst->next->next->content = strdup("HOME=/Users/nacho");
	lst->next->next->next->content = strdup("USER=nacho");
	lst->next->next->next->next->content = strdup("SHELL=/bin/bash");
	lst->next->next->next->next->next->content = strdup("CLICOLOR=1");

	printf("Original list:\n");
	ft_lstprint(lst);

	const char *str_to_remove = "USER=nacho";
	ft_lstremove(&lst, str_to_remove);

	printf("\nList after removing '%s':\n", str_to_remove);
	ft_lstprint(lst);
}
