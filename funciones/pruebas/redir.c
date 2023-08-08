#include <stdio.h>
#include <stdlib.h>

enum
{
	NOTHING,
	PIPE,
	REDIR_IN,
	D_REDIR_IN,
	REDIR_OUT,
	D_REDIR_OUT,
};

int *ft_numdup(int num)
{
	int *res = malloc(sizeof(int));
	if (res != NULL)
	{
		*res = num; // Copiar el valor desde num a la memoria asignada
	}
	return res;
}

void print_num(int **arr)
{
	int i = 0;
	while (arr[i] != NULL)
	{
		printf("Valor en redir[%d]: %d\n", i, *arr[i]);
		free(arr[i]); // Liberar la memoria asignada en ft_numdup
		i++;
	}
	free(arr); // Liberar el arreglo de punteros al final
}

int main(void)
{
	int **redir;

	redir = calloc(5, sizeof(int *));
	redir[3] = NULL;				   // Para asignar un puntero nulo, utiliza NULL en lugar de 0
	redir[0] = ft_numdup(PIPE);		   // Asignar el valor PIPE al puntero
	redir[1] = ft_numdup(PIPE);		   // Asignar el valor D_REDIR_OUT al puntero
	redir[2] = ft_numdup(D_REDIR_OUT); // Asignar el valor D_REDIR_OUT al puntero
	print_num(redir);
	return (0);
}
