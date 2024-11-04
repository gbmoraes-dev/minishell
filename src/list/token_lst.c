/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:16 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:59:31 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	init_token_heads(t_token *head);

t_token	*new_token_lst(char *line, t_list *env_lst)
{
	int		len;
	t_token	*token_lst;
	t_token	*token;

	if (!line)
		return (NULL);
	token_lst = NULL;
	while (ft_isspace(*line))
		line++;
	while (*line)
	{
		len = count_command_len(line);
		token = new_token_node(ft_substr(line, 0, len));
		token->env_lst = env_lst;
		add_token_back(&token_lst, token);
		line += len;
		while (ft_isspace(*line))
			line++;
	}
	init_token_heads(token_lst);
	return (token_lst);
}

static void	init_token_heads(t_token *head)
{
	t_token	*aux;

	if (!head)
		return ;
	aux = head;
	while (aux)
	{
		aux->head = head;
		aux = aux->next;
	}
	return ;
}
