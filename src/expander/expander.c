/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:36 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:15:19 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*expander(char *line, t_list *env_lst)
{
	char	*expanded_line;

	expanded_line = ft_calloc(count_len_after_expansion(line, env_lst) + 1,
			sizeof(char));
	if (expanded_line)
		process_env_expansion(line, expanded_line, env_lst);
	free(line);
	return (expanded_line);
}

void	process_env_expansion(char *line, char *expanded_line, t_list *env_lst)
{
	t_position	position;
	char		should_expand;
	char		in_double_quotes;

	position = (t_position){0};
	should_expand = 1;
	in_double_quotes = 1;
	while (line[position.i])
	{
		if (line[position.i] == '\"' && should_expand)
			in_double_quotes ^= 1;
		if (line[position.i] == '\'' && in_double_quotes)
			should_expand ^= 1;
		if (line[position.i] == '$' && should_expand
			&& !validate_env_name(&line[position.i]))
			expand_specific_env(line, expanded_line, &position, env_lst);
		else
		{
			expanded_line[position.j] = line[position.i];
			position.i++;
			position.j++;
		}
	}
	return ;
}

void	expand_specific_env(char *line, char *expanded_line,
	t_position *position, t_list *env_lst)
{
	extern unsigned int	g_exit_status;
	char				*value;
	int					len;

	if (line[position->i + 1] == '?')
	{
		if (g_exit_status == 0)
			len = 1;
		else
			len = count_decimal(g_exit_status);
		value = ft_itoa(g_exit_status);
		ft_memcpy(&expanded_line[position->j], value, len);
	}
	else
	{
		value = ft_substr(&line[position->i], 1,
				count_env_name_len(&line[position->i]));
		len = ft_strlen(find_env_in_lst(env_lst, value));
		ft_memcpy(&expanded_line[position->j], find_env_in_lst(env_lst, value),
			len);
	}
	position->i += count_env_name_len(&line[position->i]) + 1;
	position->j += len;
	free(value);
	return ;
}
