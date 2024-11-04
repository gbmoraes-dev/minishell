/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:09:36 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:13:15 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*aux;
	t_list	*node;

	if (!lst || !*lst)
		return ;
	node = *lst;
	while (node)
	{
		aux = node->next;
		if (del)
			del(node->content);
		free(node);
		node = aux;
	}
	*lst = NULL;
	return ;
}
