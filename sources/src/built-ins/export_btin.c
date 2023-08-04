/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_btin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/04 12:11:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "libft.h"
#include "minishell.h"

// int compare_env_strings(const void *a, const void *b)
// {
// 	// The environment strings are in the format "VARIABLE=value"
// 	// We need to compare only the VARIABLE part, so find the '=' character.
// 	const char *str_a = *(const char **)a;
// 	const char *str_b = *(const char **)b;
// 	// const char *equals_a = strchr(str_a, '=');
// 	// const char *equals_b = strchr(str_b, '=');

// 	// return ft_strcmp((char *)str_a, (char *)str_b);
// 	return strcmp(str_a, str_b);
// }

// void custom_qsort(void *base, size_t num_elements, size_t element_size, int (*compare)(const void *, const void *))
// {
// 	char *arr = (char *)base;
// 	size_t i = 0;
// 	char *temp = (char *)malloc(element_size);

// 	while (i < num_elements - 1)
// 	{
// 		size_t j = i + 1;
// 		while (j < num_elements)
// 		{
// 			char *element_a = arr + i * element_size;
// 			char *element_b = arr + j * element_size;

// 			if (compare(element_a, element_b) > 0)
// 			// if (strcmp(element_a, element_b) > 0)
// 			{
// 				memcpy(temp, element_a, element_size);
// 				memcpy(element_a, element_b, element_size);
// 				memcpy(element_b, temp, element_size);
// 			}

// 			j++;
// 		}

// 		i++;
// 	}

// 	free(temp);
// }
//=========================================================================

void print_dptr(char **arr)
{
	int i;

	i = -1;
	if (arr == NULL)
		return;
	while (arr[++i] != NULL)
		printf("declare -x %s\n", arr[i]);
}

void static custom_qsort(char **env, size_t size)
{
	char *tmp;
	size_t i;
	size_t j;
	size_t j_min;

	i = -1;
	while (++i < size - 1)
	{
		j_min = i;
		j = i + 1;
		while (++j < size)
		{
			if (env[j_min] && env[j] && ft_strcmp(env[j], env[j_min]) < 0)
				j_min = j;
		}
		if (j_min != i)
		{
			tmp = env[i];
			env[i] = env[j_min];
			env[j_min] = tmp;
		}
	}
}

char *insertQuotes(char *input)
{
	int len = ft_strlen(input);
	char *tmp = malloc((len + 3) * sizeof(char *));
	int i = 0;
	int j = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '=')
		{
			tmp[j] = input[i];
			j++;
			tmp[j] = '"';
		}
		else
			tmp[j] = input[i];
		i++;
		j++;
	}
	tmp[j] = '"';
	tmp[j + 1] = '\0';

	return (tmp);
}

// void add_export(t_list *env, t_cmd *cmd)
// {
// 	(void)cmd;
// 	ft_lstadd_back(&env, ft_lstnew("TOMATE=nuevo tomate"));
// }

void export_btin(t_list *env_lst, char **args, char **env)
{
	if (args[1] == NULL)
	{
		int i = -1;
		while (env[++i] != NULL)
			env[i] = insertQuotes(env[i]);
		custom_qsort(env, ft_len_dptr(env));
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
