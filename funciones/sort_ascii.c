/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:29:36 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/26 13:35:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../sources/lib/libft/inc/libft.h"
#include <stdio.h>
#include <string.h>

// int main()
// {
// 	char palabras[][20] = {"Apple_PubSub", "USER", "SHELL", "CLICOLOR"};
// 	int i = 0;
// 	int j;

// 	int num_palabras = sizeof(palabras) / sizeof(palabras[0]);

// 	while (i < num_palabras - 1)
// 	{
// 		j = i + 1;
// 		while (j < num_palabras)
// 		{
// 			if (ft_strcmp(palabras[i], palabras[j]) > 0)
// 			{
// 				char temp[20];
// 				ft_strcpy(temp, palabras[i]);
// 				ft_strcpy(palabras[i], palabras[j]);
// 				ft_strcpy(palabras[j], temp);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}

// 	printf("Palabras ordenadas:\n");
// 	i = -1;
// 	while (++i < num_palabras)
// 		printf("%s\n", palabras[i]);

// 	return (0);
// }

// int	main(void)
// {
// 	t_list	*palabras;
// 	t_list	*current;
// 	int		num_palabras;
// 	int		i;
// 	int		j;
// 	t_list	*next;
// 	char	*word1;
// 	char	*word2;
// 	t_list	*temp;

// 	palabras = NULL;
// 	palabras = malloc(sizeof(t_list));
// 	palabras->content = "__CF_USER_TEXT_ENCODING";
// 	palabras->next = malloc(sizeof(t_list));
// 	palabras->next->content = "COLORFGBG";
// 	palabras->next->next = malloc(sizeof(t_list));
// 	palabras->next->next->content = "CLICOLOR";
// 	palabras->next->next->next = malloc(sizeof(t_list));
// 	palabras->next->next->next->content = "Apple_PubSub";
// 	palabras->next->next->next->next = NULL;
// 	current = palabras;
// 	num_palabras = 0;
// 	// Contar el número de palabras en la lista
// 	while (current != NULL)
// 	{
// 		num_palabras++;
// 		current = current->next;
// 	}
// 	i = 0;
// 	while (i < num_palabras - 1)
// 	{
// 		j = i + 1;
// 		current = palabras;
// 		// Mover current al elemento i actual
// 		for (int k = 0; k < i; k++)
// 			current = current->next;
// 		while (j < num_palabras)
// 		{
// 			next = current->next;
// 			word1 = (char *)current->content;
// 			word2 = (char *)next->content;
// 			if (ft_strcmp(word1, word2) > 0)
// 			{
// 				temp = current->content;
// 				current->content = next->content;
// 				next->content = temp;
// 			}
// 			current = current->next;
// 			j++;
// 		}
// 		i++;
// 	}
// 	printf("Palabras ordenadas:\n");
// 	current = palabras;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	// Liberar la memoria de la lista
// 	current = palabras;
// 	while (current != NULL)
// 	{
// 		temp = current;
// 		current = current->next;
// 		free(temp);
// 	}
// 	return (0);
// }

// int	ft_strcmp_bis(const char *s1, const char *s2)
// {
// 	while (*s1 && (*s1 == *s2))
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*(unsigned char *)s1 - *(unsigned char *)s2);
// }

int	main(void)
{
	t_list	*palabras;
	t_list	*current;
	int		num_palabras;
	int		i;
	int		j;
	t_list	*next;
	char	*word1;
	char	*word2;
	t_list	*temp;

	palabras = NULL;
	palabras = malloc(sizeof(t_list));
	palabras->content = "__CF_USER_TEXT_ENCODING";
	palabras->next = malloc(sizeof(t_list));
	palabras->next->content = "COLORFGBG";
	palabras->next->next = malloc(sizeof(t_list));
	palabras->next->next->content = "CLICOLOR";
	palabras->next->next->next = malloc(sizeof(t_list));
	palabras->next->next->next->content = "Apple_PubSub";
	palabras->next->next->next->next = NULL;
	current = palabras;
	num_palabras = 0;
	// Contar el número de palabras en la lista
	while (current != NULL)
	{
		num_palabras++;
		current = current->next;
	}
	i = 0;
	while (i < num_palabras - 1)
	{
		j = i + 1;
		current = palabras;
		// Mover current al elemento i actual
		for (int k = 0; k < i; k++)
			current = current->next;
		while (j < num_palabras)
		{
			next = current->next;
			word1 = (char *)current->content;
			word2 = (char *)next->content;
			if (ft_strcmp(word1, word2) < 0)
			// Modificación en la comparación
			{
				temp = current->content;
				current->content = next->content;
				next->content = temp;
			}
			current = current->next;
			j++;
		}
		i++;
	}
	printf("Palabras ordenadas:\n");
	current = palabras;
	ft_lstreverse(current);
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	// Liberar la memoria de la lista
	current = palabras;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	return (0);
}
