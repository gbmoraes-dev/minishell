/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:09:30 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 01:17:30 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_echo(t_token *token)
{
	int		should_print_new_line;
	t_token	*head;

	head = token;
	should_print_new_line = 1;
	if (token->next)
	{
		if (!ft_strncmp(token->next->content, "-n", 2))
		{
			should_print_new_line = 0;
			token = token->next;
		}
		token = token->next;
		while (token && token->type != PIPE)
		{
			ft_putstr_fd(token->content, head->fd_out);
			token = token->next;
			if (token && token->type != PIPE)
				ft_putchar_fd(' ', head->fd_out);
		}
	}
	if (should_print_new_line)
		ft_putchar_fd('\n', head->fd_out);
	return (0);
}
