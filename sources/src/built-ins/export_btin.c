/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_btin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/04 12:35:54 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"

void static	print_dptr(char **arr)
{
	int	i;

	i = -1;
	if (arr == NULL)
		return ;
	while (arr[++i] != NULL)
		printf("declare -x %s\n", arr[i]);
}

void static	custom_qsort(char **env, size_t size)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	j_min;

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

// char	*insertQuotes(char *input)
// {
// 	int		len;
// 	char	*tmp;
// 	int		i;
// 	int		j;

// 	len = ft_strlen(input);
// 	tmp = malloc((len + 3) * sizeof(char *));
// 	i = 0;
// 	j = 0;
// 	while (input[i] != '\0')
// 	{
// 		if (input[i] == '=')
// 		{
// 			tmp[j] = input[i];
// 			j++;
// 			tmp[j] = '"';
// 		}
// 		else
// 			tmp[j] = input[i];
// 		i++;
// 		j++;
// 	}
// 	tmp[j] = '"';
// 	tmp[j + 1] = '\0';
// 	free(input);
// 	return (tmp);
// }

char	*insertQuotes(char *input)
{
	t_qoutes	data;

	data.len = ft_strlen(input);
	data.tmp = malloc((data.len + 3) * sizeof(char *));
	data.i = 0;
	data.j = 0;
	while (input[data.i] != '\0')
	{
		if (input[data.i] == '=')
		{
			data.tmp[data.j] = input[data.i];
			data.j++;
			data.tmp[data.j] = '"';
		}
		else
			data.tmp[data.j] = input[data.i];
		data.i++;
		data.j++;
	}
	data.tmp[data.j] = '"';
	data.tmp[data.j + 1] = '\0';
	free(input);
	return (data.tmp);
}

// void add_export(t_list *env, t_cmd *cmd)
// {
// 	(void)cmd;
// 	ft_lstadd_back(&env, ft_lstnew("TOMATE=nuevo tomate"));
// }

void	export_btin(t_list *env_lst, char **args, char **env)
{
	int	i;

	if (args[1] == NULL)
	{
		i = -1;
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
