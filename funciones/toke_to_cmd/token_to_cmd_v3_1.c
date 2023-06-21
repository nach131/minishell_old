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

// contar el numero de elementos de command
int count_elements(char **arr)
{
	int count = 0;
	while (arr[count] != NULL)
	{
		count++;
	}
	return count;
}

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

// // char static ***args(t_list *token)
// // {
// // 	int num;
// // 	char **res;
// // 	int i;

// // 	num = count_to_token_cmd(token);
// // 	res = malloc((num) * sizeof(char *));
// // 	i = 0;
// // 	while (token != NULL)
// // 	{
// // 		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1))
// // 			break;
// // 		res[i] = ft_strdup(token->content);
// // 		i++;
// // 		token = token->next;
// // 	}
// // 	res[i] = NULL;
// // 	// borrar todo los nodos ya pasados hasta el "|"
// // 	return (res);
// // }

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

void commands(t_cmd *cmd, t_list *token)
{
	int i = 0;
	int valid_cmds = 0; // Contador para rastrear el número de comandos válidos agregados

	cmd->command = malloc((cmd->num_cmd + 1) * sizeof(char *));
	while (token != NULL)
	{
		if (!ft_strncmp(token->content, "|", 1) || !ft_strncmp(token->content, ">", 1))
		{
			// Ignorar "|" y ">"
			token = token->next;
			continue;
		}

		if (i % 2 == 0)
		{
			// Agregar el primer valor de la lista
			cmd->command[valid_cmds] = ft_strdup(token->content);
			valid_cmds++;
		}

		token = token->next;
		i++;
	}
}

void args(t_cmd *cmd, t_list *token)
{
	int num_args = cmd->num_cmd + 1;
	cmd->args = malloc((num_args) * sizeof(char *));

	int arg_index = 0;
	t_list *current_token = token;
	while (current_token != NULL)
	{
		if (!ft_strncmp(current_token->content, "|", 1) || !ft_strncmp(current_token->content, ">", 1))
		{
			current_token = current_token->next;
			continue;
		}

		int arg_length = 0;
		t_list *arg_token = current_token;
		while (arg_token != NULL && ft_strncmp(arg_token->content, "|", 1) && ft_strncmp(arg_token->content, ">", 1))
		{
			arg_length++;
			arg_token = arg_token->next;
		}

		cmd->args[arg_index] = malloc((arg_length + 1) * sizeof(char *));
		cmd->args[arg_index][arg_length] = NULL;

		int i = 0;
		while (i < arg_length)
		{
			cmd->args[arg_index][i] = ft_strdup(current_token->content);
			current_token = current_token->next;
			i++;
		}

		arg_index++;
	}
}

void test_args(t_list *token)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));

	cmd->num_cmd = count_commands(token) + 1;
	int numNodesInCommand = count_nodes_in_command(token);
	printf("Número de nodos en el último comando: %d\n", numNodesInCommand);
	commands(cmd, token);
	printf(GREEN "Número de comandos: %d\n" WHITE, cmd->num_cmd);
	args(cmd, token);

	int i = 0;
	while (i < cmd->num_cmd)
	{
		int j = 0;
		printf(CYAN "%d\n", count_elements(cmd->args[i]));
		while (j < count_elements(cmd->args[i]))
		{
			printf(ORANGE "\t%s\n", cmd->args[i][j]);
			j++;
		}

		i++;
	}
}

int main(void)
{
	t_list *token;
	t_cmd *cmd = malloc(sizeof(t_cmd));
	cmd->num_cmd = count_commands(token) + 1;

	token = ft_lstnew("cat");
	ft_lstadd_back(&token, ft_lstnew("archivo.txt"));
	ft_lstadd_back(&token, ft_lstnew("|"));
	ft_lstadd_back(&token, ft_lstnew("grep"));
	ft_lstadd_back(&token, ft_lstnew("\"42\""));
	ft_lstadd_back(&token, ft_lstnew(">"));
	ft_lstadd_back(&token, ft_lstnew("salida.txt"));
	printf("Tokens\n");
	ft_lstprint(token);
	args(cmd, token);
	int i = 0;
	while (i < cmd->num_cmd)
	{
		int j = 0;
		printf(CYAN "%d\n", count_elements(cmd->args[i]));
		while (j < count_elements(cmd->args[i]))
		{
			printf(ORANGE "\t%s\n", cmd->args[i][j]);
			j++;
		}

		i++;
	}

	// test_args(token);
}
