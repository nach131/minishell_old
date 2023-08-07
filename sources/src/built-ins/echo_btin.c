/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_btin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:02 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/07 12:33:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "path_env.h"

// TODO
// cat archivo.txt | echo $(wc -l) // bruno si
// echo "Suma de los números:"
// echo "1 2 3 4 5" | tr " " "+" | bc
// NADIE LO HACE
// echo {1..10}

char *take_dollar(char *env)
{
	if (*env == '$')
		env++;
	return (env);
}

// void echo_btin(t_list *env_lst, char **args)
// {
// 	int i = 1;
// 	char *res;

// 	if (args[1] != NULL)
// 	{
// 		while (args[i] != NULL)
// 		{
// 			if (args[i][0] == '$' && (args[i][1] >= '!' && args[i][1] <= '~'))
// 			{
// 				// printf("ENV: %s", take_dollar(args[i]));
// 				res = ft_lstfind_to_dptr(env_lst, take_dollar(args[i]), find_env);
// 				res = env_value(res);
// 				printf("%s", res);
// 			}
// 			else
// 				printf("%s", args[i]);
// 			printf(" ");
// 			i++;
// 		}
// 	}
// 	if (ft_strncmp(args[1], "-n", 2))
// 		printf("\n");
// }

void echo_btin(t_list *env_lst, char **args)
{
	int i = 1;
	char *res;
	int no_newline = FALSE; // Initialize a boolean flag for -n option

	if (args[1] != NULL && ft_strncmp(args[1], "-n", 2) == 0)
	{
		no_newline = TRUE; // Set the flag to true if the -n option is provided
		i++;			   // Skip the -n option in the arguments
	}

	while (args[i] != NULL)
	{
		if (args[i][0] == '$' && (args[i][1] >= '!' && args[i][1] <= '~'))
		{
			// printf("ENV: %s", take_dollar(args[i]));
			res = ft_lstfind_to_dptr(env_lst, take_dollar(args[i]), find_env);
			res = env_value(res);
			printf("%s", res);
		}
		else
		{
			if (ft_strncmp(args[i], "-n", 2) != 0)
				printf("%s", args[i]);
		}

		if (args[i + 1] != NULL && ft_strncmp(args[i + 1], "-n", 2) != 0)
			printf(" "); // Print space between arguments (if the next one is not -n)

		i++;
	}

	if (!no_newline) // Print newline if -n option is not provided
		printf("\n");
}
