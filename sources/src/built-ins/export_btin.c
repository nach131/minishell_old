/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_btin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/04 00:17:47 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "libft.h"
#include "minishell.h"

void	custom_qsort(void *base, size_t num_elements, size_t element_size)
{
	char	*arr;
	size_t	i;
	char	*temp;
	size_t	j;
	char	*element_a;
	char	*element_b;

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
			if ((ft_strcmp(element_a, element_b)) > 0)
			{
				ft_memcpy(temp, element_a, element_size);
				ft_memcpy(element_a, element_b, element_size);
				ft_memcpy(element_b, temp, element_size);
			}
			j++;
		}
		i++;
	}
	free(temp);
}

void	print_dptr(char **arr)
{
	int	i;

	i = 1;
	if (arr == NULL)
		return ;
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

void	export_btin(t_list *env_lst, char **args, char **env)
{
	if (args[1] == NULL)
	{
		custom_qsort(env, ft_len_dptr(env) - 1, sizeof(char *));
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
