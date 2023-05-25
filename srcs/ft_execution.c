/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:54 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/25 11:24:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "libft.h"
#include "ft_clean.h"
#include <stdio.h>

int    ft_exec_recursion(t_data *data, t_node *node, t_node *parent);

void    ft_execution(t_data *data, t_node *node)
{
    if (ft_preprocessing(data->node) == -1)
    {
        ft_clean_tree(data->node);
        return ;
    }
    data->exit_code = ft_exec_recursion(data, data->node, NULL);
}

int ft_exec_cmd(t_data *data, t_node *node)
{
    (void)data;
    t_list  *token;
    int     exit;
    
    token = node->elems;
    while (token)
    {
        printf("%s ", (char *)token->content);
        token = token->next;
    }
    token = node->cmds->params;
    if (ft_strcmp((char *)token->content, "x") == 0)
        exit = 1;
    else
        exit = 0;
    while (token)
    {
        printf("%s ", (char *)token->content);
        token = token->next;
    }
    token = node->cmds->redir;
    while (token)
    {
        printf("%s ", (char *)token->content);
        token = token->next;
    }

    printf("\n");
    return (exit);
}

int ft_check_operator(int exit_code, char *str)
{
    if (ft_strcmp(str, "&&") == 0)
    {
        if (exit_code == 0)
            return (0);
        return (1);
    }
    if (exit_code == 0)
        return (1);
    return (0);
}

int    ft_exec_recursion(t_data *data, t_node *node, t_node *parent)
{
    if (node->type == 1)
    {
        if (!parent)
            node->exit_code = ft_exec_recursion(data, node->left, NULL);
        else
        {
            node->exit_code = 0;
            if (ft_check_operator(parent->exit_code, parent->elems->content) == 0)
                node->exit_code = ft_exec_recursion(data, node->left, NULL);
        }
        if (node->right->is_micro == node->is_micro && node->right->type == 1)
            node->exit_code = ft_exec_recursion(data, node->right, node);
        else
            if (ft_check_operator(node->exit_code, node->elems->content) == 0)
                node->exit_code = ft_exec_recursion(data, node->right, node);
    }
    else
        return (ft_exec_cmd(data, node));
    return (node->exit_code);
}
