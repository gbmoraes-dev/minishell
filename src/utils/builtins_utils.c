/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:38 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 00:48:38 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	update_env(t_list *env_lst, char *key, char *new_value)
{
	while (env_lst)
	{
		if (ft_strncmp(key, env_lst->content, ft_strlen(key)) == 0)
		{
			free(env_lst->content);
			env_lst->content = ft_strjoin(key, new_value, 0);
			if (!env_lst->content)
				return (1);
		}
		env_lst = env_lst->next;
	}
	return (0);
}

int	validate_arguments(t_token *token)
{
	return (token && token->next && token->next->type == COMMAND
		&& token->next->next && token->next->next->type == COMMAND);
}
