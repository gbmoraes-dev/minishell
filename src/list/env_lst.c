/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:29 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/03 21:09:26 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*new_env_lst(void)
{
	extern char	**environ;
	t_list		*head;
	t_list		*node;
	int			i;

	i = 0;
	head = NULL;
	while (environ[i])
	{
		node = ft_lstnew(ft_strdup(environ[i], 0));
		if (!node)
		{
			ft_lstclear(&node, free);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

char	*find_env_in_lst(t_list *env_lst, char *env)
{
	char	*line;
	char	*key;

	line = NULL;
	while (env_lst)
	{
		line = env_lst->content;
		key = ft_substr(env_lst->content, 0, ft_strchr(line, '=') - line);
		if (!ft_strncmp(key, env, ft_strlen(key) + 1))
		{
			free(key);
			break ;
		}
		free(key);
		env_lst = env_lst->next;
	}
	if (!env_lst)
		return (NULL);
	if (line)
		line = ft_strchr(line, '=') + 1;
	return (line);
}

char	**find_env_node(t_list *env_lst, char *env)
{
	char	*key;
	char	*line;
	char	**env_address;

	env_address = NULL;
	if (!env_lst || !env)
		return (NULL);
	while (env_lst)
	{
		line = env_lst->content;
		key = ft_substr(env_lst->content, 0, ft_strchr(line, '=') - line);
		if (!ft_strncmp(key, env, ft_strlen(key) + 1))
		{
			env_address = (char **)&env_lst->content;
			free(key);
			break ;
		}
		free(key);
		env_lst = env_lst->next;
	}
	return (env_address);
}

void	remove_env_in_lst(t_list **env_lst, char *key)
{
	char	*current_key;
	t_list	*node;

	if (!env_lst || !*env_lst)
		return ;
	node = *env_lst;
	current_key = ft_substr(node->content, 0, ft_strchr(node->content, '=')
			- node->content);
	if (!ft_strncmp(key, current_key, ft_strlen(current_key) + 1))
	{
		*env_lst = node->next;
		free(node->content);
		free(node);
		free(current_key);
		return ;
	}
	else
		remove_env_in_lst(&node->next, key);
	free(current_key);
	return ;
}
