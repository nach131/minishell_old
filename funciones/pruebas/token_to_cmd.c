#include "../../sources/lib/libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_cmd
{
	int				filefd[2];
	char			*command;
	char			*args;
	char			*path;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

void	VerLista(t_list *lst)
{
	while (lst != NULL)
	{
		printf("\t%s\n", lst->content);
		lst = lst->next;
	}
}

void	reserveMemory(t_list *lst)
{
	t_list	*node;
	t_cmd	*cmd;
	int		argCount;
	t_list	*nextNode;

	node = lst;
	while (node != NULL)
	{
		cmd = (t_cmd *)node->content;
		if (cmd->args != NULL)
		{
			argCount = 0;
			nextNode = node->next;
			while (nextNode != NULL && strcmp((char *)nextNode->content,
					"|") != 0)
			{
				argCount++;
				nextNode = nextNode->next;
			}
			cmd->args = (char **)malloc((argCount + 1) * sizeof(char *));
			cmd->args[argCount] = NULL;
			nextNode = node->next;
			for (int i = 0; i < argCount; i++)
			{
				cmd->args[i] = (char *)nextNode->content;
				printf("%s\n", cmd->args[i]);
				nextNode = nextNode->next;
			}
		}
		node = node->next;
	}
}

int static	count_token(t_list *token)
{
	t_list	*tmp;
	int		i;

	tmp = token;
	i = 0;
	while (tmp != NULL)
	{
		if (!ft_strncmp(tmp->content, "|", 1) || !ft_strncmp(tmp->content, ">",
				1))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*recorrer_lista(t_list *a)
{
	// t_list static *tmp;
	// tmp = a;
	// while (tmp != NULL)
	// {
	// }
	return ("42");
}

char	**pasado(t_list *a)
{
	char	**cmd;
	int		tokens;
	int		i;

	i = 0;
	tokens = count_token(a);
	cmd = malloc(sizeof(char *) * tokens);
	while (i < tokens)
	{
		cmd[i] = recorrer_lista(a);
		i++;
	}
	// cmd[0] = "42";
	// cmd[1] = "Barcelona";
	return (cmd);
}

int	main(void)
{
	t_list	*a;
	char	**cmd;

	a = ft_lstnew("cat");
	ft_lstadd_back(&a, ft_lstnew("archivo.txt"));
	ft_lstadd_back(&a, ft_lstnew("|"));
	ft_lstadd_back(&a, ft_lstnew("grep"));
	ft_lstadd_back(&a, ft_lstnew("42"));
	ft_lstadd_back(&a, ft_lstnew("sed"));
	ft_lstadd_back(&a, ft_lstnew("s/42/131/g"));
	ft_lstadd_back(&a, ft_lstnew(">"));
	ft_lstadd_back(&a, ft_lstnew("salida.txt"));
	VerLista(a);
	cmd = pasado(a);
	printf("%s\n", cmd[0]);
	printf("%s\n", cmd[1]);
	// reserveMemory(a);
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt

// gcc token_to_cmd.c ../../../libft/libft.a && ./a.out
