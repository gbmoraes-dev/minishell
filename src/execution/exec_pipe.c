/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:08:37 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:39:23 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_pipe(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE)
			return (0);
		token = token->next;
	}
	return (1);
}

void	exec_pipe(t_token *token, t_list **env_lst)
{
	int	builtin;

	builtin = is_builtin(token);
	token->pid = fork();
	if (token->pid != 0)
		return ;
	if (!builtin)
		exec_piped_command(token, *env_lst);
	else
		exec_pipe_builtin(token, env_lst, builtin);
}

void	exec_pipe_builtin(t_token *token, t_list **env_lst, int builtin)
{
	if (builtin == MY_ECHO)
		exit(my_echo(token));
	else if (builtin == MY_CD)
		exit(my_cd(token));
	else if (builtin == MY_PWD)
		exit(my_pwd(token));
	else if (builtin == MY_EXPORT)
		exit(my_export(token));
	else if (builtin == MY_ENV)
		exit(my_env(token));
	else if (builtin == MY_UNSET)
		exit(my_unset(token, env_lst));
	else if (builtin == MY_EXIT)
		exit(my_exit_pipe(&token, &token->env_lst));
	return ;
}
