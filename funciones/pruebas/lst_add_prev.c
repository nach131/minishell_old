/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:29:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/05 09:56:10 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_cmd
{
	int				filefd[2];
	char			*command;
	char			**args;
	char			*path;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

int	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	res = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*s1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}

t_cmd	*cmd_new(char *str)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = ft_strdup(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_cmd	*cmd_last(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next != NULL)
		cmd = cmd->next;
	return (cmd);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	if (!(*cmd))
	{
		*cmd = new;
		new->prev = NULL; // Establecer prev como NULL para el primer nodo
	}
	else
	{
		last = cmd_last(*cmd);
		last->next = new;
		new->prev = last; // Establecer prev como el último nodo existente
	}
}

void	printf_lst(t_cmd *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->command);
		lst = lst->next;
	}
}

void	VerLista(t_cmd *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->command);
		if (lst->prev != NULL)
			printf("\tprev: %s\n", lst->prev->command);
		//		if (lst != NULL)
		lst = lst->next;
	}
}

int	main(void)
{
	t_cmd	*a;

	a = cmd_new("1 Barcelona");
	cmd_add_back(&a, cmd_new("2 Madrid"));
	cmd_add_back(&a, cmd_new("3 Malaga"));
	VerLista(a);
}

// 1 Barcelona
// 2 Madrid
// 	prev: 1 Barcelona
// 3 Malaga
// 	prev: 2 Madrid
