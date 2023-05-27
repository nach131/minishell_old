/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:29:36 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/26 12:28:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ║                     https://github.com/Carlos1073                      ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../sources/lib/libft/inc/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list	*palabras;

	palabras = NULL;
	palabras = malloc(sizeof(t_list));
	palabras->content = "__CF_USER_TEXT_ENCODING";
	palabras->next = malloc(sizeof(t_list));
	palabras->next->content = "COLORFGBG";
	palabras->next->next = malloc(sizeof(t_list));
	palabras->next->next->content = "CLICOLOR";
	palabras->next->next->next = malloc(sizeof(t_list));
	palabras->next->next->next->content = "Apple_PubSub";
	palabras->next->next->next->next = NULL;
	while (palabras != NULL)
	{
		printf("%s\n", (char *)palabras->content);
		palabras = palabras->next;
	}
	return (0);
}
