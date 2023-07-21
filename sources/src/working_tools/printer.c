/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:52:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/20 21:52:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "colorsft.h"
#include "ft_printf.h"
#include "libft.h"
#include "minishell.h"
#include "readline/history.h"
#include "readline/readline.h"
#include "working_tools.h"
#include "cmd.h"

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

// printea cuantas cmd line hay en el historial
void	history_line(void)
{
	if (history_length)
		ft_printf(RED "cmd %d\n" WHITE, history_length);
}

void	print_filefd(int **filefd)
{
	int	i;

	i = 0;
	if (filefd == NULL)
		return ;
	while (filefd[i] != NULL)
	{
		printf(YELLOW "filefd[%d][IN]: %d\n", i, filefd[i][0]);
		printf("filefd[%d][OUT]: %d\n" WHITE, i, filefd[i][1]);
		i++;
	}
}
