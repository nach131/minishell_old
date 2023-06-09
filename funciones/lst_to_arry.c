/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:50:58 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/09 10:02:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../libft/inc/libft.h"

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

int main(void)
{
	t_list *lst;

	lst = ft_lstnew("UNO=uno");
	lst->next = ft_lstnew("DOS=dos");
	lst->next->next = ft_lstnew("TRES=tres");
	int num = ft_lstsize(lst);

	printf("%d\n", num);
	ft_lstprint(lst);

	char **array;

	array = malloc((num + 1) * sizeof(char *));

	int i = 0;
	while (lst)
	{
		array[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	array[i] = NULL;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}

	return (0);
}
