/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:08:34 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:48:23 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec(t_token **token, t_list **env_lst, int should_clean)
{
	int		has_pipe;
	t_token	*node;
	t_token	**address;

	node = *token;
	has_pipe = find_pipe(*token);
	my_pipe(node);
	while (node)
	{
		if (make_redirect(node) != 0)
			return (1);
		if (!should_clean)
			node = clean_redirections(token, 1);
		else
			node = clean_redirections(address, 0);
		if (has_pipe != 0)
			exec_whitout_pipe(node, env_lst);
		else
			exec_pipe(node, env_lst);
		close_sentece_fd(node);
		address = find_next_command_address(node);
		node = find_next_command(node);
		should_clean++;
	}
	return (0);
}

void	exec_whitout_pipe(t_token *token, t_list **env_lst)
{
	int	builtin;

	builtin = is_builtin(token);
	if (!builtin)
		exec_command(token, *env_lst);
	else
		exec_builtin(token, env_lst, builtin);
}

void	exec_builtin(t_token *token, t_list **env_lst, int builtin)
{
	if (builtin == MY_ECHO)
		token->status = my_echo(token);
	else if (builtin == MY_CD)
		token->status = my_cd(token);
	else if (builtin == MY_PWD)
		token->status = my_pwd(token);
	else if (builtin == MY_EXPORT)
		token->status = my_export(token);
	else if (builtin == MY_ENV)
		token->status = my_env(token);
	else if (builtin == MY_UNSET)
		token->status = my_unset(token, env_lst);
	else if (builtin == MY_EXIT)
		my_exit(&token->head, &token->env_lst);
	return ;
}

t_token	*clean_redirections(t_token **token_lst, int should_clean)
{
	t_token	*tmp;
	t_token	*node;

	tmp = *token_lst;
	token_lst_remove_if(token_lst);
	if (should_clean && *token_lst && *token_lst != tmp)
	{
		node = *token_lst;
		while (node)
		{
			node->head = *token_lst;
			node = node->next;
		}
	}
	return (*token_lst);
}
