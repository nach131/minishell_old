#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_cmd
{
	char			*command;
	struct s_cmd	*next;
}					t_cmd;

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
		*cmd = new;
	else
	{
		last = cmd_last(*cmd);
		last->next = new;
	}
}
t_cmd	*cmd_new(char *str)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->command = strdup(str);
	new->next = NULL;
	return (new);
}

void	parse_command(char *line, t_cmd **cmd)
{
	int		in_quotes;
	char	*start;

	in_quotes = 0;
	start = line;
	while (*line != '\0')
	{
		if (*line == '\"')
			in_quotes = !in_quotes;
		else if (*line == ' ' && !in_quotes)
		{
			*line = '\0';
			cmd_add_back(cmd, cmd_new(start));
			start = line + 1;
		}
		line++;
	}
	cmd_add_back(cmd, cmd_new(start));
}

void	execute_command(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		printf("Error al crear el proceso hijo.\n");
		return ;
	}
	else if (pid == 0)
	{
		// Proceso hijo
		execvp(cmd->command, &(cmd->command));
		printf("Error al ejecutar el comando.\n");
		exit(1);
	}
	else
	{
		// Proceso padre
		wait(NULL);
	}
}

int	main(void)
{
	char	*line;
	t_cmd	*cmd;
	int		i;
	t_cmd	*tmp;

	cmd = NULL;
	while (1)
	{
		line = readline("Minishell> ");
		if (line == NULL)
		{
			printf("\n");
			break ;
		}
		add_history(line);
		parse_command(line, &cmd);
		while (cmd)
		{
			execute_command(cmd);
			tmp = cmd;
			cmd = cmd->next;
			free(tmp->command);
			free(tmp);
		}
	}
	return (0);
}
