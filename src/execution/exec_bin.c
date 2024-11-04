/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:08:43 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/04 02:38:43 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	find_exec_path(char **command, t_list *env_lst);
static int	find_exec_pwd(char **command);

void	exec_piped_command(t_token *token, t_list *env_lst)
{
	char	*command;
	char	**matrix;
	char	**env_matrix;

	if (!token)
		return ;
	command = validate_exec(token->content, env_lst);
	if (!command)
		exit(127);
	signal(SIGQUIT, SIG_DFL);
	if (token->fd_out != STDOUT_FILENO)
		dup2(token->fd_out, STDOUT_FILENO);
	if (token->fd_in != STDIN_FILENO)
		dup2(token->fd_in, STDIN_FILENO);
	close_all_fd(token->head);
	matrix = convert_commands_to_array_matrix(token);
	env_matrix = convert_env_lst_to_array_matrix(token->env_lst);
	execve(command, matrix, env_matrix);
	return ;
}

int	exec_command(t_token *token, t_list *env_lst)
{
	char	*command;
	char	**matrix;
	char	**env_matrix;

	if (!token)
		return (0);
	command = validate_exec(token->content, env_lst);
	if (!command)
		return (-1);
	token->pid = fork();
	if (token->pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (token->fd_out != STDOUT_FILENO)
			dup2(token->fd_out, STDOUT_FILENO);
		if (token->fd_in != STDIN_FILENO)
			dup2(token->fd_in, STDIN_FILENO);
		close_all_fd(token->head);
		matrix = convert_commands_to_array_matrix(token);
		env_matrix = convert_env_lst_to_array_matrix(token->env_lst);
		execve(command, matrix, env_matrix);
		return (0);
	}
	free(command);
	return (0);
}

char	*validate_exec(char *command, t_list *env_lst)
{
	if (!command)
		return (NULL);
	if (command[0] == '/')
	{
		if (access(command, F_OK | X_OK) == 0)
			return (ft_strdup(command, 0));
		else
		{
			return (ft_putstr_fd("error: command not found\n", STDERR_FILENO),
				NULL);
		}
	}
	command = ft_strjoin("/", command, 0);
	if (find_exec_pwd(&command) == 0)
		return (command);
	else if (find_exec_path(&command, env_lst) == 0)
		return (command);
	free(command);
	return (NULL);
}

static int	find_exec_path(char **command, t_list *env_lst)
{
	extern unsigned int	g_exit_status;
	int					i;
	char				**path;
	char				*address;

	if (!find_env_in_lst(env_lst, "PATH"))
	{
		g_exit_status = 127;
		return (ft_putstr_fd("error: env PATH unseted\n", STDERR_FILENO), 1);
	}
	i = -1;
	path = ft_split(find_env_in_lst(env_lst, "PATH"), ':');
	while (path[++i])
	{
		address = ft_strjoin(path[i], *command, 0);
		if (access(address, F_OK | X_OK) == 0)
		{
			destroy_matrix(path);
			free(*command);
			return (*command = address, 0);
		}
		free(address);
	}
	ft_putstr_fd("error: command not found\n", STDERR_FILENO);
	return (destroy_matrix(path), g_exit_status = 127, 1);
}

static int	find_exec_pwd(char **command)
{
	extern unsigned int	g_exit_status;
	char				*pwd;

	pwd = ft_strjoin(getcwd(NULL, 0), *command, 1);
	if (access(pwd, F_OK) == 0)
	{
		if (access(pwd, F_OK | X_OK) == 0)
		{
			free(*command);
			*command = pwd;
			return (0);
		}
		else
		{
			ft_putstr_fd("error: command access dennied\n", STDERR_FILENO);
			g_exit_status = 126;
		}
	}
	free(pwd);
	return (1);
}
