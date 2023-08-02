/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:57:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/02 21:43:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

# include "libft.h"

typedef struct s_dtoken
{
	t_list	*current;
	t_list	*new_list;
	char	*str;
	char	*delimiters;
	char	*word;
	t_list	*delimiter_node;
	t_list *temp;
	char	*del_word;
	int		flag;
}			t_dtoken;

void		token_split(t_list **a);
int ctrl_built_ins(char *command);

#endif
