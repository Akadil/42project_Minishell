/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:37:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 15:46:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADD_SPACES_H
# define FT_ADD_SPACES_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

char    *ft_is_metacharacter(char c1, char c2);
void    ft_put(char *string, int *j, int *i, char *meta);
void    ft_remove_extra_spaces(char* str);
int     ft_size(char *str);
char    *ft_free(char *str);

#endif