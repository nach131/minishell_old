/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_separ_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:53:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/22 20:38:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/lib/libft/inc/libft.h"

char *buscar_delimitador(char *str, char *delimiters, int *flag)
{
	char *tmp;

	while (*str != '\0')
	{
		if (ft_strchr(delimiters, *str) != NULL)
		{
			tmp = ft_substr(str, 0, 1);
			*flag = 1;
			return (tmp);
		}
		str++;
	}
	return (NULL);
}

void liberar_lista_original(t_list **a, t_list *new_list)
{
	t_list *temp;
	t_list *next;

	temp = *a;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->content);
		free(temp);
		temp = next;
	}
	*a = new_list;
}

void separar_nodos_limitadores(t_list **a)
{
	t_list *current;
	t_list *new_list;
	char *str;
	char *delimiters;
	char *word;
	t_list *delimiter_node;
	t_list *temp;
	t_list *next;
	char *del_word;
	int flag;

	flag = 1;
	current = *a;
	new_list = NULL;
	delimiters = "<>|";
	while (current != NULL)
	{
		str = (char *)current->content;
		del_word = buscar_delimitador(current->content, delimiters, &flag);
		word = ft_strtok(str, delimiters);
		while (word != NULL)
		{
			ft_lstadd_back(&new_list, ft_lstnew(word));
			if (del_word && flag)
			{
				ft_lstadd_back(&new_list, ft_lstnew(del_word));
				flag = 0;
			}
			word = ft_strtok(NULL, delimiters);
			if (word != NULL)
			{
				delimiter_node = ft_lstnew(word);
				ft_lstadd_back(&new_list, delimiter_node);
			}
			word = ft_strtok(NULL, delimiters);
		}
		current = current->next;
	}
	liberar_lista_original(a, new_list);
}

int main(void)
{
	t_list *a;

	a = malloc(1 * sizeof(t_list));
	a->content = ft_strdup("cat");
	a->next = malloc(1 * sizeof(t_list));
	a->next->content = ft_strdup("Make|grep");
	// a->next->content = ft_strdup("\"Make|grep\"");
	a->next->next = malloc(1 * sizeof(t_list));
	a->next->next->content = ft_strdup("clean>toma.txt");
	// a->next->next->content = ft_strdup("a");
	a->next->next->next = NULL;
	ft_lstprint(a);
	printf("------\n");
	separar_nodos_limitadores(&a);
	ft_lstprint(a);
	ft_lstfree(a);
}

// cat Make|grep clean>toma.txt
