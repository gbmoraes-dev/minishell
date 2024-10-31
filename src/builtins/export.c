#include "../../include/minishell.h"

static void	env_assignment_handler(t_token *token, char *arg);

int	my_export(t_token *token)
{
	char	**command_args;
	int		i;

	command_args = convert_commands_to_array_matrix(token);
	if (!command_args)
		return (-1);
	i = 1;
	while (command_args[i])
	{
		env_assignment_handler(token, command_args[i]);
		i++;
	}
	free(command_args[0]);
	free(command_args);
	return (0);
}

static void	env_assignment_handler(t_token *token, char *arg)
{
	char	**current;
	char	*key;

	if (arg[0] != '=' && ft_strchr(arg, '='))
	{
		key = ft_substr(arg, 0, ft_strchr(arg, '=') - arg);
		current = find_env_node(token->env_lst, key);
		if (current)
		{
			free(*current);
			*current = arg;
		}
		else
			ft_lstadd_back(&token->env_lst, ft_lstnew(arg));
		free(key);
	}
	else
		free(arg);
}
