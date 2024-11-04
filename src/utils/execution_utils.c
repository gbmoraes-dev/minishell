/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:20 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:00:20 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(t_token *token)
{
	if (!token)
		return (0);
	if (ft_strncmp(token->content, "echo", 5) == 0)
		return (MY_ECHO);
	else if (ft_strncmp(token->content, "cd", 3) == 0)
		return (MY_CD);
	else if (ft_strncmp(token->content, "pwd", 4) == 0)
		return (MY_PWD);
	else if (ft_strncmp(token->content, "export", 7) == 0)
		return (MY_EXPORT);
	else if (ft_strncmp(token->content, "unset", 6) == 0)
		return (MY_UNSET);
	else if (ft_strncmp(token->content, "exit", 5) == 0)
		return (MY_EXIT);
	else if (ft_strncmp(token->content, "env", 4) == 0)
		return (MY_ENV);
	return (0);
}

void	wait_commands(t_token *token)
{
	extern unsigned int	g_exit_status;
	t_token				*tmp;

	if (!token)
		return ;
	tmp = token;
	while (token)
	{
		if (token->pid != 0)
			waitpid(token->pid, &token->status, 0);
		token = token->next;
	}
	token = tmp;
	while (token)
	{
		if (token->status >= 0)
			g_exit_status = WEXITSTATUS(token->status);
		token = token->next;
	}
	return ;
}

void	close_sentece_fd(t_token *token)
{
	while (token && token->type != PIPE)
	{
		if (token->fd_in != STDIN_FILENO)
			close(token->fd_in);
		if (token->fd_out != STDOUT_FILENO)
			close(token->fd_out);
		token = token->next;
	}
	return ;
}

t_token	*find_next_command(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE)
			return (token->next);
		token = token->next;
	}
	return (token);
}

t_token	**find_next_command_address(t_token *token)
{
	while (token && token->type != PIPE)
		token = token->next;
	if (token)
		return (&token->next);
	else
		return (NULL);
}
