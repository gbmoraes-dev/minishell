/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:08:34 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/01 22:08:34 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec(t_token **token, t_list **env_lst, int should_clean)
{
	int		has_pipe;
	t_token	*current;
	t_token	**address;

	current = *token;
	has_pipe = find_pipe(*token);
	my_pipe(current);
	while (current)
	{
		if (make_redirect(current) != 0)
			return (1);
		if (!should_clean)
			current = clean_redirections(token, 1);
		else
			current = clean_redirections(address, 0);
		if (has_pipe != 0)
			exec_whitout_pipe(current, env_lst);
		else
			exec_pipe(current, env_lst);
		close_fd(current);
		address = find_next_command_address(current);
		current = find_next_command(current);
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
		token->exit_status = my_echo(token);
	else if (builtin == MY_CD)
		token->exit_status = my_cd(token);
	else if (builtin == MY_PWD)
		token->exit_status = my_pwd(token);
	else if (builtin == MY_EXPORT)
		token->exit_status = my_export(token);
	else if (builtin == MY_ENV)
		token->exit_status = my_env(token);
	else if (builtin == MY_UNSET)
		token->exit_status = my_unset(token, env_lst);
	else if (builtin == MY_EXIT)
		my_exit(&token->head, &token->env_lst);
	return ;
}

t_token	*clean_redirections(t_token **token, int should_clean)
{
	t_token	*tmp;
	t_token	*current;

	tmp = *token;
	token_lst_remove_if(token);
	if (should_clean && *token && *token != tmp)
	{
		current = *token;
		while (current)
		{
			current->head = *token;
			current = current->next;
		}
	}
	return (*token);
}
