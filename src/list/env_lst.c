/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <gamoraes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:07:29 by gamoraes          #+#    #+#             */
/*   Updated: 2024/11/01 22:07:30 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*new_env_lst(void)
{
	extern char	**environ;
	t_list		*head;
	t_list		*node;
	int			i;

	head = NULL;
	i = 0;
	while (environ[i])
	{
		node = ft_lstnew(ft_strdup(environ[i]));
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

char	*find_env_in_lst(t_list *env_node, char *env)
{
	char	*key;
	char	*line;

	line = NULL;
	while (env_node)
	{
		line = env_node->content;
		key = ft_substr(env_node->content, 0, ft_strchr(line, '=') - line);
		if (!ft_strncmp(key, env, ft_strlen(key) + 1))
		{
			free(key);
			break ;
		}
		free(key);
		env_node = env_node->next;
	}
	if (!env_node)
		return (NULL);
	if (line)
		line = ft_strchr(line, '=') + 1;
	return (line);
}

char	**find_env_node(t_list *env_node, char *env)
{
	char	*key;
	char	*node_content;
	char	**match;

	match = NULL;
	if (!env_node || !env)
		return (NULL);
	while (env_node)
	{
		node_content = env_node->content;
		key = ft_substr(node_content, 0, ft_strchr(node_content, '=')
				- node_content);
		if (!ft_strncmp(key, env, ft_strlen(key) + 1))
		{
			match = (char **)&env_node->content;
			free(key);
			break ;
		}
		free(key);
		env_node = env_node->next;
	}
	return (match);
}

void	remove_env_in_lst(t_list **lst, char *key)
{
	char	*current_key;
	t_list	*current_node;

	if (!lst || !*lst)
		return ;
	current_node = *lst;
	current_key = ft_substr(current_node->content, 0,
			ft_strchr(current_node->content, '=') - current_node->content);
	if (!ft_strncmp(key, current_key, ft_strlen(current_key) + 1))
	{
		*lst = current_node->next;
		free(current_node->content);
		free(current_node);
		free(current_key);
		return ;
	}
	else
		remove_env_in_lst(&current_node->next, key);
	free(current_key);
	return ;
}
