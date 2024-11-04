/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:19 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:49:15 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*new_token_node(void *token)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = token;
	new->type = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->status = -1;
	new->pid = 0;
	new->next = NULL;
	return (new);
}

void	add_token_back(t_token **token_lst, t_token *new)
{
	t_token	*last_node;

	if (!new)
		return ;
	if (!*token_lst)
		*token_lst = new;
	else
	{
		last_node = *token_lst;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
	return ;
}
