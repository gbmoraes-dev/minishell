/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:08:26 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 02:14:56 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redirect_in(t_token *token)
{
	t_token	*head;

	head = token;
	while (head && head->type != COMMAND)
		head = head->next;
	while (head && token && token->type != PIPE)
	{
		if (token->type == REDIRECT_IN)
		{
			if (!access(token->next->content, F_OK | R_OK))
				head->fd_in = open(token->next->content, O_RDWR);
			else
			{
				printf("redirect in error: no such file as '%s'\n",
					token->next->content);
				return (-1);
			}
		}
		else if (token->type == HEREDOC)
			head->fd_in = heredoc(token);
		token = token->next;
	}
	return (0);
}

int	redirect_out(t_token *token)
{
	t_token	*head;

	head = token;
	while (head && head->type != COMMAND)
		head = head->next;
	while (head && token && token->type != PIPE)
	{
		if (token->type == REDIRECT_OUT || token->type == APPEND)
		{
			if (head->fd_out != STDOUT_FILENO)
				close(head->fd_out);
			if (token->type == REDIRECT_OUT)
				head->fd_out = open(token->next->content,
						O_WRONLY | O_CREAT | O_TRUNC, 0777);
			else
				head->fd_out = open(token->next->content,
						O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (head->fd_out == -1)
				return (-1);
		}
		token = token->next;
	}
	return (0);
}

int	heredoc(t_token *token)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		return (-1);
	line = NULL;
	while (42)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(token->next->content, line, ft_strlen(line)
				+ 1))
			break ;
		else if (line)
		{
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
	}
	if (line)
		free(line);
	close(fd[1]);
	return (fd[0]);
}

int	make_redirect(t_token *token)
{
	if (!token)
		return (0);
	if (redirect_in(token) || redirect_out(token))
		return (-1);
	return (0);
}
