/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_prev_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:29:40 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/06 14:26:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_cmd
{
	char			*command;
	int				filefd[2];
	char			**args;
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

t_cmd	*cmd_new(t_cmd cmd)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = ft_strdup(cmd.command);
	new->filefd[0] = cmd.filefd[0];
	new->filefd[1] = cmd.filefd[1];
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
		new->prev = NULL;
	}
	else
	{
		last = cmd_last(*cmd);
		last->next = new;
		new->prev = last;
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

void	ver_lista(t_cmd *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->command);
		printf("%s\n", lst->args);
		printf("%d, %d\n", lst->filefd[0], lst->filefd[1]);
		// if (lst->args)
		// 	printf("%s\n", lst->args[0]);
		if (lst->prev != NULL)
		{
			printf("\tprev: %s\n", lst->prev->command);
		}
		lst = lst->next;
	}
}

int	main(void)
{
	t_cmd	*a;

	a = cmd_new((t_cmd){
		"1 Barcelona",
		10,
		22,
	});
	cmd_add_back(&a, cmd_new((t_cmd){"1 Madrid"}));
	cmd_add_back(&a, cmd_new((t_cmd){"1 Malaga"}));
	ver_lista(a);
}

// 1 Barcelona
// 2 Madrid
// 	prev: 1 Barcelona
// 3 Malaga
// 	prev: 2 Madrid
//=========================================================================
// // Crear una nueva estructura t_cmd con los valores deseados
// t_cmd newCmd = {
// 	.command = "1 Barcelona",
// 	.filefd[0] = 10,
// 	.filefd[1] = 22,
// };

// // Asignar memoria para el arreglo args
// newCmd.args = malloc(sizeof(char *) * 4);

// // Asignar los valores al arreglo args
// newCmd.args[0] = strdup("cat");
// newCmd.args[1] = strdup("archivo.txt");
// newCmd.args[2] = strdup("-l");
// newCmd.args[3] = NULL;
// Es importante agregar un valor nulo al final del arreglo

// // Asignar los punteros prev y next
// newCmd.prev = NULL;
// newCmd.next = NULL;

// // Asignar la nueva estructura a la variable a
// a = cmd_new(newCmd);
//=========================================================================
