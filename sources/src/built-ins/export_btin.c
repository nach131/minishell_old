/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_btin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:50:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/06 00:37:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "builtins.h"

void static	print_export(char **arr)
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

char	*insert_quotes(char *input)
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

void	export_btin(t_list *env_lst, char **args, char **env)
{
	int	i;

	if (args[1] == NULL)
	{
		i = -1;
		while (env[++i] != NULL)
			env[i] = insert_quotes(env[i]);
		custom_qsort(env, ft_len_dptr(env));
		print_export(env);
	}
	else
		add_export(env_lst, args);
}
