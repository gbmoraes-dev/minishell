/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:19 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/01 22:07:19 by gamoraes         ###   ########.fr       */
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
	new->exit_status = -1;
	new->pid = 0;
	new->next = NULL;
	return (new);
}

t_token	*last_token_in_lst(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_token_back(t_token **lst, t_token *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		last_token_in_lst(*lst)->next = new;
}
