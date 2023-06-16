/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:57:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/06/16 18:43:41 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
#define CMD_H

#include "libft.h"
#include "minishell.h"

void init_cmd(t_list *token, t_cmd *cmd);

int count_commands(t_list *token);
int count_elements(char **arr);
void free_cmd(t_cmd *cmd);

#endif
