/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:12:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 15:47:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_add_spaces.h"

/**
 * @brief Add space between meta characters
 * 
 * Example:
 *          Before:  (cat||ls)|pwd
 *          After:   ( cat || ls ) | pwd
 * 
 * ft_size()				- Calculates the overall size of the string with 
 * 							  spaces
 * ft_is_metacharacter()    - checks if the character is meta
 * ft_put()                 - concantenates the meta characters with spaces
 * ft_remove_extra...()     - removes preeceding, succeeding, and duplicating
 *                       	  spaces  
 * 
 * The files located at utils/ft_add_spaces_utils.c
 * 
 * @param str   string to proceed
 * @return      string with spaces
 */
char    *ft_add_spaces(char *str)
{
    char    *string;
    char    *meta;
    int     i;
    int     j;

    string = (char *)malloc(sizeof(char) * (ft_size(str) + 1));
    if (!string)
        return (ft_free(str));
    i = 0;
    j = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]) == 1)
            string[j++] = ' ';
        else if ((meta = ft_is_metacharacter(str[i], str[i + 1])))
            ft_put(string, &j, &i, meta);
        else
            string[j++] = str[i];
        i++;
    }
    string[j] = '\0';
    ft_remove_extra_spaces(string);
    free(str);
    return (string);
}
