#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	remove_quotes(char *str)
{
	int	len;

	len = strlen(str);
	if (len >= 2 && str[0] == '\"' && str[len - 1] == '\"')
	{
		memmove(str, str + 1, len - 2);
		str[len - 2] = '\0';
	}
}

int	main(void)
{
	char	*string;

	string = "NUEVO=\"toma mas\"";
	printf("Antes: %s\n", string);
	remove_quotes(string);
	printf("Después: %s\n", string);
	return (0);
}
