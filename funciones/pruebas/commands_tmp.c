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

void commands(t_cmd *cmd, t_list *token)
{
	int valid_cmds = 0;
	t_list *current = token;

	// Count the number of valid commands
	while (current != NULL)
	{
		if (current->content[0] != '-' && strcmp(current->content, "<") != 0 && strcmp(current->content, ">") != 0 && strcmp(current->content, "|") != 0)
			valid_cmds++;
		current = current->next;
	}

	// Allocate memory for valid_cmds + 1 (for NULL termination) pointers to char
	cmd->command = malloc((valid_cmds + 1) * sizeof(char *));

	int i = 0;
	current = token;
	while (current != NULL)
	{
		if (current->content[0] != '-' && strcmp(current->content, "<") != 0 && strcmp(current->content, ">") != 0 && strcmp(current->content, "|") != 0)
		{
			cmd->command[i] = strdup(current->content);
			i++;
		}
		current = current->next;
	}

	cmd->command[i] = NULL; // Null-terminate the array
}

void ft_lstprint(t_list *list)
{
	t_list *current = list;
	while (current != NULL)
	{
		printf("%s ", current->content);
		current = current->next;
	}
	printf("\n");
}

void ft_print_dptr(char **array)
{
	int i = 0;
	while (array[i] != NULL)
	{
		printf("%s ", array[i]);
		i++;
	}
	printf("\n");
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

	commands(cmd, token);

	ft_print_dptr(cmd->command);

	// Clean up allocated memory
	free(cmd->command);
	free(cmd);
	free(token->next->next->next->next->next);
	free(token->next->next->next->next);
	free(token->next->next->next);
	free(token->next->next);
	free(token->next);
	free(token->content);
	free(token);

	return 0;
}
