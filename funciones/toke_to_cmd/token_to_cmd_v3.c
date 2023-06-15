#include "../../sources/lib/libft/inc/libft.h"
#include "../../sources/lib/libft/inc/colorsft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_cmd
{
	int num_cmd;
	char **command;
	char ***args;
	char ***env;
	int filefd[2];
	int out;
} t_cmd;

int count_commands(t_list *token)
{
	int count = 0;
	int inCommand = 0;

	while (token != NULL)
	{
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1))
			inCommand = 1;
		else if (inCommand && ft_strncmp(token->content, "|", 1) && ft_strncmp(token->content, ">", 1))
		{
			count++;
			inCommand = 0;
		}

		token = token->next;
	}

	return count;
}
int count_nodes_in_command(t_list *token)
{
	int count = 0;
	int numCommands = count_commands(token);
	int commandCount = 0;

	while (token != NULL)
	{
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1))
			commandCount++;
		else if (commandCount == numCommands)
			count++;

		token = token->next;
	}

	return count;
}

// char static ***args(t_list *token)
// {
// 	int num;
// 	char **res;
// 	int i;

// 	num = count_to_token_cmd(token);
// 	res = malloc((num) * sizeof(char *));
// 	i = 0;
// 	while (token != NULL)
// 	{
// 		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1))
// 			break;
// 		res[i] = ft_strdup(token->content);
// 		i++;
// 		token = token->next;
// 	}
// 	res[i] = NULL;
// 	// borrar todo los nodos ya pasados hasta el "|"
// 	return (res);
// }

// char ***args(t_list *token)
// {
// 	int num = count_to_token_cmd(token);
// 	char ***res = malloc((num) * sizeof(char **)); // Alojar memoria para num+1 punteros
// 	int i = 0;
// 	int j = 0;

// 	// Alojar memoria para cada puntero dentro de res
// 	for (i = 0; i < num; i++)
// 	{
// 		res[i] = malloc(2 * sizeof(char *)); // Alojar memoria para dos punteros
// 	}

// 	i = 0;
// 	while (token != NULL)
// 	{
// 		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1))
// 		{
// 			// Ignorar "|" y ">"
// 			token = token->next;
// 			continue;
// 		}

// 		res[i][j] = ft_strdup(token->content);
// 		j++;

// 		if (j == 2)
// 		{
// 			// Se ha alcanzado el segundo argumento para el comando actual
// 			i++;
// 			j = 0;
// 		}

// 		token = token->next;
// 	}

// 	res[num] = NULL;

// 	return res;
// }

void toma(t_list *token)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));

	int numCommands = count_commands(token);
	printf("Número de comandos: %d\n", numCommands);
	int numNodesInCommand = count_nodes_in_command(token);
	printf("Número de nodos en el último comando: %d\n", numNodesInCommand);

	ft_lstprint(token);
}

int main(void)
{
	t_list *token;

	token = ft_lstnew("cat");
	ft_lstadd_back(&token, ft_lstnew("archivo.txt"));
	ft_lstadd_back(&token, ft_lstnew("|"));
	ft_lstadd_back(&token, ft_lstnew("grep"));
	ft_lstadd_back(&token, ft_lstnew("\"42\""));
	ft_lstadd_back(&token, ft_lstnew(">"));
	ft_lstadd_back(&token, ft_lstnew("salida.txt"));
	toma(token);
}
