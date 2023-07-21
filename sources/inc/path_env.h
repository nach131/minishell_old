/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_env.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:53:41 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/07/21 11:23:49 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_ENV_H
# define PATH_ENV_H

# include "libft.h"

char	**path_env(t_list *env);
int		find_env(char *s1, char *s2);
char	*env_value(char *s);

#endif
