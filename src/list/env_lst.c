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
