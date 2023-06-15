#include "../../sources/lib/libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_cmd
{
	char *command;
	char **args;
	char **env;
	int filefd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
	// char			*path;
}					t_cmd;

int count_to_token_cmd(t_list *token)
{
	int i;

	i = 0;
	while (token != NULL)
	{
		// CUIADO CON EL ESPACIO EN BLANCO
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content,
															   ">", 1))
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

char static **args(t_list *token)
{
	int num;
	char **res;
	int i;

	num = count_to_token_cmd(token);
	res = malloc((num + 1) * sizeof(char *));
	i = 0;
	while (token != NULL)
	{
		res[i] = ft_strdup(token->content);
		i++;
		token = token->next;
	}
	res[i] = NULL;
	// borrar todo los nodos ya pasados hasta el "|"
	return (res);
}

t_cmd *one_cmd(t_list *token, t_list *env)
{
	t_cmd *tmp;

	char *envs[] = {"aaaaa", "bbbbb", "ccccc", NULL};
	tmp = cmd_new((t_cmd){
		.command = token->content,
		.args = args(token),
		.env = envs,
		.filefd = {STDIN_FILENO, STDOUT_FILENO},
		.prev = NULL,
		.next = NULL});
	return (tmp);
}

t_cmd *two_cmd(t_list *token, t_list *env)
{
	t_cmd *first_cmd;
	t_cmd *prev_cmd;
	t_cmd *current_cmd;
	int filefd[2];
	char *envs[] = {"aaaaa", "bbbbb", "ccccc", NULL};

	first_cmd = NULL;
	prev_cmd = NULL;

	while (token != NULL)
	{
		if (!ft_strncmp(token->content, "|", 1))
		{
			pipe(filefd);

			current_cmd = cmd_new((t_cmd){
				.command = token->next->content,
				.args = args(token->next),
				.env = envs,
				.filefd = {STDIN_FILENO, filefd[1]},
				.prev = prev_cmd,
				.next = NULL});

			if (first_cmd == NULL)
				first_cmd = current_cmd;

			if (prev_cmd != NULL)
				prev_cmd->next = current_cmd;

			prev_cmd = current_cmd;

			current_cmd = cmd_new((t_cmd){
				.command = token->next->next->next->content,
				.args = args(token->next->next->next),
				.env = envs,
				.filefd = {filefd[0], STDOUT_FILENO},
				.prev = prev_cmd,
				.next = NULL});

			prev_cmd->next = current_cmd;
			prev_cmd = current_cmd;

			token = token->next->next->next->next;
		}
		else if (!ft_strncmp(token->content, ">", 1))
		{
			current_cmd = cmd_new((t_cmd){
				.command = token->next->content,
				.args = args(token->next),
				.env = envs,
				.filefd = {STDIN_FILENO, STDOUT_FILENO},
				.prev = prev_cmd,
				.next = NULL});

			if (first_cmd == NULL)
				first_cmd = current_cmd;

			if (prev_cmd != NULL)
				prev_cmd->next = current_cmd;

			prev_cmd = current_cmd;

			token = token->next->next;
		}

		token = token->next;
	}

	return first_cmd;
}

int count_cmd(t_list *token)
{
	t_list *tmp;
	int i;

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

t_cmd *token_to_pipe(t_list *token, t_list *env)
{
	t_cmd *tmp;
	int num_cmd;
	char *command = "Aki comando";

	num_cmd = count_cmd(token);
	printf("\t%d\n", num_cmd);
	if (!command)
		tmp = NULL;
	else if (command && num_cmd == 0)
	{
		printf("UNO...\n");
		tmp = one_cmd(token, env);
	}
	else if (command && num_cmd == 1)
	{
		printf("Dos...\n");
		// tmp = two_cmd(token, env);
	}
	else
	{
		printf("Muchas mas...\n");
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
	// ft_lstadd_back(&a, ft_lstnew("|"));
	// ft_lstadd_back(&a, ft_lstnew("grep"));
	// ft_lstadd_back(&a, ft_lstnew("\"42\""));
	ft_lstprint(a);
	cmd = token_to_pipe(a, a);
	if (cmd)
	{
		while (cmd)
		{
			int i = 0;
			int j = 0;
			while (cmd->args[i])
			{
				printf("%s\n", cmd->args[i]);
				i++;
			}
			printf("--envs---\n");
			while (cmd->env[j])
			{
				printf("%s\n", cmd->env[j]);
				j++;
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
