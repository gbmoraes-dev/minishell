/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:09:23 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 02:40:01 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_valid_numeric_string(char *s);
static int	exit_error_hanlder(t_token **token);

void	my_exit(t_token **token, t_list **env_lst)
{
	unsigned char	status;

	status = exit_error_hanlder(token);
	ft_lstclear(env_lst, free);
	clear_token_lst(token, 0);
	rl_clear_history();
	exit(status);
	return ;
}

int	my_exit_pipe(t_token **token, t_list **env_lst)
{
	int	status;

	status = exit_error_hanlder(token);
	ft_lstclear(env_lst, free);
	clear_token_lst(token, 0);
	rl_clear_history();
	return (status);
}

static int	exit_error_hanlder(t_token **token_lst)
{
	t_token	*token;

	if (!token_lst || !*token_lst)
		return (0);
	token = *token_lst;
	if (validate_arguments(token))
	{
		ft_putstr_fd("error: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	else if (token->next && token->next->type == COMMAND)
	{
		if (is_valid_numeric_string(token->next->content) == 0)
			return (ft_atoi(token->next->content));
		else
		{
			ft_putstr_fd("error: invalid number\n", STDERR_FILENO);
			return (255);
		}
	}
	return (0);
}

static int	is_valid_numeric_string(char *s)
{
	if (!s || *s == '-')
		return (2);
	if (*s == '+')
		s++;
	if (!*s)
		return (1);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}
