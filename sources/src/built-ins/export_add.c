/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:56:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/05 10:47:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"
#include "minishell.h"

// int this_iqual_v2(char *s)
// {
// 	int i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '=')
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }

void add_export(t_list *env_lst, char **args)
{
	int i;
	t_list *find = NULL;
	i = 1;
	char *tmp;

	while (args[i] != NULL)
	{

		take_quote(args[i]);
		printf("sin comillas: %s\n", args[i]);

		tmp = ft_substr(args[i], 0, ft_strcspn(args[i], "="));
		printf(RED "tmp: %s\n", tmp);

		if (!ft_lstfind(env_lst, tmp, find_env))
		{
			printf(RED "NO HAY: \n");
			ft_lstadd_back(&env_lst, ft_lstnew(args[i]));
		}
		else
		{
			find = ft_lstfind(env_lst, tmp, find_env);
			printf(GREEN "pasado: %s\n", args[i]);
			printf(GREEN "encontrado: %s\n", find->content);
			free(find->content);
			// find->content = ft_strdup("tomate"); // hay que hacer join con args[i]
			find->content = ft_strdup(args[i]); // hay que hacer join con args[i]
		}
		free(tmp);
		i++;
	}
}

// TODO
// si no tiene = añadir con ="" a export
// export uno
// uno=""