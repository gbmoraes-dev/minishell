#include "../../include/minishell.h"

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

static int	exit_error_hanlder(t_token **token)
{
	t_token	*current;

	if (!token || !*token)
		return (0);
	current = *token;
	if (validate_arguments(current))
	{
		ft_putstr_fd("Minishell: Exit: Too many args\n", STDERR_FILENO);
		return (1);
	}
	else if (current->next && current->next->type == WORD)
	{
		if (is_valid_numeric_string(current->next->content) == 0)
			return (ft_atoi(current->next->content));
		else
		{
			ft_putstr_fd("Minishell: Exit: Invalid number\n", STDERR_FILENO);
			return (255);
		}
	}
	return (0);
}
