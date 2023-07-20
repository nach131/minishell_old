#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char *content;
	struct s_list *next;
} t_list;

typedef struct s_cmd
{
	int num_cmd;
	char **command;
	char ***args;
	char **env;
	int **filefd;
	char **out;
} t_cmd;

void static args(t_cmd *cmd, t_list *token)
{
	int num_args;
	int arg_index;
	t_list *current_token;
	int arg_length;
	t_list *arg_token;
	int i;

	num_args = cmd->num_cmd + 1;
	cmd->args = malloc((num_args) * sizeof(char *));
	arg_index = 0;
	current_token = token;
	while (current_token != NULL)
	{
		if (!strncmp(current_token->content, "|", 1) || !strncmp(current_token->content, ">", 1) || !strncmp(current_token->content, "<", 1))
		{
			current_token = current_token->next;
			continue;
		}
		arg_length = 0;
		arg_token = current_token;
		while (arg_token != NULL && strncmp(arg_token->content, "|", 1) && strncmp(arg_token->content, ">", 1) && strncmp(arg_token->content, "<", 1))
		{
			arg_length++;
			arg_token = arg_token->next;
		}
		cmd->args[arg_index] = malloc((arg_length + 1) * sizeof(char *));
		cmd->args[arg_index][arg_length] = NULL;
		i = 0;
		while (i < arg_length)
		{
			cmd->args[arg_index][i] = strdup(current_token->content);
			current_token = current_token->next;
			i++;
		}
		arg_index++;
	}
	cmd->args[arg_index] = NULL;
}

void ft_lstprint(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void ft_print_dptr(char **arr)
{
	int i;

	i = 0;
	if (arr == NULL)
		return;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
void ft_print_tptr(char ***arr)
{
	int i;
	int j;

	i = 0;
	if (arr == NULL)
		return;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != NULL)
		{
			printf("arr[%d][%d]: %s\n", i, j, arr[i][j]);
			j++;
		}
		i++;
	}
}

int main(void)
{
	t_list *token = calloc(1, sizeof(t_list));
	token->next = calloc(1, sizeof(t_list));
	token->next->next = calloc(1, sizeof(t_list));
	token->next->next->next = calloc(1, sizeof(t_list));
	token->next->next->next->next = calloc(1, sizeof(t_list));
	token->next->next->next->next->next = calloc(1, sizeof(t_list));

	token->next->next->next->next->next->next = NULL;

	token->content = strdup("ls");
	token->next->content = strdup("-l");
	token->next->next->content = strdup("-a");
	token->next->next->next->content = strdup("|");
	token->next->next->next->next->content = strdup("grep");
	token->next->next->next->next->next->content = strdup("lib");

	ft_lstprint(token);

	t_cmd *cmd = calloc(1, sizeof(t_cmd));

	args(cmd, token);

	ft_print_tptr(cmd->args);
}
