/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:32:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/27 17:36:37 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdio.h>

char    *ft_all_paths(t_list *env)
{
    char    *str;

    while (env)
    {
        str = (char *)env->content;
        if (ft_strncmp("PATH", str, 4) == 0 && str[4] == '=')
            break;
        env = env->next;
    }
    if (!env)
        return (NULL);
    return (str + 5);
}