/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:52:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/23 16:32:43 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "colorsft.h"
#include "ft_printf.h"
#include "libft.h"
#include "tools.h"

// int	countPointers(char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (env[i] != NULL)
// 		i++;
// 	return (i);
// }

// void	printf_env(char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (env[i] != NULL)
// 	{
// 		ft_printf(CYAN "%s\n", env[i]);
// 		i++;
// 	}
// 	ft_printf(ORANGE "TOTAL: %d\n", countPointers(env));
// }

void	print_find_env(char *find, t_list *env)
{
	t_list	*tmp;

	ft_printf(GREEN "env: %d\n", ft_lstsize(env));
	tmp = ft_lstfind(env, find, find_env);
	if (tmp)
	{
		ft_printf(MAGENTA "[%s] %s\n", find, tmp->content);
		tmp->content = env_value(tmp->content);
		ft_printf(CYAN "[%s] %s\n" WHITE, find, tmp->content);
	}
	else
	{
		ft_printf(RED "NO ENCONTRADO\n");
	}
}
