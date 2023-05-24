/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:38:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 18:56:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLEAN_H
# define FT_CLEAN_H

# include "struct_data.h"
# include "struct_list.h"

void	ft_clean_fds(t_data *my_data);
void	ft_clean_data(t_data *my_data);
void	ft_clean_full(t_data *my_data);
void	ft_clean_tree(t_node *node);
void	ft_clean_cmds(t_cmd	**cmds_p);
void	ft_clean_tokens(t_list **token, void (*del)(void*));

#endif
