/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:15 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 00:53:08 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	validate_env_name(char *line)
{
	if (line && line[1] == '?')
		return (0);
	if (!line || *line != '$' || !ft_isalnum(line[1]))
		return (1);
	return (0);
}

int	count_env_name_len(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = 0;
	line++;
	if (*line == '?')
		return (1);
	while (line && *line && ft_isalpha(*line))
	{
		len++;
		line++;
	}
	return (len);
}

int	count_expanded_env_len(char *line, t_list *env_lst)
{
	extern unsigned int	g_exit_status;
	char				*env;
	int					len;

	if (line && line[1] == '?')
	{
		if (g_exit_status == 0)
			return (1);
		else
			return (count_decimal(g_exit_status));
	}
	env = ft_substr(line, 1, count_env_name_len(line));
	len = ft_strlen(find_env_in_lst(env_lst, env));
	if (env)
		free(env);
	return (len);
}

int	count_len_after_expansion(char *line, t_list *env_lst)
{
	int		len;
	char	should_expand;
	char	in_double_quotes;

	in_double_quotes = 0;
	should_expand = 1;
	len = 0;
	while (*line)
	{
		if (*line == '\"' && should_expand)
			in_double_quotes ^= 1;
		if (*line == '\'' && !in_double_quotes)
			should_expand ^= 1;
		if (*line == '$' && should_expand && !validate_env_name(line))
		{
			len += count_expanded_env_len(line, env_lst);
			line += count_env_name_len(line) + 1;
		}
		else
		{
			len++;
			line++;
		}
	}
	return (len);
}

int	count_decimal(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
