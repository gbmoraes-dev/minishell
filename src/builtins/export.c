/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:09:19 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:25:28 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	env_assignment_handler(t_token *token, char *arg);

int	my_export(t_token *token)
{
	char	**commands;
	int		i;

	commands = convert_commands_to_array_matrix(token);
	if (!commands)
		return (-1);
	i = 1;
	while (commands[i])
	{
		env_assignment_handler(token, commands[i]);
		i++;
	}
	free(commands[0]);
	free(commands);
	return (0);
}

static void	env_assignment_handler(t_token *token, char *arg)
{
	char	**current;
	char	*key;

	if (arg[0] != '=' && ft_strchr(arg, '='))
	{
		key = ft_substr(arg, 0, ft_strchr(arg, '=') - arg);
		current = find_env_node(token->env_lst, key);
		if (current)
		{
			free(*current);
			*current = arg;
		}
		else
			ft_lstadd_back(&token->env_lst, ft_lstnew(arg));
		free(key);
	}
	else
		free(arg);
}
