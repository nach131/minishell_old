/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_btin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/04 00:10:37 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "libft.h"
#include "minishell.h"

// ANTIC
// void	start_export(t_list *palabras)
// {
// 	t_list	*current;
// 	int		num_palabras;
// 	int		i;
// 	int		j;
// 	t_list	*next;
// 	char	*word1;
// 	char	*word2;
// 	t_list	*temp;

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
// 			// word1 = ft_strtok(current->content, "=");
// 			// word2 = ft_strtok(next->content, "=");
// 			word1 = (char *)current->content;
// 			word2 = (char *)next->content;
// 			if (ft_strcmp(word1, word2) < 0)
// 			// Modificación en la comparación
// 			{
// 				temp = current;
// 				current->content = next->content;
// 				next = temp;
// 			}
// 			current = current->next;
// 			j++;
// 		}
// 		i++;
// 	}
// 	current = palabras;
// 	ft_lstreverse(current);
// 	while (current != NULL)
// 	{
// 		printf("declare -x %s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	// // Liberar la memoria de la lista
// 	// current = palabras;
// 	// while (current != NULL)
// 	// {
// 	// 	temp = current;
// 	// 	current = current->next;
// 	// 	free(temp);
// 	// }
// }

// int ft_strcmp(const char *str1, const char *str2)
// {
// 	while (*str1 != '\0' && *str1 == *str2)
// 	{
// 		str1++;
// 		str2++;
// 	}

// 	return (int)(*str1) - (int)(*str2);
// }

int compare_env_strings(const void *a, const void *b)
{
	const char *str_a;
	const char *str_b;
	// const char *equals_a;
	// const char *equals_b;

	// The environment strings are in the format "VARIABLE=value"
	// We need to compare only the VARIABLE part, so find the '=' character.
	str_a = *(const char **)a;
	str_b = *(const char **)b;
	// equals_a = strchr(str_a, '=');
	// equals_b = strchr(str_b, '=');
	// (void)equals_a;
	// (void)equals_b;
	return (strcmp(str_a, str_b));
	// return (ft_strcmp((char *)a, (char *)b));
}

void custom_qsort(void *base, size_t num_elements, size_t element_size,
				  int (*compare)(const void *, const void *))
{
	char *arr;
	size_t i;
	char *temp;
	size_t j;
	char *element_a;
	char *element_b;

	arr = (char *)base;
	i = 0;
	temp = (char *)malloc(element_size);
	while (i < num_elements - 1)
	{
		j = i + 1;
		while (j < num_elements)
		{
			element_a = arr + i * element_size;
			element_b = arr + j * element_size;
			if (compare(element_a, element_b) > 0)
			{
				memcpy(temp, element_a, element_size);
				memcpy(element_a, element_b, element_size);
				memcpy(element_b, temp, element_size);
			}
			j++;
		}
		i++;
	}
	free(temp);
}

void print_dptr(char **arr)
{
	int i;

	i = 1;
	if (arr == NULL)
		return;
	while (arr[++i] != NULL)
		printf("declare -x %s\n", arr[i]);
}

// VALE ....
// PRIMERO EL NOMBRE DE LA VARIABLE, DEPUES LA VARIABLE DENTRO DE ""
// asi que organizar solo los nombres despues buscar cada variable e imprimir el valor

void	add_export(t_list *env, t_cmd *cmd)
{
	(void)cmd;
	ft_lstadd_back(&env, ft_lstnew("TOMATE=nuevo tomate"));
}

void export_btin(t_list *env_lst, char **args, char **env)
{
	if (args[1] == NULL)
	{
		custom_qsort(env, ft_len_dptr(env) - 1, sizeof(char *),
					 compare_env_strings);
		print_dptr(env);
	}
	else
		// si existe el export cambia el valor
		// recorre args, quita " i ' add nuevo valor
		ft_lstadd_back(&env_lst, ft_lstnew(args[1]));
}

// TODO
// export uno= dos= tres=
// Tiene que crear tres env con los nomres y el valor vacio
