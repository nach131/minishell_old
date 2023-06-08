#include "../../../sources/lib/libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_cmd
{
	int				filefd[2];
	char			*command;
	char			**args;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

t_cmd	*cmd_new(char *str)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->filefd[0] = 0;
	new->filefd[1] = 0;
	new->command = ft_strdup(str);
	new->args = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
int	main(void)
{
	t_cmd	*toma;

	toma = (cmd_new("42 barcelona"));
	if (toma)
	{
		while (toma != NULL)
		{
			printf("%s\n", toma->command);
			toma = toma->next;
		}
	}
}
