/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec_recursion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:14:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 17:15:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "struct_list.h"
#include "libft.h"
#include "structdata.h"
#include <string.h>

/*
    Source file:    srcs/line_execution.c

    Possible tests: 
                - (cat||ls)&&pwd
                - (cat||ls)&&pwd||(echo a|echo b)

    1 case is not working, if right child is the last, and it is whole

    tester:         make test_exec_recursion
*/

int max_level = 0;

t_list    *ft_tokenization(char *str);
void    print_tokens(t_list *token);
char    *ft_add_spaces(char *str);
void    ft_assign_types(t_list *node);
t_node  *ft_make_tree(t_list *token, t_node *parent);
void    ft_set_the_level(t_node *node, int level);
void    ft_print_tree(t_node *node);
void    ft_print_tree_levels(t_node *node, int level);
int    ft_exec_recursion(t_node *node, t_node *parent);

/*
    right_whole untested
*/

int main(void)
{
    char    *str;
    t_list  *head;
    t_node  *node;
    int     exit_code;

    head = NULL;
    node = NULL;
    str = readline("Type the string: ");
    while (str)
    {
        printf("-----------------------------\n");
        printf("\n");
        
        str = ft_add_spaces(str);

        head = ft_tokenization(str);
        ft_assign_types(head);

        node = ft_make_tree(head, NULL);

        ft_set_the_level(node, 0);
        
        ft_print_tree(node);
        printf("\n-----------------\n");

        int i = 0;
        while (i < max_level + 1)
        {
            ft_print_tree_levels(node, i);
            printf("\n");
            i++;
        }
        printf("\n\n");

        exit_code = ft_exec_recursion(node, NULL);

        printf("\n\n");
        str = readline("Type the string: ");
        
    }

    return (0);
}

void    ft_set_the_level(t_node *node, int level)
{
    if (max_level < level)
        max_level = level;
    if (!node->left)
    {
        node->level = level;
        return ;  
    }
    ft_set_the_level(node->left, level + 1);
    node->level = level;
    ft_set_the_level(node->right, level + 1);
}

void    ft_print_tree_levels(t_node *node, int level)
{
    t_list  *token;

    if (!node->left)
    {
        token = node->elems;
        while (token)
        {
            if (node->level == level)
                printf("%s", (char *)token->content);
            else
                printf("%s", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
            if (token->next)
                printf(" ");
            token = token->next;
        }
        return ;  
    }

    ft_print_tree_levels(node->left, level);


    token = node->elems;
    while (token)
    {
        if (node->level == level)
            printf(" %s ", (char *)token->content);
        else
            printf(" %s ", (char *)ft_memset(ft_strdup(token->content), ' ', strlen((char *)token->content)));
        token = token->next;
    }

    ft_print_tree_levels(node->right, level);
}

void    ft_print_tree(t_node *node)
{
    t_list  *token;

    if (!node->left)
    {
        token = node->elems;
        while (token)
        {
            printf("%s", (char *)token->content);
            if (token->next)
                printf(" ");
            token = token->next;
        }
        return ;  
    }
    
    printf("{ ");
    ft_print_tree(node->left);
    printf(" }");

    token = node->elems;
    while (token)
    {
        printf(" %s ", (char *)token->content);
        token = token->next;
    }

    printf("{ ");
    ft_print_tree(node->right);
    printf(" }");
}
