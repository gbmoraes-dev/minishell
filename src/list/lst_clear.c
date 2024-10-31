#include "../../include/minishell.h"

void	remove_empty_token_nodes(t_token **head)
{
	t_token	*current;

	if (!head || !(*head))
		return ;
	current = *head;
	if (!current->content || !current->content[0])
	{
		*head = current->next;
		if (current->content)
			free(current->content);
		free(current);
		token_lst_remove_if(head);
	}
	current = *head;
	if (!head || !(*head))
		return ;
	remove_empty_token_nodes(&current->next);
	return ;
}

void	clear_token_lst(t_token **lst, int reset)
{
	t_token	*current;
	t_token	*next;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	if (reset)
		*lst = NULL;
	return ;
}

void	token_lst_remove_if(t_token **head)
{
	t_token	*current;

	if (!head || !(*head) || (*head)->type == PIPE)
		return ;
	current = *head;
	if (current->type != WORD)
	{
		*head = current->next;
		free(current->content);
		free(current);
		token_lst_remove_if(head);
	}
	current = *head;
	if (!head || !(*head) || (*head)->type == PIPE)
		return ;
	token_lst_remove_if(&current->next);
	return ;
}
