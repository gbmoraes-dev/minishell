/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:09:27 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:18:15 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_env(t_token *token)
{
	t_list	*env;

	if (token)
		env = token->env_lst;
	else
		env = NULL;
	while (env)
	{
		ft_putstr_fd(env->content, token->fd_out);
		ft_putchar_fd('\n', token->fd_out);
		env = env->next;
	}
	return (0);
}
