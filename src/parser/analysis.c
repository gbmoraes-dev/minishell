/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:09 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 02:40:58 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	lexical_analysis(t_token **token_lst)
{
	t_token	*node;
	int		previous_type;

	if (!token_lst || !*token_lst)
		return (1);
	node = *token_lst;
	previous_type = 0;
	while (node)
	{
		if (node->content)
		{
			node->type = tokenize(node->content, previous_type);
			node->content = expander(node->content, node->env_lst);
			node->content = remove_quotes(node->content, 1);
			previous_type = node->type;
		}
		node = node->next;
	}
	remove_empty_token_nodes(token_lst);
	return (0);
}

int	syntax_analysis(t_token *token_lst)
{
	if (!token_lst)
		return (-1);
	else if (pipe_syntax_analysis(token_lst))
		return (-1);
	else if (redirect_syntax_analysis(token_lst))
		return (-1);
	return (0);
}

int	command_syntax_analysis(t_token *token_lst)
{
	while (token_lst)
	{
		if (count_commands(token_lst) == 0)
		{
			ft_putstr_fd("error: sentence without commands\n", STDERR_FILENO);
			return (1);
		}
		while (token_lst && token_lst->type != PIPE)
			token_lst = token_lst->next;
		if (token_lst)
			token_lst = token_lst->next;
	}
	return (0);
}

int	pipe_syntax_analysis(t_token *token_lst)
{
	t_token	*node;
	int		previous_type;

	if (!token_lst)
		return (-1);
	node = token_lst;
	previous_type = PIPE;
	while (node)
	{
		if ((previous_type == PIPE && node->type == PIPE) || (!node->next
				&& node->type == PIPE))
		{
			printf("error: incorrect use of pipes\n");
			return (-1);
		}
		previous_type = node->type;
		node = node->next;
	}
	return (0);
}

int	redirect_syntax_analysis(t_token *token_lst)
{
	t_token	*node;

	if (!token_lst)
		return (-1);
	node = token_lst;
	while (node)
	{
		if (is_redirect(node->type))
		{
			if (!node->next || node->next->type != REDIRECT_FILE)
			{
				printf("error: syntax error on '%s'\n", node->content);
				return (-1);
			}
		}
		node = node->next;
	}
	return (0);
}
