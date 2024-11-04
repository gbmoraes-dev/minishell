/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:05:49 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 03:01:39 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*prompt(int get_buffer)
{
	static char	*buffer;
	char		*shell_prompt;

	if (get_buffer)
		return (buffer);
	shell_prompt = malloc(2);
	shell_prompt[0] = '\0';
	shell_prompt = ft_strjoin(shell_prompt, GREEN, 1);
	shell_prompt = ft_strjoin(shell_prompt, getenv("USER"), 1);
	shell_prompt = ft_strjoin(shell_prompt, "@minishell $> ", 1);
	shell_prompt = ft_strjoin(shell_prompt, RESET, 1);
	buffer = readline(shell_prompt);
	if (buffer && *buffer)
		add_history(buffer);
	free(shell_prompt);
	return (buffer);
}
