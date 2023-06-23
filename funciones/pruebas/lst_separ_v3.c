/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_separ_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:53:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/23 11:40:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/lib/libft/inc/libft.h"

char	*buscar_delimitador(char *str, char *delimiters, int *flag)
{
	char	*tmp;

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

void	liberar_lista_original(t_list **a, t_list *new_list)
{
	t_list	*temp;
	t_list	*next;

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

typedef struct s_data
{
	t_list	*current;
	t_list	*new_list;
	char	*str;
	char	*delimiters;
	char	*word;
	t_list	*delimiter_node;
	t_list	*temp;
	t_list	*next;
	char	*del_word;
	int		flag;
}			t_data;

void	procesar_lista(t_data *data)
{
	while (data->current != NULL)
	{
		data->str = (char *)data->current->content;
		data->del_word = buscar_delimitador(data->str, data->delimiters,
				&(data->flag));
		data->word = ft_strtok(data->str, data->delimiters);
		while (data->word != NULL)
		{
			ft_lstadd_back(&(data->new_list), ft_lstnew(data->word));
			if (data->del_word && data->flag)
			{
				ft_lstadd_back(&(data->new_list), ft_lstnew(data->del_word));
				data->flag = 0;
			}
			data->word = ft_strtok(NULL, data->delimiters);
			if (data->word != NULL)
			{
				data->delimiter_node = ft_lstnew(data->word);
				ft_lstadd_back(&(data->new_list), data->delimiter_node);
			}
			data->word = ft_strtok(NULL, data->delimiters);
		}
		data->current = data->current->next;
	}
}

void	separar_nodos_limitadores(t_list **a)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->flag = 1;
	data->current = *a;
	data->new_list = NULL;
	data->delimiters = "<>|";
	procesar_lista(data);
	liberar_lista_original(a, data->new_list);
	// free(data); //HACER EL FREE DE TODO EL CONTENIDO
}

int	main(void)
{
	t_list	*a;

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
