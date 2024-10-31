#include "../../include/minishell.h"

static void	init_token_heads(t_token *head);

t_token	*new_token_lst(char *line, t_list *env_lst)
{
	int		word_len;
	t_token	*new_node;
	t_token	*token_lst;

	if (!line)
		return (NULL);
	token_lst = NULL;
	while (ft_isspace(*line))
		line++;
	while (*line)
	{
		word_len = count_word_len(line);
		new_node = new_token_node(ft_substr(line, 0, word_len));
		new_node->env_lst = env_lst;
		add_token_back(&token_lst, new_node);
		line += word_len;
		while (ft_isspace(*line))
			line++;
	}
	init_token_heads(token_lst);
	return (token_lst);
}

static void	init_token_heads(t_token *head)
{
	t_token	*current;

	if (!head)
		return ;
	current = head;
	while (current)
	{
		current->head = head;
		current = current->next;
	}
	return ;
}
