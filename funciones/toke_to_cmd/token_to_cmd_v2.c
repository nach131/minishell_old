#include "../../sources/lib/libft/inc/libft.h"
#include "../../sources/lib/libft/inc/colorsft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_cmd
{
	char *command;
	char **args;
	char **env;
	int filefd[2];
	int out;
	struct s_cmd *prev;
	struct s_cmd *next;
	// char			*path;
} t_cmd;

int count_to_token_cmd(t_list *token)
{
	int i;

	i = 0;
	while (token != NULL)
	{
		// CUIADO CON EL ESPACIO EN BLANCO
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1))
			break;
		i++;
		token = token->next;
	}
	return (i);
}

t_cmd *cmd_new(t_cmd cmd)
{
	t_cmd *new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = cmd.command;
	new->filefd[0] = cmd.filefd[0];
	new->filefd[1] = cmd.filefd[1];
	new->args = cmd.args;
	new->env = cmd.env;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// HAY QUE PASAR EL NODO AL FINAL Y DEPUES FREE
char static **args(t_list **token)
{
	int num;
	char **res;
	int i;

	num = count_to_token_cmd(*token);
	res = malloc((num + 1) * sizeof(char *));
	i = 0;
	while (token != NULL)
	{
		if (!ft_strncmp((*token)->content, "|", 1) || !ft_strncmp((*token)->content, ">", 1))
			break;
		res[i] = ft_strdup((*token)->content);
		i++;
		(*token) = (*token)->next;
	}
	res[i] = NULL;
	// borrar todo los nodos ya pasados hasta el "|"
	return (res);
}

// t_cmd *one_cmd(t_list *token, t_list *env)
// {
// 	t_cmd *tmp;

// 	char *envs[] = {"aaaaa", "bbbbb", "ccccc", NULL};
// 	tmp = cmd_new((t_cmd){
// 		.command = token->content,
// 		.args = args(&token),
// 		.env = envs,
// 		.filefd = {STDIN_FILENO, STDOUT_FILENO},
// 		.prev = NULL,
// 		.next = NULL});
// 	return (tmp);
// }

t_cmd *two_cmd(t_list **token, t_list *env, int *num_cmd)
{
	t_cmd *tmp;
	int static i = 0;
	int filefd[2];

	printf(CYAN "Dos...\n" WHITE);

	// hacer una funcion como la de contar hasta  | o > para saber
	// que fileno poner
	if (!i)
	{
		pipe(filefd);
		tmp = cmd_new((t_cmd){
			.command = (*token)->content,
			.args = args(token),
			.env = NULL,
			.filefd = {STDIN_FILENO, filefd[1]},
			.prev = NULL,
			.next = NULL});
		*num_cmd -= 1;
	}
	return (tmp);
}

int count_cmd(t_list *token)
{
	t_list *tmp;
	int i;

	tmp = token;
	i = 1;
	while (tmp != NULL)
	{
		if (!ft_strncmp(tmp->content, "|", 1) || !ft_strncmp(tmp->content, ">",
															 1))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_cmd *token_to_pipe(t_list **token, t_list *env)
{
	t_cmd *tmp;
	int num_cmd;
	char *command = "Aki comando";

	num_cmd = count_cmd((*token));
	printf(GREEN "\t%d\n" WHITE, num_cmd);

	if (command && num_cmd == 1)
	{
		printf(RED "UNO...\n" WHITE);
		tmp = NULL;
		// tmp = one_cmd(token, env);
	}
	else if (command && num_cmd == 2)
	{
		tmp = two_cmd(token, env, &num_cmd);
		printf(GREEN "\tdespues: %d\n" WHITE, num_cmd);
		// tmp = NULL;
	}
	else
	{
		printf(RED "Muchas mas...\n" WHITE);
		tmp = NULL;
	}

	return (tmp);
}

int main(void)
{
	t_list *a;
	t_cmd *cmd;

	a = ft_lstnew("cat");
	ft_lstadd_back(&a, ft_lstnew("archivo.txt"));
	ft_lstadd_back(&a, ft_lstnew("|"));
	ft_lstadd_back(&a, ft_lstnew("grep"));
	ft_lstadd_back(&a, ft_lstnew("\"42\""));
	//=========================================================================
	// ft_lstadd_back(&a, ft_lstnew("|"));
	// ft_lstadd_back(&a, ft_lstnew("sed"));
	// ft_lstadd_back(&a, ft_lstnew("\"s/42/131/g\""));
	ft_lstprint(a);
	cmd = token_to_pipe(&a, a);
	if (cmd)
	{
		printf("COMMAND: %s\n", cmd->command);
		while (cmd)
		{
			int i = 0;
			int j = 0;
			printf("\t__args__\n");
			while (cmd->args[i])
			{
				printf("\t%s\n", cmd->args[i]);
				i++;
			}
			printf("__envs__\n");
			if (cmd->env)
			{
				while (cmd->env[j] != NULL)
				{
					printf("%s\n", cmd->env[j]);
					j++;
				}
			}
			cmd = cmd->next;
		}
	}
}

//  cat archivo.txt | grep "42" | sed "s/42/131/g" | sed "s/Barcelona/Nueva York/g" > salida.txt

// gcc token_to_cmd.c ../../../libft/libft.a && ./a.out

// ft_lstadd_back(&a, ft_lstnew("|"));
// ft_lstadd_back(&a, ft_lstnew("sed"));
// ft_lstadd_back(&a, ft_lstnew("\"s/42/131/g\""));
// ft_lstadd_back(&a, ft_lstnew(">"));
// ft_lstadd_back(&a, ft_lstnew("\"salida.txt\""));

// if (cmd)
// {
// 	while (cmd)
// 	{
// 		int i = 0;
// 		int j = 0;
// 		while (cmd->args[i])
// 		{
// 			printf("%s\n", cmd->args[i]);
// 			i++;
// 		}
// 		printf("-----\n");
// 		while (cmd->env[j])
// 		{
// 			printf("%s\n", cmd->env[j]);
// 			j++;
// 		}
// 		cmd = cmd->next;
// 	}
// }
