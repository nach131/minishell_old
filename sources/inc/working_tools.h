/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:53:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/08 21:12:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKING_TOOLS_H
# define WORKING_TOOLS_H

# include "libft.h"

// int		find_env(char *s1, char *s2);
char	*env_value(char *s);
void	print_find_env(char *find, t_list *env);
int		parser_tmp(void);
void	history_line(void);
void	print_filefd(int **filefd);
void	print_builtin(int *builtin, int num);
void print_out(int **arr);

#endif
