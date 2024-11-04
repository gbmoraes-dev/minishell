/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:08:56 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:30:03 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_unset(t_token *token, t_list **env_lst)
{
	t_token	*aux;
	char	**commands;
	int		i;

	commands = convert_commands_to_array_matrix(token);
	if (!commands)
		return (-1);
	i = 1;
	while (commands[i])
	{
		remove_env_in_lst(env_lst, commands[i]);
		i++;
	}
	if (*env_lst != token->head->env_lst)
	{
		aux = token->head;
		while (aux)
		{
			aux->env_lst = *env_lst;
			aux = aux->next;
		}
	}
	destroy_matrix(commands);
	return (0);
}
