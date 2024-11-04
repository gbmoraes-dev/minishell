/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:53 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 20:44:31 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	tokenize(char *command, int previous_token_type)
{
	if (!command)
		return (-1);
	if (ft_strncmp(command, "|", 2) == 0)
		return (PIPE);
	else if (ft_strncmp(command, "<<", 3) == 0)
		return (HEREDOC);
	else if (ft_strncmp(command, ">>", 3) == 0)
		return (APPEND);
	else if (ft_strncmp(command, "<", 2) == 0)
		return (REDIRECT_IN);
	else if (ft_strncmp(command, ">", 2) == 0)
		return (REDIRECT_OUT);
	else if (is_redirect(previous_token_type))
		return (REDIRECT_FILE);
	return (COMMAND);
}
