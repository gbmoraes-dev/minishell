#include "../../include/minishell.h"

int	my_unset(t_token *token, t_list **env)
{
	t_token	*current;
	char	**command_args;
	int		i;

	command_args = convert_commands_to_array_matrix(token);
	if (!command_args)
		return (-1);
	i = 1;
	while (command_args[i])
	{
		remove_env_in_lst(env, command_args[i]);
		i++;
	}
	if (*env != token->head->env_lst)
	{
		current = token->head;
		while (current)
		{
			current->env_lst = *env;
			current = current->next;
		}
	}
	destroy_matrix(command_args);
	return (0);
}
