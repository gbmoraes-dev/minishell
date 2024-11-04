/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:08:30 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:45:48 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pipe(t_token *token)
{
	int		fd[2];
	t_token	*command;

	while (token)
	{
		while (token && token->type != PIPE && token->type != COMMAND)
			token = token->next;
		command = token;
		while (token && token->type != PIPE)
			token = token->next;
		if (!token)
			return (0);
		if (pipe(fd) == -1)
			return (1);
		command->fd_out = fd[1];
		token = token->next;
		command = token;
		while (command && command->type != PIPE && command->type != COMMAND)
			command = command->next;
		if (command)
			command->fd_in = fd[0];
		else
			close_pipe(fd);
	}
	return (0);
}

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	return ;
}

void	close_all_fd(t_token *token)
{
	while (token)
	{
		if (token->fd_in != STDIN_FILENO)
			close(token->fd_in);
		else if (token->fd_out != STDOUT_FILENO)
			close(token->fd_out);
		token = token->next;
	}
	return ;
}
