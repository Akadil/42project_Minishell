/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_recursion.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:29:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 13:39:46 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_RECURSION_H
# define FT_EXEC_RECURSION_H

# include "struct_data.h"
# include "libft.h"
# include "ft_clean.h"
# include <stdio.h>

int    ft_exec_recursion(t_node *node, t_list **env, t_node *parent);
int		ft_check_operator(int exit_code, char *str);
int    ft_preprocess(t_node *node);
int    ft_exec_command(t_node *node, t_list **env);

#endif