
// BORRA CADA NODO UNA VES PASADO

char **args(t_list *token)
{
	int num;
	char **res;
	int i;
	t_list *current;
	t_list *next;

	num = count_to_token_cmd(token);

	res = malloc((num + 1) * sizeof(char *));
	i = 0;
	current = token;

	// while (current != '|')
	while (i < num)
	{
		res[i] = ft_strdup(current->content);
		next = current->next;
		free(current->content);
		free(current);
		current = next;
		i++;
	}
	res[i] = NULL;

	return res;
}
