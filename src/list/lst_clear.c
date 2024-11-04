/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:25 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:53:42 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_empty_token_nodes(t_token **head)
{
	t_token	*node;

	if (!head || !(*head))
		return ;
	node = *head;
	if (!node->content || !node->content[0])
	{
		*head = node->next;
		if (node->content)
			free(node->content);
		free(node);
		token_lst_remove_if(head);
	}
	node = *head;
	if (!head || !*head)
		return ;
	remove_empty_token_nodes(&node->next);
	return ;
}

void	clear_token_lst(t_token **token_lst, int reset)
{
	t_token	*tmp;
	t_token	*node;

	if (!token_lst || !(*token_lst))
		return ;
	node = *token_lst;
	while (node)
	{
		tmp = node->next;
		free(node->content);
		free(node);
		node = tmp;
	}
	if (reset)
		*token_lst = NULL;
	return ;
}

void	token_lst_remove_if(t_token **head)
{
	t_token	*node;

	if (!head || !*head || (*head)->type == PIPE)
		return ;
	node = *head;
	if (node->type != COMMAND)
	{
		*head = node->next;
		free(node->content);
		free(node);
		token_lst_remove_if(head);
	}
	node = *head;
	if (!head || !*head || (*head)->type == PIPE)
		return ;
	token_lst_remove_if(&node->next);
	return ;
}
