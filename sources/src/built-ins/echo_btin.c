/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_btin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:02 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/07 21:10:46 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "path_env.h"

// TODO
// echo "Suma de los números:"
// echo "1 2 3 4 5" | tr " " "+" | bc
// NADIE LO HACE
// echo {1..10}

char	*take_dollar(char *env)
{
	if (*env == '$')
		env++;
	return (env);
}

void	print_echo(t_list *env_lst, char *args)
{
	char	*res;

	res = ft_lstfind_to_dptr(env_lst, take_dollar(args), find_env);
	res = env_value(res);
	printf("%s", res);
}

void	echo_btin(t_list *env_lst, char **args)
{
	int	i;
	int	no_newline;

	i = 1;
	no_newline = FALSE;
	if (args[1] != NULL && ft_strncmp(args[1], "-n", 2) == 0)
	{
		no_newline = TRUE;
		i++;
	}
	while (args[i] != NULL)
	{
		if (args[i][0] == '$' && args[i][1] == '(')
			// TODO
			// cat archivo.txt | echo $(wc -l)
			// recoguer el fd y pasarlo a wc
			printf("This is not in the mandatory");
		else if (args[i][0] == '$' && (args[i][1] >= '!' && args[i][1] <= '~'))
			print_echo(env_lst, args[i]);
		else
		{
			if (ft_strncmp(args[i], "-n", 2) != 0)
				printf("%s", args[i]);
		}
		if (args[i + 1] != NULL && ft_strncmp(args[i + 1], "-n", 2) != 0)
			printf(" ");
		i++;
	}
	if (!no_newline)
		printf("\n");
}

// // comentada
// void echo_btin(t_list *env_lst, char **args)
// {
// 	int i;
// 	int no_newline;

// 	i = 1;
// 	no_newline = FALSE;
// 	if (args[1] != NULL && ft_strncmp(args[1], "-n", 2) == 0)
// 	{
// 		no_newline = TRUE; // Set the flag to true if the -n option is provided
// 		i++;				// Skip the -n option in the arguments
// 	}
// 	while (args[i] != NULL)
// 	{
// 		if (args[i][0] == '$' && (args[i][1] >= '!' && args[i][1] <= '~'))
// 			print_echo(env_lst, args[i]);
// 		else
// 		{
// 			if (ft_strncmp(args[i], "-n", 2) != 0)
// 				printf("%s", args[i]);
// 		}
// 		if (args[i + 1] != NULL && ft_strncmp(args[i + 1], "-n", 2) != 0)
// 			printf(" ");
// Print space between arguments (if the next one is not -n)
// 		i++;
// 	}
// 	if (!no_newline) // Print newline if -n option is not provided
// 		printf("\n");
// }
