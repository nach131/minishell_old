/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_btin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/03 17:10:54 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "minishell.h"
#include "working_tools.h"

void	start_export(t_list *palabras)
{
	t_list	*current;
	int		num_palabras;
	int		i;
	int		j;
	t_list	*next;
	char	*word1;
	char	*word2;
	t_list	*temp;

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
			// word1 = ft_strtok(current->content, "=");
			// word2 = ft_strtok(next->content, "=");
			word1 = (char *)current->content;
			word2 = (char *)next->content;
			if (ft_strcmp(word1, word2) < 0)
			// Modificación en la comparación
			{
				temp = current;
				current->content = next->content;
				next = temp;
			}
			current = current->next;
			j++;
		}
		i++;
	}
	current = palabras;
	ft_lstreverse(current);
	while (current != NULL)
	{
		printf("declare -x %s\n", (char *)current->content);
		current = current->next;
	}
	// // Liberar la memoria de la lista
	// current = palabras;
	// while (current != NULL)
	// {
	// 	temp = current;
	// 	current = current->next;
	// 	free(temp);
	// }
}

// VALE ....
// PRIMERO EL NOMBRE DE LA VARIABLE, DEPUES LA VARIABLE DENTRO DE ""
// asi que organizar solo los nombres despues buscar cada variable e imprimir el valor

void	add_export(t_list *env, t_cmd *cmd)
{
	(void)cmd;
	ft_lstadd_back(&env, ft_lstnew("TOMATE=nuevo tomate"));
}

void export_btin(t_list *env)
{
	ft_lstadd_back(&env, ft_lstnew("TOMATE_ONE=export_btin"));

	printf("export_btin\n");
}

// TODO
// export uno dos tres
// Tiene que crear tres env con los nomres y el valor vacio
