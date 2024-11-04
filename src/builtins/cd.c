/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:09:36 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 02:39:47 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	cd_with_params(t_token *token);
static int	cd_without_params(t_token *token);

int	my_cd(t_token *token)
{
	int	status;

	if (token->next && token->next->next && token->next->next->type != COMMAND)
	{
		ft_putstr_fd("error: too many arguments\n", token->fd_out);
		return (1);
	}
	if (token->next && token->next->type == COMMAND)
		status = cd_with_params(token);
	else
		status = cd_without_params(token);
	return (status);
}

static int	cd_with_params(t_token *token)
{
	char	*pwd;

	if (validate_arguments(token))
	{
		ft_putstr_fd("error: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	pwd = getcwd(NULL, 0);
	if (chdir(token->next->content) == -1)
	{
		ft_putstr_fd("error: no such file or directory\n", STDERR_FILENO);
		free(pwd);
		return (1);
	}
	if (update_env(token->env_lst, "OLDPWD=", pwd) != 0)
	{
		free(pwd);
		return (1);
	}
	free(pwd);
	pwd = getcwd(NULL, 0);
	if (update_env(token->env_lst, "PWD=", pwd) != 0)
		return (1);
	free(pwd);
	return (0);
}

static int	cd_without_params(t_token *token)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (chdir(find_env_in_lst(token->env_lst, "HOME")) == -1)
	{
		ft_putstr_fd("error: no such file or directory\n", token->fd_out);
		free(pwd);
		return (1);
	}
	if (update_env(token->env_lst, "OLDPWD=", pwd) != 0)
		return (1);
	free(pwd);
	pwd = getcwd(NULL, 0);
	if (update_env(token->env_lst, "PWD=", pwd) != 0)
		return (1);
	free(pwd);
	return (0);
}
