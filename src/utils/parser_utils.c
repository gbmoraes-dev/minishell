/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:01 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 21:37:31 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_command_len(char *line)
{
	int	len;

	if (ft_ismeta(line))
		return (ft_ismeta(line));
	len = 0;
	while (*line && !ft_ismeta(line) && !ft_isspace(*line))
	{
		if (*line == '\'' || *line == '\"')
		{
			len += find_next_quote(line) + 1;
			line += find_next_quote(line) + 1;
		}
		else
		{
			len++;
			line++;
		}
	}
	return (len);
}

int	count_commands(t_token *node)
{
	int	commands;

	commands = 0;
	while (node && node->type != PIPE)
	{
		if (node->type == COMMAND)
			commands++;
		node = node->next;
	}
	return (commands);
}

int	is_redirect(int token_type)
{
	return (token_type == REDIRECT_OUT || token_type == REDIRECT_IN
		|| token_type == HEREDOC || token_type == APPEND);
}
