/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:44:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/23 11:47:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "control.h"

char static	*find_token(char *str, char *delimiters, int *flag)
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

// void token_split(t_list **a)
// {
// 	t_list *current;
// 	t_list *new_list;
// 	char *str;
// 	char *delimiters;
// 	char *word;
// 	t_list *delimiter_node;
// 	t_list *temp;
// 	t_list *next;
// 	char *del_word;
// 	int flag = 1;

// 	current = *a;
// 	new_list = NULL;
// 	delimiters = "<>|";
// 	while (current != NULL)
// 	{
// 		str = (char *)current->content;
// 		del_word = find_token(current->content, delimiters, &flag);
// 		word = ft_strtok(str, delimiters);
// 		while (word != NULL)
// 		{
// 			if (word != NULL && *word != '\0')
// 				ft_lstadd_back(&new_list, ft_lstnew(word));
// 			if (del_word && flag)
// 			{
// 				ft_lstadd_back(&new_list, ft_lstnew(del_word));
// 				flag = 0;
// 			}
// 			word = ft_strtok(NULL, delimiters);
// 			if (word != NULL && *word != '\0')
// 			{
// 				delimiter_node = ft_lstnew(word);
// 				ft_lstadd_back(&new_list, delimiter_node);
// 			}
// 			word = ft_strtok(NULL, delimiters);
// 		}
// 		current = current->next;
// 	}
// 	// Liberar la lista original
// 	temp = *a;
// 	while (temp != NULL)
// 	{
// 		next = temp->next;
// 		free(temp->content);
// 		free(temp);
// 		temp = next;
// 	}
// 	*a = new_list;
// }

void static	free_origin_lst(t_list **a, t_list *new_list)
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

void static	process_list(t_dtoken *data)
{
	while (data->current != NULL)
	{
		data->str = (char *)data->current->content;
		data->del_word = find_token(data->current->content, data->delimiters,
				&data->flag);
		data->word = ft_strtok(data->str, data->delimiters);
		while (data->word != NULL)
		{
			if (data->word != NULL && *data->word != '\0')
				ft_lstadd_back(&data->new_list, ft_lstnew(data->word));
			if (data->del_word && data->flag)
			{
				ft_lstadd_back(&data->new_list, ft_lstnew(data->del_word));
				data->flag = 0;
			}
			data->word = ft_strtok(NULL, data->delimiters);
			if (data->word != NULL && *data->word != '\0')
			{
				data->delimiter_node = ft_lstnew(data->word);
				ft_lstadd_back(&data->new_list, data->delimiter_node);
			}
			data->word = ft_strtok(NULL, data->delimiters);
		}
		data->current = data->current->next;
	}
}

void	token_split(t_list **a)
{
	t_dtoken	*data;

	data = malloc(sizeof(t_dtoken));
	data->flag = 1;
	data->current = *a;
	data->new_list = NULL;
	data->delimiters = "<>|";
	process_list(data);
	free_origin_lst(a, data->new_list);
	// free(data);
}
