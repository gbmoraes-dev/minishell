/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:01 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/01 22:06:02 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_word_len(char *line)
{
	int	word_len;

	if (ft_ismeta(line))
		return (ft_ismeta(line));
	word_len = 0;
	while (*line && !ft_ismeta(line) && !ft_isspace(*line))
	{
		if (*line == '\'' || *line == '\"')
		{
			word_len += find_next_quote(line) + 1;
			line += find_next_quote(line) + 1;
		}
		else
		{
			word_len++;
			line++;
		}
	}
	return (word_len);
}

int	count_commands(t_token *node)
{
	int	cmd_count;

	cmd_count = 0;
	while (node && node->type != PIPE)
	{
		if (node->type == WORD)
			cmd_count++;
		node = node->next;
	}
	return (cmd_count);
}

int	is_redirect(int token_type)
{
	return (token_type == REDIRECT_OUT || token_type == REDIRECT_IN
		|| token_type == HEREDOC || token_type == APPEND);
}
